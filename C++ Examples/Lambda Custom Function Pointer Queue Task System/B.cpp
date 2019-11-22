#include <iostream>
#include "B.h"
#include "TaskQueue.h"

int B::count = 0;

void B::Test()
{
	void (*task)() = []()
	{
		std::cout << "\nB Count: " << ++count;
	};

	TaskQueue::InsertFunctionInQueue(task, 10, false);
}