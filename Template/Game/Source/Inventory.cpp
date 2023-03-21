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
		AddItem(app->scene->items.start->data);
		app->scene->items.start->data->Disable();
	}
	if (app->input->GetKey(SDL_SCANCODE_P) == KEY_DOWN && app->scene->items.start->next != nullptr)
	{
		AddItem(app->scene->items.start->next->data);
		app->scene->items.start->data->Disable();
	}

	MoveThroughInv();

	if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		ChangeItemPos();


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
	DrawItems();

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
	for (int i = 0; i < MAX_INVENTORY_SLOTS; ++i)
	{
		if (slots[MAX_INVENTORY_SLOTS].id == item->id && slots[i].itemsAmount <= ITEM_STACK)
		{
			slots[i].itemsAmount++;
			slots[i].state = SlotState::UNSELECTED;
			break;
		}
		else if (slots[i].id == 0)
		{
			slots[i].id = item->id;
			slots[i].filled = true;
			slots[i].itemsAmount = 1;
			slots[i].texture = item->texture;
			slots[i].state = SlotState::UNSELECTED;
			break;
		}
	}
}

void Inventory::DrawItems()
{
	for (int i = 0; i < MAX_INVENTORY_SLOTS; ++i)
	{
		SDL_Rect r { 0,0,32,32 };
		SDL_Rect r2{ 0,0,38,39 };
		//Draw Item Texture
		if (slots[i].id != 0)
		{
			app->render->DrawTexture(selectedSlotTexture, slots[currentSlotId].bounds.x + invPos.x, slots[currentSlotId].bounds.y + invPos.y, &r2, false);
			app->render->DrawTexture(slots[i].texture, slots[i].bounds.x+invPos.x, slots[i].bounds.y+invPos.y, &r, false);
			//app->render->DrawText("1", slots[i].bounds.x+25, slots[i].bounds.y+25, slots[i].bounds.w, slots[i].bounds.h, { 255,255,255 });
		}
	}
}

void Inventory::MoveThroughInv()
{
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
		if (currentSlotId > 5)
			currentSlotId -= 6;

	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		if (currentSlotId < 24)
			currentSlotId += 6;

	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
		if (currentSlotId != 0 && currentSlotId != 6 && currentSlotId != 12 && currentSlotId != 18 && currentSlotId != 24)
				currentSlotId -= 1;

	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
		if (currentSlotId != 5 && currentSlotId != 11 && currentSlotId != 17 && currentSlotId != 23 && currentSlotId != 29)
			currentSlotId += 1;
}

void Inventory::ChangeItemPos()
{

	if (slots[currentSlotId].filled && slots[currentSlotId].state == SlotState::UNSELECTED && !changingSlot)
	{
		changingSlot = true;
		slots[currentSlotId].state = SlotState::SELECTED;
		saveCopyIdSlot = currentSlotId;
		saveCopy.id = slots[currentSlotId].id;
		saveCopy.itemsAmount = slots[currentSlotId].itemsAmount;
		saveCopy.texture = slots[currentSlotId].texture;
	}


	if(!slots[currentSlotId].filled && changingSlot)
	{
		if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && !slots[currentSlotId].filled)
		{
			//Delete the slot where you had the item
			slots[saveCopyIdSlot].filled = false;
			slots[saveCopyIdSlot].id = 0;
			slots[saveCopyIdSlot].itemsAmount = 0;
			slots[saveCopyIdSlot].state = SlotState::UNSELECTED;
			slots[saveCopyIdSlot].texture = nullptr;
			changingSlot = false;

			//Change the item position
			slots[currentSlotId].filled = true;
			slots[currentSlotId].id = saveCopy.id;
			slots[currentSlotId].itemsAmount = saveCopy.itemsAmount;
			slots[currentSlotId].texture = saveCopy.texture;
			slots[currentSlotId].state = SlotState::UNSELECTED;
		}
	}	
}

void Inventory::DeleteItem()
{
	if (app->input->GetKey(SDL_SCANCODE_K) == KEY_DOWN)
	{
		slots[currentSlotId].filled = false;
		slots[currentSlotId].id = 0;
		slots[currentSlotId].itemsAmount = 0;
		slots[currentSlotId].state = SlotState::UNSELECTED;
		slots[currentSlotId].texture = nullptr;
	}
}