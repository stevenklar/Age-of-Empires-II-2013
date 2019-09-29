#include "Engine.h"

#include "Sdk.h"
#include "Offsets.h"


Engine* Engine::instance = NULL;

Engine::Engine()
{
	base = (DWORD)GetModuleHandle(NULL);
}

Engine* Engine::Get()
{
	if (!instance)
	{
		instance = new Engine();
	}
	return instance;
}

Main* Engine::GetMain()
{
	return reinterpret_cast<Main*>(base + Offsets::main);
}

BaseGameScreen* Engine::GetBaseGameScreen()
{
	return reinterpret_cast<BaseGameScreen*>(base + Offsets::baseGameScreen);
}

int Engine::GetTotalPlayers()
{
	return *reinterpret_cast<int*>(base + Offsets::totalPlayers);
}

Vector2 Engine::worldToScreen(Vector3 position)
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

Vector2 Engine::worldToScreen(Unit* unit)
{
	return worldToScreen(unit->vPos);
}