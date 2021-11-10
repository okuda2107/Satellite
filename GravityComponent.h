#pragma once
#include "Component.h"
#include "Math.h"

//���L���͂̌v�Z�A���������N���X
class GravityComponent : public Component
{
	enum Tag
	{
		Player,
		Object
	};
	GravityComponent(class Actor* owner, int updateOrder = 10);
	~GravityComponent();

	void Update(float deltatime);

	float GetMass() { return mMass; }
private:	
	Vector2 ForceDirectCalculate();

	float mSpeed;
	Vector2 mForceDirect;//���͂̕���
	float mMass;
	Tag mTag;

	const static float gravity;
};