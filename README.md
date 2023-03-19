# Introduction

In loads of games the player has to collect differents items, materials through out the story of the videogame so there appears the problem. Where do the player put those items? The inventory which is the place where you will put everything you collect. Here appears the inventory management which basically are the different tools the player will have to organise the different items. Depending on the game a good management of the inventory will be more or less important, for example in all kinds of RPGs having a well thought system is necessary because most time of the game the player will be managing items recieved from quests, killing enemies, crafting...

# Types Inventory Systems

Here I will some categories in which you can organise most of the games inventories. I say most because there is not just some ways of creating an inventory system, new ways can be invented by designers. All the games that enter these categories despite being put in the same pack each of them have its own differences which makes them unic.

## The Classic JRPG Inventory or "Rule of 99

This one is very easy to implement into the game because the player normally has one universal inventory where it stashes all the items it founds during the gameplay, an inventory share among the party members. The slots are infinite, everytime you add a new item to the inventory a new slot is created, ennabling the player to stash an innumerable amount of items. However there is a fixed number of each, typically 99 but it can be 50, 100, 1000.

PROS:
- Low design risk
- Easily scalable
- Easily implemented
- Sorting and filtering

CONS:
- Searching
- Realism
- Non-visual

![Branching](https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/pokemonInv.png)

![[https://github.com/JanNetoLlorens/Inventory_Management/blob/main/WebpageAssets/pokemonInv.png | width = 600px]]

## The Weighted Inventory

The inventory is rulled by how many weight the character can carry. To add an extra layer of depth and to make the management of the inventory more immersive a value which represents the weight is added to every item and character will be able to carry items until the total weight is reached. If the total weight goes over the limit the character won't be able to move or its movent would be extremly diminished forcing the player to remove items. 

This system gained a great degree of popularity during the last decade, due to the growth of Western RPG

* If you add this system to your game is mandatory to be able to search items by weight.

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

* The second all the items just occupy one slot.

PROS:
- Visual
- Drag and drop
- Realism

CONS:
- Arrangement
- Size balancing
- Stash
