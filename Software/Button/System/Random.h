#pragma once

namespace System {

class Random {
public:
	constexpr Random()
	: state(0)
	{};

	void seed(uint32_t seed) {
		state = seed;
	}
	uint32_t next(void) {
		/* Linear congruential generator */
		state = (22695477 * state + 1);
		return state;
	}
private:
	uint32_t state;
};

}
