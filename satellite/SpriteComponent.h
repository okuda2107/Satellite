#pragma once
#include "Component.h"
#include "SDL.h"
#include "SDL_image.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent(class Actor* owner, int drawOrder);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(SDL_Texture* tex);

	const int GetDrawOrder() { return mDrawOrder; }
protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTexHeight;
	int mTexWidth;
};