#pragma once
#include "Module.h"
#include "p2Point.h"
#include "Globals.h"
#include "Animation.h"


class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	Animation dockanim;
	Animation idle;
	Animation* current_animation = nullptr;

	SDL_Rect dockrect;

	uint flipperfx;

	PhysBody * flipperR;
	PhysBody* flipperL;
	PhysBody* dock;

	iPoint flipRpos, flipLpos, dockpos;

};