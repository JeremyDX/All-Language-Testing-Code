#pragma once

#include <iostream>

struct Task
{
	void (*execute)();
	uint8_t ticks;
	uint8_t original_tick;
};