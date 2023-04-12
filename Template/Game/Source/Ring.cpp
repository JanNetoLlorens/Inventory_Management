#include "Ring.h"
#include "App.h"
#include "Textures.h"
#include "Audio.h"
#include "Input.h"
#include "Render.h"
#include "Log.h"
#include "Point.h"
#include "Physics.h"

Ring::Ring() : Entity(EntityType::RING)
{
	name.Create("ring");
}

Ring::~Ring() {}

bool Ring::Start() {

	position.x = 200;
	position.y = 200;
	texturePath = "Assets/Textures/ring.png";

	id = 1;

	//initilize textures
	texture = app->tex->Load(texturePath);

	// L07 DONE 4: Add a physics to an item - initialize the physics body
	pbody = app->physics->CreateRectangle(position.x, position.y, 32, 32, bodyType::STATIC);

	// L07 DONE 7: Assign collider type
	pbody->ctype = ColliderType::ITEM;


	return true;
}

bool Ring::Update()
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

bool Ring::CleanUp()
{
	/*pbody->body->DestroyFixture(pbody->body->GetFixtureList());
	active = false;*/
	pbody->body->SetActive(false);
	return true;
}