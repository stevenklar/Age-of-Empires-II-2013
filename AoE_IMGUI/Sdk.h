#pragma once
#include <Windows.h>

#include "Classes.h"
#include "Offsets.h"




void DrawBox(Vector3 unitPos)
{
	Vector3 one3 = unitPos;
	one3.x -= 1;
	one3.z -= 1;
	Vector2 one = worldToScreen(one3);

	Vector3 two3 = unitPos;
	two3.x += 1;
	two3.z += 1;
	Vector2 two = worldToScreen(two3);

	Vector3 three3 = unitPos;
	three3.x -= 1;
	three3.z += 1;
	Vector2 three = worldToScreen(three3);

	Vector3 four3 = unitPos;
	four3.x += 1;
	four3.z -= 1;
	Vector2 four = worldToScreen(four3);
	
	ImVec2 ivOne = ImVec2(one.x, one.y);
	ImVec2 ivTwo = ImVec2(two.x, two.y);
	ImVec2 ivThree = ImVec2(three.x, three.y);
	ImVec2 ivFour = ImVec2(four.x, four.y);

	Renderer::Get()->RenderRect(ivOne, ivFour, ivTwo, ivThree,0xff0000ff);
}

Vector2 worldToScreen(Vector3 position)
{
	int tile_width = 96;
	int tile_height = 96;
	static BaseGameScreen* baseGameSreen = reinterpret_cast<BaseGameScreen*>((DWORD)GetModuleHandle(NULL) + Offsets::baseGameScreen);

	float xDelta = position.x - baseGameSreen->gameScreenPtr->mainViewPtr->PosScreen.x;
	float yDelta = position.z - baseGameSreen->gameScreenPtr->mainViewPtr->PosScreen.y;

	int xResolution = baseGameSreen->gameScreenPtr->ScreenResX1;
	int yResolution = baseGameSreen->gameScreenPtr->ScreenResY1;

	float screenXfinal = ((xDelta + yDelta) / 2)*tile_width + (xResolution / 2);
	float screenYfinal = (((xDelta - yDelta) / 2)* tile_height * -1) / 2 + (yResolution / 2);

	screenYfinal -= position.y * 96 / 4;

	return Vector2(screenXfinal - tile_width / 2, screenYfinal - tile_height);
}

Vector2 worldToScreen(Unit* unit)
{
	return worldToScreen(unit->vPos);
}