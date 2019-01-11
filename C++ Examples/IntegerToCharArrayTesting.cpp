#include <iostream>
#include <windows.h>
#include "GameTime.h"

char* AddDynamicallyToBuffer(int64_t num)
{
	static char buffer[21];

	uint64_t value = num;

	int offset = -1;

	if (num < 0)
	{
		value = -num;
		buffer[++offset] = '-';
	}

	int len = 0;
	if (value >= 1000000000) //10 Digit.
	{
		if (value >= 100000000000000) //15 Digit.
		{
			if (value >= 10000000000000000) //17 Digits.
			{
				if (value >= 1000000000000000000)
				{
					//Length = 19
					uint64_t charValue = value / 1000000000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000000000);
					charValue = value / 100000000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000000000);
					charValue = value / 10000000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000000000);
					charValue = value / 1000000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000000);
					charValue = value / 100000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000000);
					charValue = value / 10000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000000);
					charValue = value / 1000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000);
					charValue = value / 100000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000);
					charValue = value / 10000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000);
					charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					if (value >= 100000000000000000)
					{
						//Length = 18
						uint64_t charValue = value / 100000000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000000000);
						charValue = value / 10000000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000000000);
						charValue = value / 1000000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000000000);
						charValue = value / 100000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000000);
						charValue = value / 10000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000000);
						charValue = value / 1000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000000);
						charValue = value / 100000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000);
						charValue = value / 10000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000);
						charValue = value / 1000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000);
						charValue = value / 100000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000);
						charValue = value / 10000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000);
						charValue = value / 1000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000);
						charValue = value / 100000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000);
						charValue = value / 10000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000);
						charValue = value / 1000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000);
						charValue = value / 100;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100);
						charValue = value / 10;
						buffer[++offset] = (char)((int)charValue | 0x30);
						buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
					}
					else
					{
						//Length = 17
						uint64_t charValue = value / 10000000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000000000);
						charValue = value / 1000000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000000000);
						charValue = value / 100000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000000);
						charValue = value / 10000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000000);
						charValue = value / 1000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000000);
						charValue = value / 100000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000);
						charValue = value / 10000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000);
						charValue = value / 1000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000);
						charValue = value / 100000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000);
						charValue = value / 10000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000);
						charValue = value / 1000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000);
						charValue = value / 100000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000);
						charValue = value / 10000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000);
						charValue = value / 1000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000);
						charValue = value / 100;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100);
						charValue = value / 10;
						buffer[++offset] = (char)((int)charValue | 0x30);
						buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
					}
				}
			}
			else
			{
				if (value >= 1000000000000000)
				{
					//Length = 16
					uint64_t charValue = value / 1000000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000000);
					charValue = value / 100000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000000);
					charValue = value / 10000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000000);
					charValue = value / 1000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000);
					charValue = value / 100000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000);
					charValue = value / 10000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000);
					charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					//Length = 15
					uint64_t charValue = value / 100000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000000);
					charValue = value / 10000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000000);
					charValue = value / 1000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000);
					charValue = value / 100000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000);
					charValue = value / 10000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000);
					charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
			}
		}
		else {
			if (value >= 100000000000) // 12 Digits.
			{
				if (value >= 10000000000000) //14 Digits.
				{
					//Length = 14
					uint64_t charValue = value / 10000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000000);
					charValue = value / 1000000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000000);
					charValue = value / 100000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000000);
					charValue = value / 10000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000);
					charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					if (value >= 1000000000000) //13 Digits.
					{
						//Length = 13
						uint64_t charValue = value / 1000000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000000);
						charValue = value / 100000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000);
						charValue = value / 10000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000);
						charValue = value / 1000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000);
						charValue = value / 100000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000);
						charValue = value / 10000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000);
						charValue = value / 1000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000);
						charValue = value / 100000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000);
						charValue = value / 10000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000);
						charValue = value / 1000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000);
						charValue = value / 100;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100);
						charValue = value / 10;
						buffer[++offset] = (char)((int)charValue | 0x30);
						buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
					}
					else
					{
						//Length = 12
						uint64_t charValue = value / 100000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000000);
						charValue = value / 10000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000000);
						charValue = value / 1000000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000000);
						charValue = value / 100000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000000);
						charValue = value / 10000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000000);
						charValue = value / 1000000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000000);
						charValue = value / 100000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100000);
						charValue = value / 10000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 10000);
						charValue = value / 1000;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 1000);
						charValue = value / 100;
						buffer[++offset] = (char)((int)charValue | 0x30);
						value -= (charValue * 100);
						charValue = value / 10;
						buffer[++offset] = (char)((int)charValue | 0x30);
						buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
					}
				}
			}
			else
			{
				if (value >= 10000000000)
				{
					//Length = 11
					uint64_t charValue = value / 10000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000000);
					charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					//Length = 10
					uint64_t charValue = value / 1000000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000000);
					charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
			}
		}
	}
	else {
		if (value >= 100000) //6 Digit.
		{
			if (value >= 10000000)
			{
				if (value >= 100000000)
				{
					//Length = 9
					uint64_t charValue = value / 100000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000000);
					charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					//Length = 8
					uint64_t charValue = value / 10000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000000);
					charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
			}
			else
			{
				if (value >= 1000000)
				{
					//Length = 7
					uint64_t charValue = value / 1000000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000000);
					charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					//Length = 6
					uint64_t charValue = value / 100000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100000);
					charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
			}
		}
		else {
			if (value >= 1000)
			{
				if (value >= 10000)
				{
					//Length = 5
					uint64_t charValue = value / 10000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 10000);
					charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					//Length = 4
					uint64_t charValue = value / 1000;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 1000);
					charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
			}
			else
			{
				if (value >= 100)
				{
					//Length = 3
					uint64_t charValue = value / 100;
					buffer[++offset] = (char)((int)charValue | 0x30);
					value -= (charValue * 100);
					charValue = value / 10;
					buffer[++offset] = (char)((int)charValue | 0x30);
					buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
				}
				else
				{
					if (value >= 10)
					{
						//Length = 2
						uint64_t charValue = value / 10;
						buffer[++offset] = (char)((int)charValue | 0x30);
						buffer[++offset] = (char)((value - (charValue * 10)) | 0x30);
					}
					else
					{
						//Length = 1
						buffer[++offset] = (char)(value | 0x30);
					}
				}
			}
		}
	}
	
	buffer[++offset] = '\000';

	return buffer;
}

