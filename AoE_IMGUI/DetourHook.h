#pragma once
#pragma once

#include <Windows.h>
#include <cstdint>
#include <iostream>

class DetourHook
{
	byte originalBytes[100]; //TODO fixed size 10?!
	int hookLength;
	PBYTE address;
public:
	void* Hook(PBYTE src, const PBYTE dst, const int len);
	void Unhook();
};
