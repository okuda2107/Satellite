#include "GravityComponent.h"
#include "Actor.h"
#include "Game.h"

GravityComponent::GravityComponent(class Actor* owner, int updateOrder = 10) : Component(owner, updateOrder)
{
	mOwner->GetGame()->AddGravity(this);
}

GravityComponent::~GravityComponent()
{
	mOwner->GetGame()->RemoveGravity(this);
}

void GravityComponent::Update(float deltatime)
{
	if (!Math::NearZeroVector(mForceDirect))
	{
		mForceDirect = ForceDirectCalculate();

		Vector2 pos = mOwner->GetPosition();
		pos += (Verticalize(Normalize(mForceDirect)) * mSpeed + mForceDirect) * deltatime;

		mOwner->SetPosition(pos);
	}
}

Vector2 GravityComponent::ForceDirectCalculate()
{
	for (auto object : mOwner->GetGame()->mGravity)
	{
		if (mTag != object->GetTag())
		{
			float temp;

			Vector2 distance = object->GetOwner()->GetPosition() - mOwner->GetPosition();

			temp = (gravity * object->GetMass() * mMass) / distance.LengthSquared();

			mForceDirect += Normalize(distance) * temp;
		}
	}
}