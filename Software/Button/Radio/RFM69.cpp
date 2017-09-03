/*
 * RFM69.cpp
 *
 *  Created on: Aug 19, 2017
 *      Author: jan
 */

#include "RFM69.h"

bool RFM69::init() {
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_SET);

	uint8_t version = readRegister(RG_VERSION);
	if (version != 0x24)
		return false;

	/* Radio configuration */
	/* 0x01 */
	writeSubregister(SR_SEQUENCER, SEQUENCER_BY_REG_OP_MODE);
	writeSubregister(SR_LISTEN, LISTEN_OFF);
	writeSubregister(SR_MODE, MODE_STDBY);
	/* 0x02 */
	writeSubregister(SR_DATA_MODE, DATA_MODE_PACKET);
	writeSubregister(SR_MODULATION_TYPE, MODULATION_TYPE_FSK);
	writeSubregister(SR_MODULATION_SHAPING, SHAPING_FSK_OFF);
	/* 0x03 */
	writeRegister(RG_BITRATE_MSB, RF_BITRATE_MSB_25000);
	/* 0x04 */
	writeRegister(RG_BITRATE_LSB, RF_BITRATE_LSB_25000);
	/* 0x05 */
	writeRegister(RG_FDEV_MSB, RF_FDEV_MSB_50000);
	/* 0x06 */
	writeRegister(RG_FDEV_LSB, RF_FDEV_LSB_50000);
	/* 0x07 */
	writeRegister(RG_FRF_MSB, RF_FRF_MSB_868);
	/* 0x08 */
	writeRegister(RG_FRF_MID, RF_FRF_MID_868);
	/* 0x09 */
	writeRegister(RG_FRF_LSB, RF_FRF_LSB_868);
	/* 0x19 */
	writeSubregister(SR_DCC_FREQ, DCC_FREQ_010);
	writeSubregister(SR_RX_BW_MANT, RX_BW_MANT_16);
	writeSubregister(SR_RX_BW_EXP, RX_BW_EXP_2);
	/* 0x25 */
	writeSubregister(SR_DIO0_MAPPING, DIO0_MAPPING_01);
	/* 0x26 */
	writeSubregister(SR_CLK_OUT, CLK_OUT_OFF);
	/* 0x28 */
	writeSubregister(SR_FIFO_OVERRUN, 1);
	/* 0x29 */
	writeRegister(RG_RSSI_THRESH, 220);
	/* 0x2E */
	writeSubregister(SR_SYNC, SYNC_ON);
	writeSubregister(SR_FIFO_FILL_CONDITION, FIFO_FILL_CONDITION_AUTO);
	writeSubregister(SR_SYNC_SIZE, SYNC_SIZE_2);
	writeSubregister(SR_SYNC_TOL, 0);
	/* 0x2F */
	writeRegister(RG_SYNC_VALUE1, 0xAA);
	/* 0x30 */
	writeRegister(RG_SYNC_VALUE2, 0x55);
	/* 0x37 */
	writeSubregister(SR_PACKET_FORMAT, PACKET_FORMAT_VARIABLE);
	writeSubregister(SR_DC_FREE, DC_FREE_NONE);
	writeSubregister(SR_CRC, CRC_ON);
	writeSubregister(SR_CRC_AUTO_CLEAR, CRC_AUTO_CLEAR_ON);
	writeSubregister(SR_ADDRESS_FILTERING, ADDRESS_FILTERING_OFF);
	/* 0x38 */
	writeRegister(RG_PACKET_PAYLOAD_LENGTH, 66);
	/* 0x39 */
	/* 0x3C */
	writeSubregister(SR_TX_START_CONDITION, TX_START_CONDITION2);
	writeSubregister(SR_FIFO_THRESHOLD, 0x0F);
	/* 0x3D */
	writeSubregister(SR_INTER_PACKET_RX_DELAY, 1);
	writeSubregister(SR_AUTO_RX_RESTART, AUTO_RX_RESTART_ON);
	writeSubregister(SR_AES, AES_OFF);
	/* 0x6F */
	writeRegister(RG_TEST_DAGC, TEST_DAGC_LOWBETA1);

	applyPower(transmitPower);

	return true;
}

