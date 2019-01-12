#include <iostream>
#include "Functions.h"

int main()
{
	Functions::SetSize(4);
	Functions::CreateFunction(0, 0);
	Functions::CreateFunction(1, 1);
	Functions::CreateFunction(2, 2);
	Functions::CreateFunction(3, 3);

	Functions::SetCurrentFunction(2);
	Functions::Execute();
	Functions::Execute();
	Functions::Execute();
	Functions::Execute();

	Functions::SetCurrentFunction(0);
	Functions::Execute();
	Functions::Execute();
	Functions::Execute();
	Functions::Execute();

	system("pause");
	return 0;
}