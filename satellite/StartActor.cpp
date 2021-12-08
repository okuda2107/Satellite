#include "StartActor.h"
#include "SDL.h"
#include "Game.h"
#include "SpriteComponent.h"

StartActor::StartActor(class Game* game) : Actor(game)
{
	//タイトルの文字を表示
	//背景もここで生成

}

void StartActor::ActorInput(const uint8_t* keystate)
{
	if (keystate[SDL_SCANCODE_SPACE])
	{
		//ここでデータをロードする

		delete this;
	}
}