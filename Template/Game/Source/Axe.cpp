#include "Axe.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include "Point.h"
#include "Physics.h"

Axe::Axe() : Entity(EntityType::AXE)
{
	name.Create("axe");
}

Axe::~Axe() {}

bool Axe::Start() {

	position.x = 200;
	position.y = 240;
	texturePath = "Assets/Textures/axe.png";

	id = 2;

	//initilize textures
	texture = app->tex->Load(texturePath);

	// L07 DONE 4: Add a physics to an item - initialize the physics body
	pbody = app->physics->CreateCircle(position.x + 11, position.y + 11, 11, bodyType::STATIC, true);

	// L07 DONE 7: Assign collider type
	pbody->ctype = ColliderType::ITEM;

	return true;
}

bool Axe::Update()
{
	if (!pbody->body->IsActive())
	{
		pbody->body->DestroyFixture(pbody->body->GetFixtureList());
		active = false;
	}

	// L07 DONE 4: Add a physics to an item - update the position of the object from the physics.  
	position.x = METERS_TO_PIXELS(pbody->body->GetTransform().p.x) - 11;
	position.y = METERS_TO_PIXELS(pbody->body->GetTransform().p.y) - 11;

	SDL_Rect rect = { 0,0,32,32 };
	app->render->DrawTexture(texture, position.x, position.y, &rect);

	return true;
}

bool Axe::CleanUp()
{
	pbody->body->SetActive(false);
	return true;
}