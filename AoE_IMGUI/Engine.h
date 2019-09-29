#pragma once
#include <cstdint>

struct Vector2;
struct Vector3;

class Main;
class Unit;
class BaseGameScreen;
class Engine
{
	static Engine* instance;

	uint32_t base;
	
	//typedef int(__cdecl *tMaphack)();
	//tMaphack oMaphack;
	//

	Engine();

public:
	static Engine* Get();
	Main* GetMain();
	BaseGameScreen* GetBaseGameScreen();
	int GetTotalPlayers();

	Vector2 worldToScreen(Vector3 position);
	Vector2 worldToScreen(Unit* unit);
};
