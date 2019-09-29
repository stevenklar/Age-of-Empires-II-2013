#include "Maphack.h"
#include "Renderer.h"

#include <Windows.h>

void Maphack::OnMenuMainWindow()
{
	if (ImGui::Button("Maphack"))
	{
		static tMaphack oMaphack = (tMaphack)((DWORD)GetModuleHandle(NULL) + 0x26C020);
		oMaphack();
	}
}
