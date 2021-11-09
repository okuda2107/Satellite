#pragma once
#include "Component.h"
#include "Math.h"

//万有引力の計算、挙動実装クラス
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
	Vector2 mForceDirect;//引力の方向
	Vector2 mForward;//加速減速する方向(引力からみて90度)
	float mMass;
	Tag mTag;
};