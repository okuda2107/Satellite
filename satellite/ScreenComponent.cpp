#include "ScreenComponent.h"
#include "Actor.h"
#include "Game.h"

void ScreenComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		SDL_Rect r;
		r.h = static_cast<int>(mTexHeight * mOwner->GetScale());
		r.w = static_cast<int>(mTexWidth * mOwner->GetScale());
		r.x = static_cast<int>((mOwner->GetPosition().x + mOwner->GetGame()->GetScreenSize()->x / 2) - r.w / 2);
		r.y = static_cast<int>((mOwner->GetPosition().y + mOwner->GetGame()->GetScreenSize()->y / 2) - r.h / 2);

		SDL_RenderCopyEx(renderer,
			mTexture,
			nullptr,
			&r,
			Math::ToDegrees(Math::Atan(mOwner->GetPosition())),
			nullptr,
			SDL_FLIP_NONE);
	}
}