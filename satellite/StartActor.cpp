#include "StartActor.h"
#include "SDL.h"
#include "Game.h"
#include "SpriteComponent.h"

StartActor::StartActor(class Game* game) : Actor(game)
{
	//�^�C�g���̕�����\��
	//�w�i�������Ő���

}

void StartActor::ActorInput(const uint8_t* keystate)
{
	if (keystate[SDL_SCANCODE_SPACE])
	{
		//�����Ńf�[�^�����[�h����

		delete this;
	}
}