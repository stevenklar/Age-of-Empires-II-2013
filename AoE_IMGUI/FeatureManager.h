#pragma once
#include <vector>

class Feature;
class Player;
class Unit;
class FeatureManager
{
private:
	static FeatureManager* instance;

	std::vector <Feature*> features;

	FeatureManager();

public:
	static FeatureManager* Get();
	void registerFeature(Feature* feature);

	//Callbacks
	void OnInitialise();
	void OnShutdown();
	void OnDraw();
	void OnMenuMainWindow();
	void OnMenuPlayerTreenode(Player* player);
	void OnPlayerIteration(Player* player);
	void OnUnitIteration(Unit* unit);
};