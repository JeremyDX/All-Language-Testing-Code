#pragma once

class Functions
{
	public:
		void(*funcptr)();

		static Functions* GetCurrentFunction();
		static void SetSize(int size);
		static void SetCurrentFunction(int index);
		static void Execute();

		static void CreateFunction(int index, int func_id);

	public:
		int value;
};