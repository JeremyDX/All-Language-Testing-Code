#include <iostream>
#include <string>
#include <string_view>
#include <Windows.h>

/*
[FunctionPass][CONST CHAR*]: Time Taken : (Nano)23263080, (Micro) : 23263, (Mili's): 23
[FunctionPass][STRING_VIEW]: Time Taken : (Nano)31719222, (Micro) : 31719, (Mili's): 31

[Substring_10][CONST CHAR*]: Time Taken : (Nano)2211573, (Micro) : 2211, (Mili's): 2
[Substring_10][STRING_VIEW]: Time Taken : (Nano)91917562, (Micro) : 91917, (Mili's): 91

[Substring_1][CONST CHAR*]: Time Taken : (Nano)2208619, (Micro) : 2208, (Mili's): 2
[Substring_1][STRING_VIEW]: Time Taken : (Nano)91080970, (Micro) : 91080, (Mili's): 91

[Length][CONST CHAR*]: Time Taken : (Nano)15178250, (Micro) : 15178, (Mili's): 15
[Length][STRING_VIEW]: Time Taken : (Nano)20555210, (Micro) : 20555, (Mili's): 20
*/

#define END_STAMP QueryPerformanceCounter((LARGE_INTEGER*)&end_time); nano_time = end_time - start_time; std::cout << "Time Taken: (Nano)" << nano_time << ", (Micro): " << (int)(nano_time * 0.001) << ", (Mili's): " << (int)(nano_time * 0.001 * 0.001)
#define START_STAMP QueryPerformanceCounter((LARGE_INTEGER*)&start_time)

const char* c = "Hello World";
const char* c_temp = c;

std::string_view sv = "Hello World";

long long clock_cycles = 0;
long long start_time = 0;
long long end_time = 0;
long long nano_time = 0;

void Func(std::string_view s)
{

}

void Func(const char* c)
{

}

void TestFunctionPass()
{
	std::cout << "\n[FunctionPass][CONST CHAR*]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		Func(c);
	}
	END_STAMP;

	std::cout << "\n[FunctionPass][STRING_VIEW]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		Func(sv);
	}
	END_STAMP;
}

void TestSubString()
{
	std::cout << "\n[Substring_10][CONST CHAR*]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		c_temp = c + 10;
	}
	END_STAMP;

	std::cout << "\n[Substring_1][CONST CHAR*]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		c_temp = c + 1;
	}
	END_STAMP;

	std::cout << "\n[Substring10][STRING_VIEW]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		sv.substr(10);
	}
	END_STAMP;

	std::cout << "\n[Substring1][STRING_VIEW]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		sv.substr(1);
	}
	END_STAMP;
}

void TestLength()
{
	std::cout << "\n[Length][CONST CHAR*]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		int n = 0;
		while (c[n]) ++n;
	}
	END_STAMP;

	std::cout << "\n[Length][STRING_VIEW]: ";
	START_STAMP;
	for (int i = 0; i < 100000000; ++i)
	{
		sv.size();
	}
	END_STAMP;
}

int main()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&clock_cycles);

	TestFunctionPass();
	TestSubString();
	TestLength();

	std::cout << '\n';
	return 0;
}
