#include "Planet.h"
#include "GravityComponent.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Random.h"
#include "Texture.h"
#include "Renderer.h"
#include "Satellite.h"

Planet::Planet(class Game* game) : Actor(game), mTargetFrag(false)
{
	//aiueo
	CircleComponent* cc = new CircleComponent(this);
	GravityComponent* grac = new GravityComponent(this);
	grac->SetTag(grac->Planet);
	grac->SetMass(2.0f);
	SpriteComponent* sc = new SpriteComponent(this, 100);
	Texture* tex = GetGame()->GetRenderer()->GetTexture("Assets/ori.png");
	sc->SetTexture(tex);
	SetScale(0.2f);
	cc->SetRadius(100.0f);
}

Planet::~Planet()
{
	
}