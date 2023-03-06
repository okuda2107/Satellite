#pragma once
#include "Actor.h"

//���ۂ�TransActor�����āA�Q�[���̃V�[���J�ڂ����
class StartActor : public Actor
{
public:
	StartActor(class Game* game);

	void ActorInput(const uint8_t* keystate);


};