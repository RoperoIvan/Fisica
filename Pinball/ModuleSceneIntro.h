#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleInitScene : public Module
{
public:
	ModuleInitScene(Application* app, bool start_enabled = true);
	~ModuleInitScene();

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
	uint bluefx;

	PhysBody* ball;
	PhysBody* circlepoint;
	PhysBody* bouncer;
	PhysBody* bouncermedium;
	PhysBody* bouncermedium2;
	PhysBody* bouncermedium3;
	PhysBody* bouncerlittle;
	PhysBody* sensor;
	PhysBody* leftBounce;
	PhysBody* rightBounce;
	PhysBody* topBounce;
	PhysBody* sensorhole;
	PhysBody* sensorhole2;
	PhysBody* sensorlittle;
	PhysBody* sensor2;
	PhysBody* sensor3;
	PhysBody* sensorvolume;
	PhysBody* sensorfx;


	SDL_Rect tablerect;
	SDL_Rect ballrect;
	SDL_Rect clickerrect;
	SDL_Rect clickerrectmedium;
	SDL_Rect clickerrectlittle;
	SDL_Rect sensorlittlerect;
	SDL_Rect bluecircle;
	SDL_Rect orangecircle;
	SDL_Rect brightclicker;
	SDL_Rect brightclickermedium;
	SDL_Rect brightclickerlittle;
	SDL_Rect sensorlittleor;
	SDL_Rect flipperLrect;
	SDL_Rect flipperRrect;

	iPoint ballpos, circlepos, bouncerpos, bounpos, holepos, holepos2, circlepos2, circlepos3, circlepos4;
	iPoint bouncermpos, bouncermpos3, bouncermpos2, bouncerlpos;

	bool collision = false;
	bool collision2 = false;
	bool collision3 = false;
	bool collision4 = false;
	bool collision5 = false;
	bool collision6 = false;
	bool collision7 = false;
	bool collision8 = false;
	bool collision9 = false;

	bool tp = false;
	bool tp2 = false;
	bool mute = false;
	bool mutefx = false;
	int combo = 0;
	int combo2 = 0;
	int highscore = 0;
	int lives = 0;
	int points = 0;
	int score;
	char text[10];
	char text2[10];
	char text3[10];

};
