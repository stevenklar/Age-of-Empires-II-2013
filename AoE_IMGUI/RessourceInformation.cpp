#include "RessourceInformation.h"

#include "Sdk.h"
#include "Renderer.h"

#include "Engine.h"



std::vector<Unit*> getCivilianList(Player* player)
{
	std::vector<Unit*> civilian;

	static Main* main = Engine::Get()->GetMain();
	static int totalPlayers = Engine::Get()->GetTotalPlayers();

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

struct RessourceDistribution
{
	int wood, food, gold, stone;
};

RessourceDistribution getCivilianDistribution(Player* player)
{
	RessourceDistribution resDist = RessourceDistribution();
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
			resDist.wood += 1;

		if (EnumUnitDataClass::BerryBush == targetClass
			|| EnumUnitDataClass::LIvestock == targetClass
			|| EnumUnitDataClass::PreyAnimal == targetClass
			|| EnumUnitDataClass::PredatorAnimal == targetClass
			|| EnumUnitDataClass::Farm == targetClass)
			resDist.food += 1;

		if (EnumUnitDataClass::GoldMine == targetClass)
			resDist.gold += 1;

		if (EnumUnitDataClass::StoneMine == targetClass)
			resDist.stone += 1;
	}

	return resDist;
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

void RessourceInformation::OnMenuPlayerTreenode(Player* player)
{
	ImGui::Text("Player: %x", player);
	ImGui::Text("Wood: %.f", player->Ressources->wood);
	ImGui::Text("Food: %.f", player->Ressources->food);
	ImGui::Text("Gold: %.f", player->Ressources->gold);
	ImGui::Text("Stone: %.f", player->Ressources->stone);
	ImGui::Text("Villigers: %.f", player->Ressources->villagerCount);
	ImGui::Text("Pop: %.f/%.f", player->Ressources->CurrentPop, player->Ressources->CurrentPop + player->Ressources->popSpaceLeft);
	
	RessourceDistribution resDist = getCivilianDistribution(player);

	if (ImGui::TreeNode("Villiger Ressource Distribution"))
	{
		ImGui::Text("Wood: %d", resDist.wood);
		ImGui::Text("Food: %d", resDist.food);
		ImGui::Text("Gold: %d", resDist.gold);
		ImGui::Text("Stone: %d", resDist.stone);
		ImGui::TreePop();
	}
}