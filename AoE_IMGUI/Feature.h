#pragma once
#include <vector>

class Player;
class Unit;
class Feature
{

protected:
	static std::vector <Player*> players;
	static std::vector <Unit*> units;
public:
	virtual void OnInitialise();
	virtual void OnShutdown();

	virtual void OnDraw();
	virtual void OnMenuMainWindow();
	virtual void OnMenuPlayerTreenode(Player* player);

	virtual void OnPlayerIteration(Player* player);
	virtual void OnUnitIteration(Unit* unit);
};