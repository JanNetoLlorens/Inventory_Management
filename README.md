## Link to the Presentation

[Link to the presentation](https://docs.google.com/presentation/d/1Xn4yaQkcfGut4O5_Wk8ZEM0TXJdEdhAJOft5CHNzca8/edit?usp=sharing)

# Introduction

In loads of games the player has to collect differents items, materials through out the story of the videogame so there appears the problem. Where do the player put those items? The inventory which is the place where you will put everything you collect. Here appears the inventory management which basically are the different tools the player will have to organise the different items. Depending on the game a good management of the inventory will be more or less important, for example in all kinds of RPGs having a well thought system is necessary because most time of the game the player will be managing items recieved from quests, killing enemies, crafting...

# Types Inventory Systems

Here I will some categories in which you can organise most of the games inventories. I say most because there is not just some ways of creating an inventory system, new ways can be invented by designers. All the games that enter these categories despite being put in the same pack each of them have its own differences which makes them unic.

## The Classic JRPG Inventory or "Rule of 99

This one is very easy to implement into the game because the player normally has one universal inventory where it stashes all the items it founds during the gameplay, an inventory share among the party members. The slots are infinite, everytime you add a new item to the inventory a new slot is created, ennabling the player to stash an innumerable amount of items. However there is a fixed number of each, typically 99 but it can be 50, 100, 1000.

![Octocat](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/99inv.jpg) ![Octocat](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/pokemonInv.png)

PROS:
- Low design risk
- Easily scalable
- Easily implemented
- Sorting and filtering

CONS:
- Searching
- Realism
- Non-visual


## The Weighted Inventory

The inventory is rulled by how many weight the character can carry. To add an extra layer of depth and to make the management of the inventory more immersive a value which represents the weight is added to every item and character will be able to carry items until the total weight is reached. If the total weight goes over the limit the character won't be able to move or its movent would be extremly diminished forcing the player to remove items. 

This system gained a great degree of popularity during the last decade, due to the growth of Western RPG

* If you add this system to your game is mandatory to be able to search items by weight.

![Octocat](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/Fallout3.jpg)

PROS:
- Resource management
- Realism
- Sorting and filtering

CONS:
- Balance
- Item dump
- Item value
- Non-visual

## The visual Grid

The items of the inventory instead of being displayed as text are shown ase images in a grid. For this one there are two variants:

* The first tryes to represent the size of the items making them occupy more or less slots which makes the inventory more interactive because the player has to solve a little puzzle to fit the maximum amount of items as it is possible. 

![Octocat](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/ResidentEvilIV.jpg)


* The second all the items just occupy one slot.

![Octocat](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/LostArkInv.png)

PROS:
- Visual
- Drag and drop
- Realism

CONS:
- Arrangement
- Size balancing
- Stash

#Handout

## TODO 1 - Get in Touch

Too start whith the handout i will make a brief explanation of the code I prepared for it, basically what I added to the Project II template. Check and make sure to understand the basics before advancing to the next TODO.

* Two items added. These inherit from the parent class entity and and are managed by the module EntityManager. The entities are added into a list inside the EntityManager and this is the one in charge of calling the loop functions of the entities or destroying them. There is just one little change in the items which is that I added an id which will be useful when when to pass the item from being diplayed into the map to the inventory. By pressing "q" and "e" a ring or an axe will spawn in the scene.

* Inventory module added. It works as a scene when the player wants to open the inventory by clicking the "i" the module will be set as Active and it will appear the inventory.

Inside the inventory:

 * SlotState enum class added. It will be necessary to manage different states of the slots for example when moving objects, there  we will differentiate between selected and unselected.
 
 * InventorySlot struct added. This struct basically defines a slot.
 
 * Five functions to manage the inventory added. This ones aren't donte yet because they will be the principal content of the handout.
 

## TODO 2 - Add Item

This function is the portal from the map to your inventory, to sum up it passes the information from an entity displayed in the scene to a slot in the inventory. Because the inventory isn't just one slot it will have to be implemented a loop which detects if a slot is empty or not and then pass the required information to the corresponding slot.

```c++
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
		}
```

## TODO 3 - Draw Items

Whith this function we will be able to display visually the items in the inventory. Depending of what item we have in each slot we will have to draw the corresponding texture. To do that we will have to find a way to be able to recognise what appears in the slot or if there is nothing. As in the 2 TODO a loop will be required.

* to do that the "int id" of the slot structure will be very useful.

```c++
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
```

## TODO 4 - Move Through the Inventory

We will have to find a way to change from on slot to another by using W, A, S, D. To notice if we are really changing of slot we will add a slot marker. We will have to add limits so that we don't go outside the inventory slots.

* Outside the InventorySlot struct there is a variable which we will need to use "currentSlotId".

```c++
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
```

## TODO 5 - Delete Items

We have to add a function to release space from the inventory in case we don't have enough to take another item. A function which will work similarly would be a function which drops the item to the scene, the item will still have to be deleted from the inventory but it have to spawn in the scene. By clicking a button you have to be able to delete an object, basically it mean reseting the information stored in that slot to leave it empty.

```c++
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
```

## TODO 6

In this function we have to create a way of moving one slot to another one. To be able to do that we will copy a filled slot and then print it in an empty one. We will have to be careful with the conditions because if we messed up we can make infinite copies of one object. 
* Use SaveCopy, saveCopyIdSlot to store the slot information and bool filled, SlotState and changingSlot for the conditions.
* After the copy print the information in the empty slot and delete the first one.
```c++
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
```