uint32_t RFM69::getFrequency() {
	return (((uint64_t) (((uint32_t) readRegister(RG_FRF_MSB) << 16)
			+ ((uint16_t) readRegister(RG_FRF_MID) << 8)
			+ readRegister(RG_FRF_LSB))) * 15625) >> 8;
}

void RFM69::setFrequency(uint32_t freq) {
	oldMode = getMode();
	if (oldMode == Mode::Transmit) {
		setMode(Mode::Receive);
	}
	uint32_t freqval = ((uint64_t) (freq) << 8) / 15625;
	writeRegister(RG_FRF_MSB, freqval >> 16);
	writeRegister(RG_FRF_MID, freqval >> 8);
	writeRegister(RG_FRF_LSB, freqval);
	if (oldMode == Mode::Receive) {
		setMode(Mode::Synthesizer);
	}
	restoreMode();
}


void RFM69::applyPower(int8_t dbm) {
	if(isHWversion)
	{
		/* can only use PA1 and PA2, power from -2 to 20 dbm */
		if(dbm < -2)
			dbm = -2;
		if(dbm > 20)
			dbm = 20;
		if(dbm <= 13) {
			/* use just PA1 */
			dbm += 18;
			writeRegister(RG_PA_LEVEL, 0x40 | dbm);
//			writeSubregister(SR_PA0, PA0_OFF);
//			writeSubregister(SR_PA1, PA1_ON);
//			writeSubregister(SR_PA2, PA2_OFF);
//			writeSubregister(SR_OUTPUT_POWER, dbm + 18);
			writeRegister(RG_TEST_PA1, TEST_PA1_NORMAL);
			writeRegister(RG_TEST_PA2, TEST_PA2_NORMAL);
			writeSubregister(SR_OCP, OCP_ON);
		} else if(dbm  <= 17) {
			/* use PA1 and PA2 */
			dbm += 14;
			writeRegister(RG_PA_LEVEL, 0x60 | dbm);
//			writeSubregister(SR_PA0, PA0_OFF);
//			writeSubregister(SR_PA1, PA1_ON);
//			writeSubregister(SR_PA2, PA2_ON);
//			writeSubregister(SR_OUTPUT_POWER, dbm + 14);
			writeRegister(RG_TEST_PA1, TEST_PA1_NORMAL);
			writeRegister(RG_TEST_PA2, TEST_PA2_NORMAL);
			writeSubregister(SR_OCP, OCP_ON);
		} else {
			/* use PA1 and PA2 on high power settings */
			dbm += 11;
			writeRegister(RG_PA_LEVEL, 0x60 | dbm);
//			writeSubregister(SR_PA0, PA0_OFF);
//			writeSubregister(SR_PA1, PA1_ON);
//			writeSubregister(SR_PA2, PA2_ON);
//			writeSubregister(SR_OUTPUT_POWER, dbm + 11);
			writeRegister(RG_TEST_PA1, TEST_PA1_20DBM);
			writeRegister(RG_TEST_PA2, TEST_PA2_20DBM);
			writeSubregister(SR_OCP, OCP_OFF);
		}
	} else {
		/* can only use PA0 */
		if(dbm < -18)
			dbm = -18;
		if(dbm > 13)
			dbm = 13;
		dbm += 18;
		writeRegister(RG_PA_LEVEL, 0x40 | dbm);
//		writeSubregister(SR_PA0, PA0_ON);
//		writeSubregister(SR_PA1, PA1_OFF);
//		writeSubregister(SR_PA2, PA2_OFF);
//		writeSubregister(SR_OUTPUT_POWER, dbm + 18);
		writeRegister(RG_TEST_PA1, TEST_PA1_NORMAL);
		writeRegister(RG_TEST_PA2, TEST_PA2_NORMAL);
		writeSubregister(SR_OCP, OCP_ON);
	}
}

void RFM69::setMode(Mode m) {
	if (mode != m) {
		/* requested a new mode, change register */
		writeSubregister(SR_MODE, (uint8_t) m);
		/* if leaving sleepmode, wait for FIFO to be available */
		if (mode == Mode::Sleep)
			while (readSubregister(SR_MODE_READY) == 0)
				;
		while (readSubregister(SR_MODE) != (uint8_t) m)
			;
		mode = m;
	}
}

