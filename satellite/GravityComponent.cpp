#include "GravityComponent.h"
#include "Game.h"
#include "Actor.h"
#include "Planet.h"

GravityComponent::GravityComponent(class Actor* owner, int updateOrder) :MoveComponent(owner, updateOrder), mTag(Planet), mMass(0.0f)
{
	mOwner->GetGame()->AddGravity(this);
}

GravityComponent::~GravityComponent()
{
	mOwner->GetGame()->RemoveGravity(this);
}

void GravityComponent::Update(float deltatime)
{
	if (mTag == Planet) return;
	Vector2 speed = this->GetSpeed();
	speed += this->culculateGravity(deltatime);
	this->SetSpeed(speed);
	MoveComponent::Update(deltatime);
}

Vector2 GravityComponent::culculateGravity(float deltatime)
{
	Vector2 returnVec;
	
	for (auto planet : mOwner->GetGame()->mGravityComponents)
	{
		Vector2 direct = planet->GetOwner()->GetPosition() - this->GetOwner()->GetPosition();
		float distance = direct.LengthSquared();
		if (Math::NearZero(distance)) continue;
		direct.Normalize();
		returnVec = returnVec + ((gravity * planet->mMass * deltatime) / distance) * direct;
	}

	return returnVec;
}
