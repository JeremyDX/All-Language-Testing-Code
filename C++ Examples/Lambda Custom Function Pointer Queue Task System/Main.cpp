#pragma warning(disable:6011)

#include <iostream>
#include "A.h"
#include "B.h"
#include "TaskQueue.h"

int main()
{
	A::Test();
	B::Test();

	//Test 20 Loops Of Queue.
	for (int j = 0; j < 50; ++j)
	{
		TaskQueue::Poll();
	}
}