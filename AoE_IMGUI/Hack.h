#pragma once
#include <Windows.h>
#include <iostream>
#include <sstream>

#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx9.h"
#include "../ImGui/imgui_impl_win32.h"

#include "../ImGui/imgui_internal.h"

#include "Classes.h"



//
//float RenderText(const std::string& text, const ImVec2& position, float size, uint32_t color, bool center)
//{
//	static ImFont* m_pFont;
//	static void* g_fFont;
//
//	if (!m_pFont)
//	{
//		ImGuiIO& io = ImGui::GetIO();
//
//		io.Fonts->AddFontFromMemoryTTF(g_fFont, sizeof(g_fFont), 14.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
//		m_pFont = io.Fonts->AddFontFromMemoryTTF(g_fFont, sizeof(g_fFont), 32.0f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
//	}
//	ImGuiWindow* window = ImGui::GetCurrentWindow();
//
//	float a = (color >> 24) & 0xff;
//	float r = (color >> 16) & 0xff;
//	float g = (color >> 8) & 0xff;
//	float b = (color) & 0xff;
//
//	std::stringstream stream(text);
//	std::string line;
//
//	float y = 0.0f;
//	int i = 0;
//
//	while (std::getline(stream, line))
//	{
//		ImVec2 textSize = m_pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());
//
//		if (center)
//		{
//			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) + 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) - 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) + 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x - textSize.x / 2.0f) - 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//
//			window->DrawList->AddText(m_pFont, size, { position.x - textSize.x / 2.0f, position.y + textSize.y * i }, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), line.c_str());
//		}
//		else
//		{
//			window->DrawList->AddText(m_pFont, size, { (position.x) + 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x) - 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x) + 1.0f, (position.y + textSize.y * i) - 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//			window->DrawList->AddText(m_pFont, size, { (position.x) - 1.0f, (position.y + textSize.y * i) + 1.0f }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, a / 255.0f }), line.c_str());
//
//			window->DrawList->AddText(m_pFont, size, { position.x, position.y + textSize.y * i }, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), line.c_str());
//		}
//
//		y = position.y + textSize.y * (i + 1);
//		i++;
//	}
//
//	return y;
//}
//

void RenderCircle(const ImVec2& position, float radius, uint32_t color, float thickness, uint32_t segments)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddCircle(position, radius, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), segments, thickness);
}

void RenderLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	window->DrawList->AddLine(from, to, ImGui::GetColorU32({ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f }), thickness);
}

void createPlayerTreeNode(Player* player)
{
	if (ImGui::TreeNode((char*)player->pName))
	{
		ImGui::Text("Player: %x", player);
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
					static BaseGameScreen* baseGameSreen = reinterpret_cast<BaseGameScreen*>((DWORD)GetModuleHandle(NULL) + 0x6F3D90);
	
					float screenX = (unit->vPos.x - unit->vPos.z) * 96;
					float screenZ = (unit->vPos.x + unit->vPos.z) * 96;

					float tile_width = 96;
					float tile_height = 96;

					Vector3 screenViewPos = baseGameSreen->gameScreenPtr->mainViewPtr->PosScreen;

					float screenX2 = (unit->vPos.x- screenViewPos.x) * (tile_width / 2) + (unit->vPos.z - screenViewPos.x) * (tile_width / 2);
					float screenY2 = (unit->vPos.z - screenViewPos.y) * (tile_height / 2) - (unit->vPos.x - screenViewPos.x / 2) * (tile_height / 2);

					float GlobalX = screenViewPos.x + (unit->vPos.x - unit->vPos.z) * 2;
					float GlobalY = screenViewPos.y + (unit->vPos.x + unit->vPos.z) * 1;

					ImGui::Text("");
					ImGui::Text("%s", unit->pUnitData->name);
					ImGui::Text("x: %f y: %f z: %f", unit->vPos.x, unit->vPos.y, unit->vPos.z);
					ImGui::Text("sX: %f sY: %f", screenX2, screenY2);

					float xDelta = unit->vPos.x - screenViewPos.x;
					float yDelta = unit->vPos.z - screenViewPos.y;


					float screenXfinal = ((xDelta + yDelta) / 2)*tile_width + 1280;
					float screenYfinal = (((xDelta - yDelta) / 2)* tile_height * -1) / 2 + 720;
					ImGui::Text("gridX: %f gridY: %f", screenXfinal, screenYfinal);
					//RenderCircle(ImVec2(screenXfinal, screenYfinal), 20, 0xffffffff, 2, 10);
					RenderCircle(ImVec2(screenXfinal- tile_width/2, screenYfinal - tile_height), 20, 0xffffffff, 2, 10);
		
					//ImGui::Text("sX: %f sY: %f", screenX, screenZ);
					//ImGui::Text("ScreenPosition x: %f y: %f z: %f", screenX2, screenY2);
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

int tileSize = 1;
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
		if (ImGui::Begin("Age of Empires 2 HD", &openOverlay, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
		{
			static BaseGameScreen* baseGameSreen = reinterpret_cast<BaseGameScreen*>((DWORD)GetModuleHandle(NULL) + 0x6F3D90);
			Vector3 screenViewPos = baseGameSreen->gameScreenPtr->mainViewPtr->PosScreen;
			ImGui::Text("ScreenView x: %f y: %f z: %f", screenViewPos.x, screenViewPos.y);
			ImGui::SliderInt("TileSize", &tileSize, 1, 128);
			for (int i = 0; i < totalPlayers; i++)
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
