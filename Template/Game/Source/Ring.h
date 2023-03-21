#pragma once

#include "Entity.h"
#include "Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class Ring : public Entity
{
public:

	Ring();
	virtual ~Ring();

	bool Start();

	bool Update();

	bool CleanUp();

public:

	bool isPicked = false;
	
private:

	//DONE 4: Add a physics to an item
	PhysBody* pbody;
};