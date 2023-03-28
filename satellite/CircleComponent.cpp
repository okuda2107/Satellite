#include "CircleComponent.h"
#include "SDL_image.h"
#include "Game.h"

CircleComponent::CircleComponent(class Actor* owner) :Component(owner), mRadius(0.0f), mCollision(false)
{
	this->GetOwner()->GetGame()->AddColider(this);
}

CircleComponent::~CircleComponent()
{
	this->GetOwner()->GetGame()->RemoveColider(this);
}

void CircleComponent::Update(float deltatime)
{//これではそれぞれの衝突計算するときに誤差が生まれる．一気に計算した方がいい
	auto iter = std::find(mOwner->GetGame()->mColiders.begin(), mOwner->GetGame()->mColiders.end(), this);
	iter++;
	for (auto end = mOwner->GetGame()->mColiders.end(); iter != end; iter++)
	{
		if (Intersect(*this, **iter))
		{
			SetFlag(true);
			mActors.push_back(*iter);
			CircleComponent* cc = *iter;
			cc->SetFlag(true);
			cc->mActors.push_back(this);
			*iter = cc;
		}
	}
}

bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSquared();

	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}
