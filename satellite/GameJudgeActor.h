#pragma once
#include "Actor.h"

//�Q�[���N���A�̔���R���|�[�l���g
class GameJudgeActor : public Actor
{
public:
	GameJudgeActor(class Game* game);

	void Update(float deltatime);

	void SetTarget(Actor* target) { mTarget = target; }

private:
	Actor* mTarget;
};