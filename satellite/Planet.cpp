#include "Planet.h"
#include "GravityComponent.h"
#include "SpriteComponent.h"
#include "MeshComponent.h"
#include "Mesh.h"
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
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Sphere.gpmesh"));
	SetScale(3.0f);
	cc->SetRadius(35.0f);
}

Planet::~Planet()
{
	
}