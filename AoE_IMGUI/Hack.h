#pragma once
#include <Windows.h>
#include <iostream>

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

#include "Classes.h"

void createPlayerTreeNode(Player* player)
{
	if (ImGui::TreeNode((char*)player->pName))
	{
		ImGui::Text("Wood: %.f", player->Ressources->wood);
		ImGui::Text("Food: %.f", player->Ressources->food);
		ImGui::Text("Gold: %.f", player->Ressources->gold);
		ImGui::Text("Stone: %.f", player->Ressources->stone);
		ImGui::Text("Villigers: %.f", player->Ressources->villagerCount);
		ImGui::Text("Pop: %.f/%.f", player->Ressources->CurrentPop, player->Ressources->CurrentPop + player->Ressources->popSpaceLeft);

		if (ImGui::TreeNode("Units"))
		{
			int buildingCount = 0;
			int infantryCount = 0;
			int calavaryCount = 0;
			for (int i = 0; i < player->objectManager->iObjectCount; i++)
			{
				Unit* unit = player->objectManager->untis[i];
				if (!unit) { continue; }

				if (unit->pOwner == player)
				{
					if (unit->pUnitData->Class == EnumUnitDataClass::Building)
					{
						buildingCount++;
					}
					if (unit->pUnitData->Class == EnumUnitDataClass::Infantry)
					{
						infantryCount++;
					}
					if (unit->pUnitData->Class == EnumUnitDataClass::Cavalry)
					{
						calavaryCount++;
					}
				}
			}
			ImGui::Text("Buildings %.d", buildingCount);
			ImGui::Text("Infantry %.d", infantryCount);
			ImGui::Text("Cavalry %.d", calavaryCount);
			ImGui::TreePop();
		}
		ImGui::TreePop();
	}
}

bool openOverlay = true;
void RunHack()
{
	static Main* main = reinterpret_cast<Main*>((DWORD)GetModuleHandle(NULL) + 0x6FDA30);
	static int totalPlayers = *reinterpret_cast<int*>((DWORD)GetModuleHandle(NULL) + 0x9D9FFC);
	static GameData* gameData = main->GameData;
	static PlayerArray* playerArray = gameData->pPlayerArray;

	if (GetAsyncKeyState(VK_INSERT) & 1) { openOverlay = !openOverlay; }

	ImGui::SetNextWindowBgAlpha(0.35f);
	if (openOverlay)
	{
		if (ImGui::Begin("Age of Empires 2 HD", &openOverlay, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
		{
			for (int i = 1; i < totalPlayers; i++)
			{
				createPlayerTreeNode(playerArray->playerData[i].player);
			}
			if (ImGui::Button("Maphack"))
			{
				typedef int(__cdecl *tEnableCheats)();
				tEnableCheats oEnableCheats;
				oEnableCheats = (tEnableCheats)((DWORD)GetModuleHandle(NULL) + 0x26C020);
				oEnableCheats();
			}
			ImGui::SameLine();
			ImGui::Text("<-- Desync in multiplayer");
		}

		ImGui::End();
	}
}
