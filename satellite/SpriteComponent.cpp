#include "SpriteComponent.h"
#include "Satellite.h"
#include "Game.h"
#include "Math.h"

SpriteComponent::SpriteComponent(class Actor* owner, int drawOrder) : Component(owner), mDrawOrder(drawOrder), mTexHeight(0), mTexWidth(0), mTexture(nullptr)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		//Satellite‚©‚ç‚Ì‘Š‘ÎˆÊ’u‚É•`‰æ
		SDL_Rect r;
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.x = static_cast<int>((mOwner->GetPosition().x - mOwner->GetGame()->GetSatellite()->GetPosition().x + mOwner->GetGame()->GetScreenSize()->x / 2) - r.w / 2);
		r.y = static_cast<int>((mOwner->GetPosition().y - mOwner->GetGame()->GetSatellite()->GetPosition().y + mOwner->GetGame()->GetScreenSize()->y / 2) - r.h / 2);

		SDL_RenderCopyEx(renderer,
			mTexture,
			nullptr,
			&r,
			Math::ToDegrees(Math::Atan( mOwner->GetPosition())),
			nullptr,
			SDL_FLIP_NONE);
	}
}

void SpriteComponent::SetTexture(SDL_Texture* tex)
{
	mTexture = tex;
	SDL_QueryTexture(tex, nullptr, nullptr, &mTexWidth, &mTexHeight);
}