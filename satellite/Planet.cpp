#include "Planet.h"
#include "GravityComponent.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Random.h"
#include "GameJudgeActor.h"
#include "Satellite.h"

Planet::Planet(class Game* game) : Actor(game), mTargetFrag(false)
{
	CircleComponent* cc = new CircleComponent(this);
	GravityComponent* grac = new GravityComponent(this);
	grac->SetTag(grac->Object);
	grac->SetMass(20.0f * Random::GetFloat());
	SetScale(Random::GetFloat()*0.8);
	Vector2 randPos = Random::GetVector(-1**(GetGame()->GetWorldSize()), *(GetGame()->GetWorldSize()));
	randPos *= 1.0f / 3.0f;
	SetPosition(randPos);
	SpriteComponent* sc = new SpriteComponent(this, 100);
	SDL_Texture* tex = GetGame()->GetTexture("Assets/ori.png");
	sc->SetTexture(tex);

	cc->SetRadius(tex, GetScale());
}

Planet::~Planet()
{
	if (mTargetFrag)
	{
		GameJudgeActor* gja = new GameJudgeActor(GetGame());
		SDL_Log("flag");
		GetGame()->GetSatellite()->SetState(EDead);
	}
}