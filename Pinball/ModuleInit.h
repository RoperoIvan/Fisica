#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class ModuleInit : public Module
{
public:
	ModuleInit(Application* app, bool start_enabled = true);
	~ModuleInit();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* initTex;
	PhysBody* play;
	SDL_Rect initRect;
	

};
