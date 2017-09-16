#pragma once

#include <cstdint>
#include <cstring>
#include <algorithm>
#include <array>
#include "stm32f0xx_hal.h"

namespace System {

template<typename T>
class Flash {
public:
	constexpr Flash(uint32_t addr)
	: FlashAddress(addr)
	{};

	bool available(void) {
		return *(uint8_t*) FlashAddress == sizeof(T);
	}

	T read(void) {
		T t;
		uint8_t *from = mostRecent();
		if(!from) {
			/* No valid entry found */
			return t;
		}
		/* Skip identification byte */
		from++;
		std::copy_n(from, sizeof(T), (uint8_t*) &t);
		return t;
	}

	bool write(T t) {
		uint32_t to = firstFree();
		if(!to) {
			/* No space available anymore */
			if(!erase())
				/* erase failed */
				return false;
			to = FlashAddress;
		}
		HAL_FLASH_Unlock();
		union {
			uint8_t rawData[FlashSize];
			uint32_t writeArray[FlashSize/4];
		};
		memset(rawData, 0xff, FlashSize);
		rawData[0] = sizeof(T);
		memcpy(&rawData[1], &t, sizeof(T));

		for (uint8_t i = 0; i < FlashSize; i += 4) {
			HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, to + i,
					writeArray[i / 4]);
		}

		HAL_FLASH_Lock();
		return true;
	}
private:
	static const uint8_t FlashSize = ((sizeof(T) + 1) + 3) & ~0x03;

	uint32_t firstFree(void) {
		uint32_t address = FlashAddress;
		while (*(uint8_t*) address == sizeof(T)) {
			address += FlashSize;
			if (address - FlashAddress - FlashSize >= FLASH_PAGE_SIZE)
				/* Run out of usable flash space, needs erase */
				return 0;
		}
		if (*(uint8_t*) address == 0xff) {
			/* found the end of the used sector */
			return address;
		} else {
			/* Unknown memory layout, needs erase */
			return 0;
		}
	}

	uint8_t* mostRecent(void) {
		uint32_t address = FlashAddress;
		while (*(uint8_t*) address == sizeof(T)) {
			address += FlashSize;
			if (address - FlashAddress + FlashSize >= FLASH_PAGE_SIZE)
				/* The address advanced beyond usable space, use the last entry */
				return (uint8_t*) address - sizeof(T);
		}
		if (*(uint8_t*) address == 0xff) {
			/* found the end of the used sector */
			return (uint8_t*) address - FlashSize;
		} else {
			/* Unknown memory layout, needs erase */
			return nullptr;
		}
	}

	bool erase(void) {
		HAL_FLASH_Unlock();
		FLASH_EraseInitTypeDef erase;
		erase.NbPages = 1;
		erase.PageAddress = FlashAddress;
		erase.TypeErase = FLASH_TYPEERASE_PAGES;
		uint32_t result;
		HAL_FLASHEx_Erase(&erase, &result);
		HAL_FLASH_Lock();
		if (result == 0xFFFFFFFF) {
			/* Flash erase succeeded */
			return true;
		} else {
			/* some error occurred */
			return false;
		}
	}

	const uint32_t FlashAddress;
};

}
