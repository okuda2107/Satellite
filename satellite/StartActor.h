#pragma once
#include "Actor.h"

//実際はTransActorを作って、ゲームのシーン遷移を実装
class StartActor : public Actor
{
public:
	StartActor(class Game* game);

	void ActorInput(const uint8_t* keystate);


};