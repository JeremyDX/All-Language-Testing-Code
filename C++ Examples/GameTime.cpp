#include "GameTime.h"

unsigned __int32 clock_cycles_per_second = 0;

double seconds_per_frame = 0.0;
double seconds_per_cycle = 0.0;

unsigned __int64 clock_start_time = 0L;

unsigned __int64 current_time_stamp = 0L;
unsigned __int64 delta_time = 0L;

unsigned __int64 total_elapsed_time = 0L;
unsigned __int64 fps_elapsed_times = 0L;
unsigned __int64 total_elapsed_frames = 0L;

unsigned __int64 total_estimated_frames = 0L;
unsigned __int64 total_render_calls = 0L;


void GameTime::Begin()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&clock_cycles_per_second);

	unsigned __int64 clock_cycles_per_frame = clock_cycles_per_second / 60;
	seconds_per_frame = 1.0 / clock_cycles_per_frame;
	seconds_per_cycle = 1.0 / clock_cycles_per_second;

	QueryPerformanceCounter((LARGE_INTEGER*)&clock_start_time);
}

void GameTime::Tick()
{
	__int64 previous_time_stamp = current_time_stamp;
	QueryPerformanceCounter((LARGE_INTEGER*)&current_time_stamp);
	delta_time = current_time_stamp - previous_time_stamp;

	total_elapsed_time = current_time_stamp - clock_start_time;
	total_elapsed_frames = seconds_per_frame * total_elapsed_time;

	++total_render_calls;
}

__int64 GameTime::GetCurrentTimeCPUCycle()
{
	__int64 time_stamp;
	QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);
	return time_stamp;
}

__int64 GameTime::GetCurrentTimeMicrosecond()
{
	__int64 time_stamp;
	QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);
	return (__int64)(time_stamp * 1000000 * seconds_per_cycle);
}

__int64 GameTime::GetCurrentTimeMilliseconds()
{
	__int64 time_stamp;
	QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);
	return (__int64)(time_stamp * 1000 * seconds_per_cycle);
}

__int64 GameTime::GetCurrentTimeSeconds()
{
	__int64 time_stamp;
	QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);
	return (__int64)(time_stamp * seconds_per_cycle);
}

float GameTime::CPUCyclesToSeconds(float cycles)
{
	return (float)(cycles * seconds_per_cycle);
}

float GameTime::CPUCyclesToMilli(float cycles)
{
	return (float)(cycles * 1000 * seconds_per_cycle);
}

float GameTime::CPUCyclesToMicro(float cycles)
{
	return (float)(cycles * 1000000 * seconds_per_cycle);
}

float GameTime::CPUCyclesToNano(float cycles)
{
	return cycles * 1000000000 * seconds_per_cycle;
}

__int64 GameTime::TotalElapsedSeconds()
{
	return (__int64)(total_elapsed_time * seconds_per_cycle);
}

__int64 GameTime::TotalElapsedMilli()
{
	return (__int64)(total_elapsed_time * 1000 * seconds_per_cycle);
}

__int64 GameTime::TotalElapsedMicro()
{
	return (__int64)(total_elapsed_time * 1000000 * seconds_per_cycle);
}

__int64 GameTime::TotalElapsedCPUCycles()
{
	return total_elapsed_time;
}

__int64 GameTime::DeltaTime()
{
	return delta_time;
}

__int64 GameTime::TotalElapsedFrames()
{
	return total_elapsed_frames;
}

bool GameTime::Sleep()
{
	__int64 B = 0;
	while (B <= total_elapsed_frames)
	{
		__int64 time_stamp;
		QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);

		__int64 A = time_stamp - clock_start_time;
		B = seconds_per_frame * A;
	}
	return true;
}

__int64 GameTime::Sleep(int pause, int checksum)
{
	__int64 pause_stamp = 0L;
	__int64 time_stamp = 0L;
	QueryPerformanceCounter((LARGE_INTEGER*)&pause_stamp);
	__int64 B = 0;
	while (((time_stamp - pause_stamp) < pause) && B <= checksum)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&time_stamp);

		__int64 A = time_stamp - clock_start_time;
		B = A - total_elapsed_time;
	}
	return B;
}

void GameTime::DisplayOutputMilliseconds(unsigned __int64 timespan, unsigned loops)
{
	float avg_cc = (float)timespan / loops;
	int millitime = (int)CPUCyclesToMilli(timespan);
	int avg_nspl = (int)(avg_cc * 1000000000 * seconds_per_cycle);

	std::cout << "\nLoops: " << loops << ", Time Spent: " << millitime << "(Milli), Time Per Loop " << avg_nspl << "(Nano)\n";
}

void GameTime::DisplayOutputCPUCycles(unsigned __int64 timespan, unsigned loops)
{
	float avg_cc = (float)timespan / loops;
	int millitime = timespan;
	int avg_nspl = (int)(avg_cc * 1000000000 * seconds_per_cycle);

	std::cout << "\nLoops: " << loops << ", Time Spent: " << millitime << "(CPU Cycles), Time Per Loop " << avg_nspl << "(Nano)\n";

}