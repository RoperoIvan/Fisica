#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> clicker;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	SDL_Texture* table;
	uint bonus_fx;

	PhysBody* ball;
	PhysBody* circlepoint;
	PhysBody* bouncer;
	PhysBody* sensor;

	SDL_Rect tablerect;
	SDL_Rect ballrect;
	SDL_Rect clickerrect;
	SDL_Rect bluecircle;
	SDL_Rect orangecircle;
	SDL_Rect brightclicker;

	iPoint ballpos, circlepos, bouncerpos;
	int counter = 0;
	bool collision = false;
};
