#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
	:Component(owner, updateOrder)
	, mSpeed(Vector2::Zero)
{}

void MoveComponent::Update(float deltatime)
{
	if (!(Math::NearZero(mSpeed.x) && Math::NearZero(mSpeed.y))) {
		
		Vector2 pos = mOwner->GetPosition();
		pos += mSpeed * deltatime;
		
		mOwner->SetPosition(pos);
	}
}
