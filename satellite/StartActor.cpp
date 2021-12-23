#include "StartActor.h"
#include "SDL.h"
#include "Game.h"
#include "ScreenComponent.h"
//Satelliteが死んだら生成
StartActor::StartActor(class Game* game) : Actor(game)
{
	//タイトルの文字を表示
	//背景もここで生成
	ScreenComponent* sc = new ScreenComponent(this, 200);
	SDL_Texture* tex = GetGame()->GetTexture("Assets/face.png");
	sc->SetTexture(tex);
}

void StartActor::ActorInput(const uint8_t* keystate)
{
	if (keystate[SDL_SCANCODE_SPACE])
	{
		//ここでデータをロードする

		delete this;
	}
}