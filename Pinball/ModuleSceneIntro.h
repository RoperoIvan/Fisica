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
	p2List<PhysBody*> chains;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	SDL_Texture* table;
	uint bonus_fx;

	PhysBody* ball;
	PhysBody* circlepoint;
	PhysBody* bouncer;
	PhysBody* sensor;
	PhysBody* leftBounce;
	PhysBody* rightBounce;
	PhysBody* topBounce;
	PhysBody* sensorhole;
	PhysBody* sensorhole2;


	SDL_Rect tablerect;
	SDL_Rect ballrect;
	SDL_Rect clickerrect;
	SDL_Rect bluecircle;
	SDL_Rect orangecircle;
	SDL_Rect brightclicker;

	iPoint ballpos, circlepos, bouncerpos,bounpos,holepos, holepos2;
	bool collision = false;
	bool collision2 = false;
	bool tp = false;
	bool tp2 = false;
};
