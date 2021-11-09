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
	GravityComponent(class Actor* owner, Tag tag, int updateOrder = 10);
	~GravityComponent();

	void Update(float deltatime);

private:	
	Vector2 ForwardCalculate();	
	void ForceDirectCalculate();

	float mSpeed;
	Vector2 mForceDirect;//���͂̕���
	Vector2 mForward;//���������������(���͂���݂�90�x)
	float mMass;
	Tag mTag;
};