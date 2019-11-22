#include "TaskQueue.h"
#include "Task.h"

static uint16_t BIT_FLIP = 0;
static uint8_t size = 0;
static uint32_t bit_execute_storage[16];

Task tasks[512];

void TaskQueue::Poll()
{
	int old = BIT_FLIP;
	const int length = size | old;

	BIT_FLIP ^= 0x100;
	size = 0x0;

	for ( ; old < length; ++old)
	{
		std::cout << "\nTicking... " << old << " , Ticks: " << (int)tasks[old].ticks;

		if (tasks[old].ticks == 0)
		{
			tasks[old].execute();

			
			int single_execute = bit_execute_storage[old >> 5] & (1 << (old & 0x1F));

			if (single_execute)
			{
				int index = (int)(size | BIT_FLIP);

				tasks[index].execute = tasks[old].execute;
				tasks[index].ticks = tasks[old].original_tick;
				tasks[index].original_tick = tasks[old].original_tick;
				bit_execute_storage[index >> 5] |= (1 << (index & 0x1F));
				++size;
			}
		}
		else 
		{
			int index = (int)(size | BIT_FLIP);

			tasks[index].execute = tasks[old].execute;
			tasks[index].ticks = tasks[old].ticks - 1;
			tasks[index].original_tick = tasks[old].original_tick;
			bit_execute_storage[index >> 5] |= (1 << (index & 0x1F));
			++size;
		}
	}
}

bool TaskQueue::InsertFunctionInQueue(void(*func_ptr)(), uint32_t ticks, bool single_execute)
{
	const int index = (int)(size | BIT_FLIP);

	bit_execute_storage[index >> 5] |= (1 << (index & 0x1F));
	if (!single_execute)
		bit_execute_storage[index >> 5] ^= (1 << (index & 0x1F));

	tasks[index].execute = func_ptr;
	tasks[index].ticks = tasks[index].original_tick = ticks;
	bit_execute_storage[index] = single_execute;

	++size;
	return true;
}
