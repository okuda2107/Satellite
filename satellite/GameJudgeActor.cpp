#include "GameJudgeActor.h"
#include "ScreenComponent.h"
#include "Game.h"
//Planetが死んだら生成
GameJudgeActor::GameJudgeActor(class Game* game) : Actor(game)
{
	ScreenComponent* sc = new ScreenComponent(this, 200);
	SDL_Texture *tex = GetGame()->GetTexture("Assets/ori.png");
	sc->SetTexture(tex);
}