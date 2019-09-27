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


//Vector3 one3 = unit->vPos;
//one3.x -= unit->pUnitData->collisionX;
//one3.z -= unit->pUnitData->collisionY;
//Vector2 one = worldToScreen(one3);
//
//Vector3 two3 = unit->vPos;
//two3.x += unit->pUnitData->collisionX;
//two3.z += unit->pUnitData->collisionY;
//Vector2 two = worldToScreen(two3);
//
//Vector3 three3 = unit->vPos;
//three3.x -= unit->pUnitData->collisionX;
//three3.z += unit->pUnitData->collisionY;
//Vector2 three = worldToScreen(three3);
//
//Vector3 four3 = unit->vPos;
//four3.x += unit->pUnitData->collisionX;
//four3.z -= unit->pUnitData->collisionY;
//Vector2 four = worldToScreen(four3);
//
//ImVec2 ivOne = ImVec2(one.x, one.y);
//ImVec2 ivTwo = ImVec2(two.x, two.y);
//ImVec2 ivThree = ImVec2(three.x, three.y);
//ImVec2 ivFour = ImVec2(four.x, four.y);
//
//Renderer::Get()->RenderRect(ivOne, ivFour, ivTwo, ivThree, color);