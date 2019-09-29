#pragma once
#include <vector>

class Player;
class Unit;
class Feature
{
	
protected:
	bool enabled = true;
public:
	virtual void OnInitialise();
	virtual void OnShutdown();

	virtual void OnDraw();
	virtual void OnMenuMainWindow();
	virtual void OnMenuPlayerTreenode(Player* player);

	virtual void OnPlayerIteration(Player* player);
	virtual void OnUnitIteration(Unit* unit);
};