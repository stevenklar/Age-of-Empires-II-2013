#include "UnitCollisions.h"

#include "Sdk.h"
#include "Renderer.h"
#include "Engine.h"


void DrawBox(Unit* unit)
{
	Vector3 one3 = unit->vPos;
	one3.x -= unit->pUnitData->collisionX;
	one3.z -= unit->pUnitData->collisionY;
	Vector2 one = Engine::Get()->worldToScreen(one3);

	Vector3 two3 = unit->vPos;
	two3.x += unit->pUnitData->collisionX;
	two3.z += unit->pUnitData->collisionY;
	Vector2 two = Engine::Get()->worldToScreen(two3);

	Vector3 three3 = unit->vPos;
	three3.x -= unit->pUnitData->collisionX;
	three3.z += unit->pUnitData->collisionY;
	Vector2 three = Engine::Get()->worldToScreen(three3);

	Vector3 four3 = unit->vPos;
	four3.x += unit->pUnitData->collisionX;
	four3.z -= unit->pUnitData->collisionY;
	Vector2 four = Engine::Get()->worldToScreen(four3);

	ImVec2 ivOne = ImVec2(one.x, one.y);
	ImVec2 ivTwo = ImVec2(two.x, two.y);
	ImVec2 ivThree = ImVec2(three.x, three.y);
	ImVec2 ivFour = ImVec2(four.x, four.y);

	Renderer::Get()->RenderRect(ivOne, ivFour, ivTwo, ivThree, 0xff0000ff);
}

void UnitCollisions::OnUnitIteration(Unit* unit)
{
	if (enabled)
	{
		DrawBox(unit);
	}
}

void UnitCollisions::OnMenuMainWindow()
{
	ImGui::Checkbox("ESP", &enabled);
}
