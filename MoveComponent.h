#pragma once
#include "Component.h"
#include "Math.h"

class MoveComponent : Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);
	void Update(float deltatime);

	void SetSpeed(float speed) { mSpeed = speed; }
private:
	float mSpeed;
	Vector2 mForward;
};