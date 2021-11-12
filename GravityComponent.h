#pragma once
#include "Component.h"
#include "Math.h"

//万有引力の計算、挙動実装クラス
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
	Vector2 mForceDirect;//引力の方向
	float mMass;
	Tag mTag;

	const static float gravity;
};