char *Integer64ToCharArray(int64_t num)
{
	uint64_t value = num;
	int neg = num < 0;
	if (neg)
		value = -num;
	int len = 0;
	if (value >= 1000000000) //10 Digit.
	{
		if (value >= 100000000000000) //15 Digit.
		{
			if (value >= 10000000000000000) //17 Digits.
			{
				if (value >= 1000000000000000000)
					len = 19;
				else
				{
					if (value >= 100000000000000000)
						len = 18;
					else
						len = 17;
				}
			}
			else
			{
				if (value >= 1000000000000000)
					len = 16;
				else
				{
					len = 15;
				}
			}
		}
		else {
			if (value >= 100000000000) // 12 Digits.
			{
				if (value >= 10000000000000) //14 Digits.
					len = 14;
				else
				{
					if (value >= 1000000000000) //13 Digits.
						len = 13;
					else
						len = 12; //12 Digits.
				}
			}
			else
			{
				if (value >= 10000000000)
					len = 11; //11 Digits.
				else
				{
					len = 10; //10 Digits.
				}
			}
		}
	}
	else {
		if (value >= 100000) //6 Digit.
		{
			if (value >= 10000000)
			{
				if (value >= 100000000)
					len = 9;
				else
					len = 8;
			}
			else
			{
				if (value >= 1000000)
					len = 7;
				else
					len = 6;
			}
		}
		else {
			if (value >= 1000)
			{
				if (value >= 10000)
					len = 5;
				else
					len = 4;
			}
			else
			{
				if (value >= 100)
					len = 3;
				else
				{
					if (value >= 10)
						len = 2;
					else
						len = 1;
				}
			}
		}
	}

	static const uint64_t REDUCTION[20] =
	{
		1,
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000, //8
		100000000,
		1000000000,
		10000000000,
		100000000000,
		1000000000000,
		10000000000000,
		100000000000000,
		1000000000000000,
		10000000000000000, //17
		100000000000000000, //18
		1000000000000000000, //19
	};

	static char buffer[21];
	//switch to this if you want unique copies. remember to delete though.
	//char* buffer = new char[len + neg + 1];

	int offset = -1;

	if (neg)
		buffer[++offset] = '-';

	uint64_t reduction = REDUCTION[len];

	for ( ; --len >= 0 ; )
	{
		int c_value = (value / reduction);
		value -= reduction * c_value;
		buffer[++offset] = 48 + c_value;
		reduction = REDUCTION[len];
	}

	buffer[++offset] = 0;

	return buffer;
}


int main()
{
	int CYCLES = 100000000;

	int64_t value;
	scanf_s("%lld", &value);

	GameTime::Begin();

	int j = 0;
	for (int x = 0; x < CYCLES; ++x)
	{
		j += Integer64ToCharArray(value)[0];
	}

	GameTime::Tick();

	std::cout << "Value Used: " << value << '\n';
	std::cout << "Offset Size: " << j << '\n';
	std::cout << "String Data: " << Integer64ToCharArray(value) << '\n';

	std::cout << "Test: " << Integer64ToCharArray(LLONG_MAX) << '\n';
	std::cout << "Test: " << Integer64ToCharArray(LLONG_MIN) << '\n';

	GameTime::DisplayOutputMilliseconds(GameTime::TotalElapsedCPUCycles(), CYCLES);
	system("pause");
	return 0;
}
