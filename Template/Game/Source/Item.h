#pragma once

#include "Entity.h"
#include "Point.h"

enum class ItemType
{
	RING,
	AXE,
};

class Item : public Entity
{
public:
	//Item() {};
	Item(ItemType type, iPoint pos, SDL_Texture* text, EntityType entType = EntityType::ITEM) : Entity(entType), itemType(type), texture(text), isDragging(false)
	{
		bounds.x = pos.x;
		bounds.y = pos.y;
		bounds.w = 32;
		bounds.h = 32;
		isDropped = false;
	}

	virtual ~Item() {}

	//virtual bool Load() override { return true; }
	//virtual bool Update(float dt) override;
	//virtual void Draw(bool showColliders) {}
	//virtual bool UnLoad() override;

	//inline ObjectType GetItemType() const { return objectType; }

	/*bool operator==(Item& it) const
	{
		return this->objectType == it.objectType;
	}*/

public:
	//ObjectType objectType;
	ItemType itemType;

	SDL_Texture* texture;
	const char* texturePath;

	SDL_Rect section;

	bool isDragging; // For inventory
	//eastl::string mapName;

	bool isDropped; // For dropping items
};