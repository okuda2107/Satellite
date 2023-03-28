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

		if (pos.x < -512.0f) { pos.x = 510.0f; }
		else if (pos.x > 512.0f) { pos.x = -510.0f; }
		if (pos.y < -384.0f) { pos.y = 382.0f; }
		else if (pos.y > 384.0f) { pos.y = -382.0f; }
		
		mOwner->SetPosition(pos);
	}
}
