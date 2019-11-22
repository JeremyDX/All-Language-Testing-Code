#include <iostream>
#include "A.h"
#include "TaskQueue.h"

int A::count = 0;

void A::Test()
{
	void (*task)() = []()
	{
		std::cout << "\nA Count: " << ++count;
	};

	TaskQueue::InsertFunctionInQueue(task, 5, true);
}