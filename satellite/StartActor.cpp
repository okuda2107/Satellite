#include "StartActor.h"
#include "SDL.h"
#include "Game.h"
#include "ScreenComponent.h"
//Satellite�����񂾂琶��
StartActor::StartActor(class Game* game) : Actor(game)
{
	//�^�C�g���̕�����\��
	//�w�i������Ő���
	ScreenComponent* sc = new ScreenComponent(this, 200);
	SDL_Texture* tex = GetGame()->GetTexture("Assets/face.png");
	sc->SetTexture(tex);
}

void StartActor::ActorInput(const uint8_t* keystate)
{
	if (keystate[SDL_SCANCODE_SPACE])
	{
		//�����Ńf�[�^����[�h����

		delete this;
	}
}