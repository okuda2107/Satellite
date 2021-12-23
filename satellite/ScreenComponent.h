#pragma once
#include "SpriteComponent.h"
class ScreenComponent :
	public SpriteComponent
{
public:
	ScreenComponent(class Actor* owner, int drawOrder) : SpriteComponent(owner, drawOrder)
	{}

	void Draw(SDL_Renderer* renderer);
};

