#pragma once
#include "Feature.h"

class Maphack : public Feature
{
	typedef int(__cdecl *tMaphack)();
	tMaphack oMaphack;

	void OnMenuMainWindow();
};