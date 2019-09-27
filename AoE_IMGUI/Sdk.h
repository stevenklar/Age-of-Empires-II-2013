#pragma once
#include <Windows.h>
#include <vector>

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

std::vector<Unit*> getCivilianList(Player* player)
{
	std::vector<Unit*> civilian;

	static Main* main = reinterpret_cast<Main*>((DWORD)GetModuleHandle(NULL) + Offsets::main);
	static int totalPlayers = *reinterpret_cast<int*>((DWORD)GetModuleHandle(NULL) + Offsets::totalPlayers);

	static GameData* gameData = main->GameData;
	static PlayerArray* playerArray = gameData->pPlayerArray;

	for (int i = 0; i < player->objectManager->iObjectCount; i++)
	{
		Unit* unit = player->objectManager->untis[i];

		if (!unit)
			continue;

		if (unit->pOwner != player)
			continue;

		if (unit->pUnitData->Class != EnumUnitDataClass::Civilian)
			continue;

		civilian.push_back(unit);
	}

	return civilian;
}

Vector2 worldToScreen(Unit* unit)
{
	return worldToScreen(unit->vPos);
}

std::vector<Unit*> getIdleCivilianList(Player* player)
{
	std::vector<Unit*> civilian = getCivilianList(player);
	std::vector<Unit*> idle;

	for (auto c : civilian)
	{
		Target* target = c->pTarget->pTarget;

		if (!target)
		{
			idle.push_back(c);
			continue;
		}

		if (!target->pTargetData->pTargetUnit)
		{
			idle.push_back(c);
			continue;
		}

	}

	return idle;
}

class Ressources getCivilianDistribution(Player* player)
{
	class Ressources res = { 0 };

	std::vector<Unit*> civilian = getCivilianList(player);

	for (auto c : civilian)
	{
		Target* target = c->pTarget->pTarget;

		if (!target)
			continue;

		if (!target->pTargetData->pTargetUnit)
			continue;

		EnumUnitDataClass targetClass = static_cast<EnumUnitDataClass>(target->pTargetData->pTargetUnit->pUnitData->Class);

		if (EnumUnitDataClass::Tree == targetClass)
			res.wood += 1.0f;

		if (EnumUnitDataClass::BerryBush == targetClass
			|| EnumUnitDataClass::LIvestock == targetClass
			|| EnumUnitDataClass::PreyAnimal == targetClass
			|| EnumUnitDataClass::PredatorAnimal == targetClass
			|| EnumUnitDataClass::Farm == targetClass)
			res.food += 1.0f;

		if (EnumUnitDataClass::GoldMine == targetClass)
			res.gold += 1.0f;

		if (EnumUnitDataClass::StoneMine == targetClass)
			res.stone += 1.0f;
	}

	return res;
}