#pragma once
#include "Actor.h"

//ゲームクリアの判定コンポーネント
class GameJudgeActor : public Actor
{
public:
	GameJudgeActor(class Game* game);

	void Update(float deltatime);

	void SetTarget(Actor* target) { mTarget = target; }

private:
	Actor* mTarget;
};