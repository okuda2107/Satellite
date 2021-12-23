#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner) : GravityComponent(owner)
{}

void InputComponent::ProcessInput(const uint8_t* keystate)
{
	SetKey(0);
	if (keystate[mAcceleKey])
	{
		SetKey(1);
	}
	if (keystate[mDeceleKey])
	{
		SetKey(-1);
	}
}

void InputComponent::Update(float deltatime)
{
	Vector2 mForceDirect = ForceDirectCalculate();
	if (!Math::NearZeroVector(mForward))
	{
		bool m = false;
		if (mKey == 1)
		{
			mTime += deltatime;
			m = true;
		}
		else if (mKey == -1)
		{
			mTime -= deltatime;
			m = true;
		}

		if (!m)
			mTime = 0.0f;

		if (mForward == Normalize(Verticalize(mForceDirect)))
			mForward = Normalize(Verticalize(mForceDirect));
		else if (mForward == Normalize(Verticalize(-1 * mForceDirect)))
			mForward = Normalize(Verticalize(-1 * mForceDirect));

		Vector2 pos = mOwner->GetPosition();
		pos += mForward * mSpeed * deltatime;
		mOwner->SetPosition(pos);
		
		mForward = Normalize(mForward * mSpeed + mForceDirect * mTime);
	}
}