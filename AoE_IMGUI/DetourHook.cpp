#include "DetourHook.h"

void* DetourHook::Hook(PBYTE src, const PBYTE dst, const int len)
{
	memcpy(originalBytes, src, len);
	hookLength = len;
	address = src;
	DWORD dwback;
	BYTE* jmp = (BYTE*)malloc(len + 5);
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = 0xE9;
	*(DWORD*)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = 0xE9;
	*(DWORD*)(src + 1) = (DWORD)(dst - src) - 5;
	VirtualProtect(src, len, dwback, &dwback);
	VirtualProtect(jmp - len, len + 5, PAGE_EXECUTE_READWRITE, &dwback);
	return (jmp - len);
}

void DetourHook::Unhook()
{
	DWORD dwback;
	VirtualProtect(address, hookLength, PAGE_READWRITE, &dwback);
	memcpy(address, originalBytes, hookLength);
	VirtualProtect(address, hookLength, dwback, &dwback);
}
