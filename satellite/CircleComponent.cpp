#include "CircleComponent.h"
#include "SDL_image.h"
#include "Game.h"

CircleComponent::CircleComponent(class Actor* owner) :Component(owner)
{
	mOwner->GetGame()->mColider.push_back(this);
}

CircleComponent::~CircleComponent()
{
	auto iter = std::find(mOwner->GetGame()->mColider.begin(), mOwner->GetGame()->mColider.end(), this);
	mOwner->GetGame()->mColider.erase(iter);
}

void CircleComponent::SetRadius(SDL_Texture* tex, float scale)
{
	int texWidth;
	SDL_QueryTexture(tex, nullptr, nullptr, &texWidth, nullptr);
	mRadius = (texWidth * scale) / 2;
}

bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.LengthSquared();

	float radiiSq = a.GetRadius() - b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}
