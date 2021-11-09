#include "GravityComponent.h"
#include "Actor.h"
#include "Game.h"

GravityComponent::GravityComponent(class Actor* owner, Tag tag, int updateOrder = 10) : Component(owner, updateOrder), mTag(tag)
{
	mOwner->GetGame()->AddGravity(this);
}

GravityComponent::~GravityComponent()
{
	mOwner->GetGame()->RemoveGravity(this);
}

void GravityComponent::Update(float deltatime)
{
	if (!Math::NearZero(mSpeed))
	{
		mForward = ForwardCalculate();

		Vector2 pos = mOwner->GetPosition();
		pos += mForward * mSpeed * deltatime;

		mOwner->SetPosition(pos);
	}
}

Vector2 GravityComponent::ForwardCalculate()
{

}