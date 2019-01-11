#pragma once

#include <iostream>
#include <windows.h>;


class GameTime
{
public:

	static void Begin();
	static void Tick();

	static __int64 GetCurrentTimeCPUCycle();
	static __int64 GetCurrentTimeMicrosecond();
	static __int64 GetCurrentTimeMilliseconds();
	static __int64 GetCurrentTimeSeconds();

	static float CPUCyclesToSeconds(float cycles);
	static float CPUCyclesToMilli(float cycles);
	static float CPUCyclesToMicro(float cycles);
	static float CPUCyclesToNano(float cycles);

	static __int64 TotalElapsedSeconds();
	static __int64 TotalElapsedMilli();
	static __int64 TotalElapsedMicro();
	static __int64 TotalElapsedCPUCycles();

	static __int64 DeltaTime();

	static __int64 TotalElapsedFrames();

	static bool Sleep();
	static __int64 Sleep(int pause, int checksum);
	static void DisplayOutputCPUCycles(unsigned __int64 timespan, unsigned loops);
	static void DisplayOutputMilliseconds(unsigned __int64 timespan, unsigned loops);
};