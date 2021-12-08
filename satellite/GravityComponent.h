#pragma once
#include "Component.h"
#include "Math.h"
#include <vector>

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

	void SetTag(Tag tag) { mTag = tag; }
	void SetMass(float mass) { mMass = mass; }
	void SetSpeed(float speed) { mSpeed = speed; }

	float GetMass() { return mMass; }
	Tag GetTag() { return mTag; }
private:	
	void ForceDirectCalculate();

	float mSpeed;
	Vector2 mForceDirect;//引力の方向
	float mMass;
	Tag mTag;

	static constexpr float gravity = 9.80665f;
};