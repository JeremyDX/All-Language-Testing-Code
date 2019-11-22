#pragma once

#include <iostream>

struct TaskQueue
{
	public:
		static void Poll();
		static bool InsertFunctionInQueue(void(*func_ptr)(), uint32_t ticks, bool execute_once);
};