#include "GravityComponent.h"
#include "Actor.h"
#include "Game.h"

GravityComponent::GravityComponent(class Actor* owner, int updateOrder) : Component(owner, updateOrder), mSpeed(0.0f), mMass(0.0f)
{
	mOwner->GetGame()->mGravity.push_back(this);
}

GravityComponent::~GravityComponent()
{
	auto iter = std::find(mOwner->GetGame()->mGravity.begin(), mOwner->GetGame()->mGravity.end(), this);
	mOwner->GetGame()->mGravity.erase(iter);
}

void GravityComponent::Update(float deltatime)
{
	ForceDirectCalculate();
	if (!Math::NearZeroVector(mForceDirect))
	{	
		Vector2 pos = mOwner->GetPosition();
		pos += (Normalize(Verticalize(mForceDirect)) * mSpeed + mForceDirect) * deltatime;

		mOwner->SetPosition(pos);
	}
}

void GravityComponent::ForceDirectCalculate()
{
	mForceDirect = Vector2(0.0f, 0.0f);
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