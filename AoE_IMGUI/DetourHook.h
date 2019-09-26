#pragma once
#include <Windows.h>
#include <cstdint>

class DetourHook
{
	byte originalBytes[100];
	int hookLength;
	PBYTE address;
public:
	void* Hook(PBYTE src, const PBYTE dst, const int len);
	void Unhook();
};