#pragma once
#include <Windows.h>

#include "Classes.h"
#include "Offsets.h"



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