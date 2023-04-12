#pragma once

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Axe : public Entity
{
public:

	Axe();
	virtual ~Axe();

	bool Start();

	bool Update();

	bool CleanUp();

public:

	bool isPicked = false;

private:
	//DONE 4: Add a physics to an item
	PhysBody* pbody;
};