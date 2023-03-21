#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Ring.h"
#include "Axe.h"

struct SDL_Texture;

class Scene : public Module
{
public:

	Scene(bool startEnabled);

	// Destructor
	virtual ~Scene();

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

public:

	List<Entity*> items;

private:
	SDL_Texture* img;
};

#endif // __SCENE_H__