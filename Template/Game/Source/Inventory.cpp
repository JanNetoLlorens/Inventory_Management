#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Inventory.h"
#include "EntityManager.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"

Inventory::Inventory(bool startEnabled) : Module(startEnabled)
{
	name.Create("inventory");
}

// Destructor
Inventory::~Inventory()
{}

// Called before render is available
bool Inventory::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	for (size_t i = 0; i < MAX_INVENTORY_SLOTS; i++)
	{
		slots[i].id = 0;
	}

	return ret;
}

// Called before the first frame
bool Inventory::Start()
{
	slots[0].bounds =  { 16, 16, 32, 32 }; 
	slots[1].bounds =  { 54, 16, 32, 32 };
	slots[2].bounds =  { 98, 16, 32, 32 };
	slots[3].bounds =  { 142, 16, 32, 32 };
	slots[4].bounds =  { 186, 16, 32, 32 };
	slots[5].bounds =  { 230, 16, 32, 32 };
	slots[6].bounds =  { 16,  58, 32, 32 };
	slots[7].bounds =  { 54,  58, 32, 32 };
	slots[8].bounds =  { 98,  58, 32, 32 };
	slots[9].bounds =  { 142, 58, 32, 32 };
	slots[10].bounds = { 186, 58, 32, 32 };
	slots[11].bounds = { 230, 58, 32, 32 };
	slots[12].bounds = { 16,  100, 32, 32 };
	slots[13].bounds = { 54,  100, 32, 32 };
	slots[14].bounds = { 98,  100, 32, 32 };
	slots[15].bounds = { 142, 100, 32, 32 };
	slots[16].bounds = { 186, 100, 32, 32 };
	slots[17].bounds = { 230, 100, 32, 32 };
	slots[18].bounds = { 16,  142, 32, 32 };
	slots[19].bounds = { 54,  142, 32, 32 };
	slots[20].bounds = { 98,  142, 32, 32 };
	slots[21].bounds = { 142, 142, 32, 32 };
	slots[22].bounds = { 186, 142, 32, 32 };
	slots[23].bounds = { 230, 142, 32, 32 };
	slots[24].bounds = { 16,  184, 32, 32 };
	slots[25].bounds = { 54,  184, 32, 32 };
	slots[26].bounds = { 98,  184, 32, 32 };
	slots[27].bounds = { 142, 184, 32, 32 };
	slots[28].bounds = { 186, 184, 32, 32 };
	slots[29].bounds = { 230, 184, 32, 32 };

	invPos.x = 500; invPos.y = 200;

	img = app->tex->Load("Assets/Textures/inventory.png");

	currentSlotId = 0;
	selectedSlotTexture = app->tex->Load("Assets/Textures/slotSelectedHole.png");

	return true;
}

// Called each loop iteration
bool Inventory::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Inventory::Update(float dt)
{

	if (app->input->GetKey(SDL_SCANCODE_O) == KEY_DOWN && app->scene->items.start != nullptr)
	{
		//TODO 2: Use AddItem
	}
	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN && app->scene->items.start->next != nullptr)
	{
		//TODO 2: Use AddItem
	}

	//TODO 4: Use MoveThroughInv

	if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		//TODO 6: Use MoveItemPos


	DeleteItem();

	return true;
}

// Called each loop iteration
bool Inventory::PostUpdate()
{
	bool ret = true;

	if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	app->render->DrawTexture(img, invPos.x, invPos.y);

	//TODO 3: Use DrawItems

	return ret;
}

// Called before quitting
bool Inventory::CleanUp()
{
	LOG("Freeing inventory");

	return true;
}

void Inventory::AddItem(Entity* item)
{
	//TODO 2: Create a loop to iterate over the slots

		//detect the empty slots and pass the information to the it (check the struct)
}

void Inventory::DrawItems()
{

	//TODO 3: Iterate over the slots and use DrawTexture to display the item in the inventory (check that the slots are not empty)
	
		//The sections for the textures
		SDL_Rect itemSect { 0,0,32,32 };
		SDL_Rect slotMarkerSect{ 0,0,38,39 };
	
}

void Inventory::MoveThroughInv()
{
	//TODO 4: By clicking WASD move throught the slots (check currentSlotId and apply limits)
}

void Inventory::DeleteItem()
{
	//TODO 5: By clicking K delete and item from a slot (reset the information of the corresponding slot)
}

void Inventory::ChangeItemPos()
{
	//TODO 6: In this function you must be able to copy a filled slot and print it on an empty slot (the conditions are the trick here)

		//Copy the slot if filled (check saveCopy and saveCopyIdSlot)
		
		//Print the information into the empty slot and delete the first slot
}