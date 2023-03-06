#pragma once
#include "SpriteComponent.h"
//�~�`��̃A���S���Y��

class DrawCircleComponent : SpriteComponent
{
public:
	DrawCircleComponent(class Actor* owner) : SpriteComponent(owner, 100)
	{}

	void Draw(SDL_Renderer* renderer);

	void SetRudius(float rudius) { mRudius = rudius; }
	void SetColor(int redColor, int greenColor, int blueColor, int alpha);

	int* GetColor() { return mColor; }
	float GetRudius() { return mRudius; }
private:
	float mRudius;
	int mColor[4];
};