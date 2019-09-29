#include "RessourceInformation.h"

#include "Sdk.h"
#include "Renderer.h"



void RessourceInformation::OnMenuPlayerTreenode(Player* player)
{
	ImGui::Text("Player: %x", player);
	ImGui::Text("Wood: %.f", player->Ressources->wood);
	ImGui::Text("Food: %.f", player->Ressources->food);
	ImGui::Text("Gold: %.f", player->Ressources->gold);
	ImGui::Text("Stone: %.f", player->Ressources->stone);
	ImGui::Text("Villigers: %.f", player->Ressources->villagerCount);
	ImGui::Text("Pop: %.f/%.f", player->Ressources->CurrentPop, player->Ressources->CurrentPop + player->Ressources->popSpaceLeft);
}