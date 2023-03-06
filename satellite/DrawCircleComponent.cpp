#include "DrawCircleComponent.h"

void DrawCircleComponent::Draw(SDL_Renderer* renderer)
{
	//SDL_RenderDrawLine
	//�������~�̕`��@�\�����������SpriteComponent��Asset���烍�[�h����΂悭�ˁH
}

void DrawCircleComponent::SetColor(int redColor, int greenColor, int blueColor, int alpha)
{
	mColor[0] = redColor;
	mColor[1] = greenColor;
	mColor[2] = blueColor;
	mColor[3] = alpha;
}