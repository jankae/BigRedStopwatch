#pragma once

#include <cstdint>
#include <algorithm>
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
		std::copy_n(from, sizeof(T), (uint8_t*) &t);
		return t;
	}

	bool write(T t) {
		uint8_t *to = firstFree();
		if(!to) {
			/* No space available anymore */
			if(!erase())
				/* erase failed */
				return false;
			to = (uint8_t*) FlashAddress;
		}
		HAL_FLASH_Unlock();
		*to = sizeof(T);
		std::copy_n((uint8_t*) &t, sizeof(T), to+1);
		HAL_FLASH_Lock();
		return true;
	}
private:
	uint8_t *firstFree(void) {
		uint32_t address = FlashAddress;
		while (*(uint8_t*) address == sizeof(T)) {
			address += sizeof(T) + 1;
			if (address - FlashAddress - sizeof(T) - 1 >= FLASH_PAGE_SIZE)
				/* Run out of usable flash space, needs erase */
				return nullptr;
		}
		if (*(uint8_t*) address == 0xff) {
			/* found the end of the used sector */
			return (uint8_t*) address;
		} else {
			/* Unknown memory layout, needs erase */
			return nullptr;
		}
	}

	uint8_t* mostRecent(void) {
		uint32_t address = FlashAddress;
		while (*(uint8_t*) address == sizeof(T)) {
			address += sizeof(T) + 1;
			if (address - FlashAddress + sizeof(T) + 1 >= FLASH_PAGE_SIZE)
				/* The address advanced beyond usable space, use the last entry */
				return (uint8_t*) address - sizeof(T);
		}
		if (*(uint8_t*) address == 0xff) {
			/* found the end of the used sector */
			return (uint8_t*) address - sizeof(T);
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
