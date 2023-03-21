#pragma once

#include "Module.h"
#include "Ring.h"
#include "Axe.h"

#define MAX_INVENTORY_SLOTS 30
#define ITEM_STACK 32

enum class SlotState
{
	NONE = 0,
	UNSELECTED,
	SELECTED,
	USE,
};


struct InventorySlot
{
	SDL_Rect bounds;
	SDL_Texture* texture;
	int itemsAmount;
	bool filled;
	int id;
	SlotState state;	
};

struct SDL_Texture;

class Inventory : public Module
{
public:

	Inventory(bool startEnabled);

	// Destructor
	virtual ~Inventory();

	// Called before render is available
	bool Awake();
	// Called before the first frame
	bool Start();
	// Called before all Updates
	bool PreUpdate();
	// Called each loop iteration
	bool Update(float dt);
	// Called before all Updates
	bool PostUpdate();
	// Called before quitting
	bool CleanUp();

	void AddItem(Entity* item);
	void DrawItems();
	void MoveThroughInv();
	void DeleteItem();
	void ChangeItemPos();
	
public:

	List<Entity*> items;

private:
	SDL_Texture* img;

	SDL_Texture* selectedSlotTexture;

	InventorySlot slots[MAX_INVENTORY_SLOTS];
	int currentSlotId;
	InventorySlot* originSlot;
	iPoint invPos;

	InventorySlot saveCopy;
	int saveCopyIdSlot;
	bool changingSlot = false;
};