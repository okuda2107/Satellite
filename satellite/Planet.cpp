#include "Planet.h"
#include "GravityComponent.h"
#include "SpriteCOmponent.h"
#include "Game.h"

Planet::Planet(class Game* game) : Actor(game)
{
	GravityComponent* grac = new GravityComponent(this);
	grac->SetTag(grac->Object);
	grac->SetMass(10.0f);
	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetTexture(GetGame()->GetTexture("Assets/ori.png"));
}