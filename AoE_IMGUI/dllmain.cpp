#include <Windows.h>
#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

#include "DetourHook.h"
#include "Core.h"
#include "FeatureManager.h"


const char* windowName = "Age of Empires II: HD Edition"; 
Core* core = new Core();

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef HRESULT(__stdcall * f_EndScene)(IDirect3DDevice9 * pDevice);
f_EndScene oEndScene;

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

DetourHook endsceneHook = DetourHook();
DetourHook resetHook = DetourHook();



WNDPROC oWndProc;
HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9 * pDevice) // Our hooked endscene
{
	static bool init = true;
	if (init)
	{
		init = false;
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		
		ImGui_ImplWin32_Init(FindWindowA(NULL, windowName));
		ImGui_ImplDX9_Init(pDevice);
	}


	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGuiIO& io = ImGui::GetIO();

	
	core->OnEndscene();

	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
	
	return oEndScene(pDevice); // Call original ensdcene so the game can draw
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


VOID WINAPI OnDllAttach(PVOID base)
{
#ifdef _DEBUG
	AllocConsole();
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	SetConsoleTitleA("Age of Empires 2 HD - BDKPlayer");
#endif
}

VOID WINAPI OnDllDetach()
{
#ifdef _DEBUG
	fclose((FILE*)stdin);
	fclose((FILE*)stdout);

	HWND hw_ConsoleHwnd = GetConsoleWindow();
	FreeConsole();
	PostMessageW(hw_ConsoleHwnd, WM_CLOSE, 0, 0);
#endif
}


DWORD WINAPI MainThread(LPVOID param)
{
	OnDllAttach(param);
	HWND  window = FindWindowA(NULL, windowName);

	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);

	
	//Create a D3D9Device so we can hook its VFTABLE
	IDirect3D9 * pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (!pD3D)
		return false;

	D3DPRESENT_PARAMETERS d3dpp{ 0 };
	d3dpp.hDeviceWindow = window, d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD , d3dpp.Windowed = TRUE;
	
	IDirect3DDevice9 *Device = nullptr;
	if (FAILED(pD3D->CreateDevice(0, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &Device)))
	{
		pD3D->Release();
		return false;
	}
		

	void ** pVTable = *reinterpret_cast<void***>(Device); 

	if (Device)
		Device->Release() , Device = nullptr;
		
	oEndScene = (f_EndScene)endsceneHook.Hook((PBYTE)pVTable[42], (PBYTE)Hooked_EndScene, 7);

	while (!(GetAsyncKeyState(VK_DELETE) & 0x8000))
	{
		Sleep(1);
	}

	FeatureManager::Get()->OnShutdown();
	//Restore hooks and end thread
	(WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
	endsceneHook.Unhook();
	FreeLibraryAndExitThread((HMODULE)param, 0);
	return false; 
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, MainThread, hModule, 0, 0);
		break;
	case DLL_PROCESS_DETACH:
		Sleep(1000);
		OnDllDetach();
		break;
	}
	return TRUE;
}