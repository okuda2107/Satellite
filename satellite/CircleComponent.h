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

	void SetRadius(struct SDL_Texture* tex, float scale);
	float GetRadius() const { return  mRadius; };

	const Vector2& GetCenter() const { return mOwner->GetPosition(); };

	CircleComponent &operator+=(const CircleComponent& cc)
	{
		float rate = mOwner->GetScale() / this->mRadius;
		this->mRadius += cc.GetRadius();
		mOwner->SetScale(this->mRadius * rate);
//		float newMass = this->mOwner->mActorGravity->GetMass() + cc.mOwner->mActorGravity->GetMass();
//		this->mOwner->mActorGravity->SetMass(newMass);
		return *this;
	}

private:
	float mRadius;
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);