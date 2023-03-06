#pragma once
#include "Component.h"
#include "Math.h"
#include <vector>

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

	void SetTag(Tag tag) { mTag = tag; }
	void SetMass(float mass) { mMass = mass; }
	void SetSpeed(float speed) { mSpeed = speed; }
	void SetKey(int key) { mKey = key; }
	void SetForward() 
	{
		Vector2 Direct = ForceDirectCalculate();
		Vector2 vec = Verticalize(Direct);
		mForward = Normalize(vec);
	}

	Vector2 ForceDirectCalculate();
	
	float GetMass() { return mMass; }
	Tag GetTag() { return mTag; }
protected:	
	float mSpeed;
	Vector2 mForceDirect;//���͂̕���
	Vector2 mForward;//�i�ޕ���
	float mMass;
	Tag mTag;
	int mKey;
	float mTime;

	static constexpr float gravity = 98.0665f;
};