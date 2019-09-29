#pragma once
#include "Feature.h"

class UnitCollisions : public Feature
{
	void OnUnitIteration(Unit* unit);
	void OnMenuMainWindow();
};