RFM69::Mode RFM69::getMode() {
	return (Mode) readSubregister(SR_MODE);
}

bool RFM69::send(const uint8_t* data, uint8_t len) {
	if(mode==Mode::Transmit) {
		return false;
	}
	if (len > RFM69_MAX_FRAME)
		len = RFM69_MAX_FRAME;
	oldMode = mode;
	setMode(Mode::Standby);
	while (readSubregister(SR_MODE_READY) == 0)
					;
	writeSubregister(SR_DIO0_MAPPING, DIO0_MAPPING_00);

	applyPower(transmitPower);

	/* Write the transmit frame */
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_RESET);

	uint8_t length[2] = { RG_FIFO, len };
	length[0] |= 0x80;
#ifdef RFM69_GETTIME
	/* Add space for timestamp */
	length[1] += 4;
#endif
	HAL_SPI_Transmit(spi, length, 2, 100);
	HAL_SPI_Transmit(spi, data, len, 100);
#ifdef RFM69_GETTIME
	/* Add space for timestamp */
	uint32_t timestamp = RFM69_GETTIME();
	HAL_SPI_Transmit(spi, (uint8_t*) &timestamp, 4, 100);
#endif
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_SET);
	setMode(Mode::Transmit);
	return true;
}

int8_t RFM69::getRSSI() {
	return -(readRegister(RG_RSSI_VALUE) >> 1);
}

uint32_t RFM69::getRandom() {
	Mode old = mode;
	setMode(Mode::Standby);
	uint32_t rnd = 0;
	uint8_t i;
	for (i = 0; i < 32; i++) {
		rnd <<= 1;
		writeSubregister(SR_RSSI_START, 1);
		while(!readSubregister(SR_RSSI_DONE));
		rnd |= readRegister(RG_RSSI_VALUE) & 0x01;
	}
	setMode(old);
	return rnd;
}

uint8_t RFM69::readRegister(uint8_t address) {
	uint8_t send[2] = { address, 0 };
	send[0] &= 0x7F;
	uint8_t rec[2];
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(spi, send, rec, 2, 100);
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_SET);
	return rec[1];
}

void RFM69::writeRegister(uint8_t address, uint8_t value) {
	uint8_t data[2] = { address, value };
	data[0] |= 0x80;
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(spi, data, 2, 100);
	HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_SET);
}

uint8_t RFM69::readSubregister(uint8_t address, uint8_t mask,
		uint8_t position) {
	uint8_t val = readRegister(address) & mask;
	return val >> position;
}

RFM69::Packet RFM69::getPacket(void) {
	receivedPacket = false;
	return packet;
}

void RFM69::writeSubregister(uint8_t address, uint8_t mask, uint8_t position,
		uint8_t value) {
	/* Read register and mask out the bits we will be modifying */
	uint8_t val = readRegister(address) & ~mask;
	/* Add the new subregister value */
	val |= (value << position) & mask;
	/* and write the modified register */
	writeRegister(address, val);
}

void RFM69::onDIO0(void) {
	switch(mode) {
	case Mode::Transmit:
		/* sending packet finished */
		restoreMode();
		writeSubregister(SR_DIO0_MAPPING, DIO0_MAPPING_01);
		break;
	case Mode::Receive:
		/* Read frame into buffer */
#ifdef RFM69_GETTIME
		packet.receivedTimestamp = RFM69_GETTIME();
#endif
		packet.rssi = getRSSI();
		packet.lna = readRegister(RG_LNA);

		HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_RESET);
		uint8_t cmd[2] = {RG_FIFO, 0};
		uint8_t len[2];
		HAL_SPI_TransmitReceive(spi, cmd, len, 2, 100);
#ifdef RFM69_GETTIME
		len[1] -= 4;
#endif
		packet.length = len[1];
		HAL_SPI_Receive(spi, packet.data, len[1], 100);
#ifdef RFM69_GETTIME
		HAL_SPI_Receive(spi, (uint8_t*) &packet.sentTimestamp, 4, 100);;
#endif
		HAL_GPIO_WritePin(nss_gpio, nss_pin, GPIO_PIN_SET);
		receivedPacket = true;
		break;
	}
}

