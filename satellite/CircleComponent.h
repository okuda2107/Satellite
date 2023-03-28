#pragma once
#include "Component.h"
#include "Math.h"
#include "Actor.h"
#include "GravityComponent.h"

class CircleComponent : public Component
{
public:
	CircleComponent(class Actor* owner);
	~CircleComponent();

	void Update(float deltatime);

	void SetFlag(bool flag) { mCollision = flag; }
	void SetRadius(float radius) { mRadius = radius; }

	bool GetFlag() const { return mCollision; }
	float GetRadius() const { return  mRadius; }
	const Vector2& GetCenter() const { return mOwner->GetPosition(); }

	std::vector<class CircleComponent*> mActors;

private:
	float mRadius;
	bool mCollision;	
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);