#pragma once
#include "Component.h"
#include "Math.h"

//���L���͂̌v�Z�A���������N���X
class GravityComponent : public Component
{
public:
	enum Tag
	{
		Player,
		Object
	};
	GravityComponent(class Actor* owner, int updateOrder = 10);
	~GravityComponent();

	void Update(float deltatime);

	void UpdateSpeed(float accele) { mSpeed += accele; }

	float GetMass() { return mMass; }
	Tag GetTag() { return mTag; }
private:	
	Vector2 ForceDirectCalculate();

	float mSpeed;
	Vector2 mForceDirect;//���͂̕���
	float mMass;
	Tag mTag;

	const static float gravity;
};