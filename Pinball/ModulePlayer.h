#pragma once
#include "Module.h"
#include "p2Point.h"
#include "Globals.h"



class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	PhysBody * flipperR;
	PhysBody* flipperL;
	PhysBody* dock;

	iPoint flipRpos, flipLpos, dockpos;

};