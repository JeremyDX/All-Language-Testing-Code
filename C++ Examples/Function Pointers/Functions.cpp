#include "Functions.h"
#include <iostream>

static int index = 0;
static Functions *functions;

void Functions::SetSize(int size)
{
	functions = new Functions[size];
}

Functions* Functions::GetCurrentFunction()
{
	return &functions[index];
}

void Functions::SetCurrentFunction(int index)
{
	::index = index;
}

void Functions::Execute()
{
	functions[index].funcptr();
}

void Test1()
{
	Functions *ref = Functions::GetCurrentFunction();
	ref->value += 1;
	std::cout << "Hello From Test One.\nMy Value: " << Functions::GetCurrentFunction()->value << '\n';
}

void Test2()
{
	Functions *ref = Functions::GetCurrentFunction();
	ref->value += 2;
	std::cout << "This is your commander Test Two.\nMy Value: " << Functions::GetCurrentFunction()->value << '\n';
}

void Test3()
{
	Functions *ref = Functions::GetCurrentFunction();
	ref->value += 3;
	std::cout << "Welcome to Test Three.\nMy Value: " << Functions::GetCurrentFunction()->value << '\n';
}

void Test4()
{
	Functions *ref = Functions::GetCurrentFunction();
	ref->value += 4;
	std::cout << "Forth Test You Are Looking Yes?\nMy Value: " << Functions::GetCurrentFunction()->value << '\n';
}

void DoNothing()
{
	std::cout << "UNUSED SLOT\n";
}

void Functions::CreateFunction(int index, int func_id)
{
	if (func_id == 0)
		functions[index].funcptr = Test1;
	else if (func_id == 1)
		functions[index].funcptr = Test2;
	else if (func_id == 2)
		functions[index].funcptr = Test3;
	else if (func_id == 3)
		functions[index].funcptr = Test4;
	else
		functions[index].funcptr = DoNothing;
	functions[index].value = 0;
}
