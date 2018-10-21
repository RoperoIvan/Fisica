#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
	table = NULL;

}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	/*circle = App->textures->Load("pinball/wheel.png"); */
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");
	table = App->textures->Load("pinball/Texturas2.png");

	tablerect.x = 222;
	tablerect.y = 369;
	tablerect.h = 730;
	tablerect.w = 442;

	ballrect.x = 11;
	ballrect.y = 427;
	ballrect.h = 19;
	ballrect.w = 20;

	clickerrect.x = 9;
	clickerrect.y = 565;
	clickerrect.h = 56;
	clickerrect.w = 54;

	brightclicker.x = 9;
	brightclicker.y = 833;
	brightclicker.h = 54;
	brightclicker.w = 56;

	bluecircle.x = 9;
	bluecircle.y = 519;
	bluecircle.h = 37;
	bluecircle.w = 38;

	orangecircle.x = 68;
	orangecircle.y = 520;
	orangecircle.h = 35;
	orangecircle.w = 37;

	int right_bounce[10] = {
		547, 1048,
		587, 974,
		588, 957,
		581, 946,
		524, 1048
	};

	int left_bounce[14] = {
		365, 1046,
		310, 946,
		303, 957,
		303, 975,
		349, 1055,
		357, 1056,
		363, 1052
	};

	int top_bounce[12] = {
		566, 872,
		599, 870,
		610, 862,
		619, 836,
		614, 832,
		562, 868
	};

	ballpos.x = SCREEN_WIDTH / 2;
	ballpos.y = SCREEN_HEIGHT / 2 - 200;
	circlepos.x = SCREEN_WIDTH / 2;
	circlepos.y = SCREEN_HEIGHT / 2;
	bouncerpos.x = SCREEN_WIDTH / 2;
	bouncerpos.y = SCREEN_HEIGHT / 2 - 100;
	bounpos.x = -SCREEN_WIDTH / 2.0f;
	bounpos.y = -SCREEN_HEIGHT / 2.08f;

	ball = App->physics->CreateCircle(ballpos.x, ballpos.y, 10);

	/*bouncer = App->physics->CreateCircleStatic(bouncerpos.x, bouncerpos.y, 27);
	bouncer->body->GetFixtureList()->SetDensity(10.0f);
	bouncer->body->GetFixtureList()->SetRestitution(1.5f);*/

	sensor = App->physics->CreateCircleSensor(circlepos.x, circlepos.y, 18);

	rightBounce = App->physics->CreateChain(bounpos.x, bounpos.y, right_bounce, 10);
	leftBounce = App->physics->CreateChain(bounpos.x, bounpos.y, left_bounce, 14);
	topBounce = App->physics->CreateChain(bounpos.x, bounpos.y, top_bounce, 12);

	rightBounce->body->GetFixtureList()->SetRestitution(1.5f);
	leftBounce->body->GetFixtureList()->SetRestitution(1.5f);
	topBounce->body->GetFixtureList()->SetRestitution(1.5f);
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	App->textures->Unload(table);
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->renderer->Blit(table, 0, 0, &tablerect);
	if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		circles.add(App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 8));
		circles.getLast()->data->listener = this;
	}

	/*if(App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		boxes.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 20,40));
		
	}
*/

	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();

	// All draw functions ------------------------------------------------------
	
	ball->GetPosition(ballpos.x, ballpos.y);
	ball->listener = this;
	App->renderer->Blit(table, ballpos.x, ballpos.y, &ballrect);
	
	sensor->GetPosition(circlepos.x, circlepos.y);
	if (!collision2)
	{
		App->renderer->Blit(table, circlepos.x, circlepos.y, &bluecircle);
	}
	else if (collision2)
	{
		App->renderer->Blit(table, circlepos.x, circlepos.y, &orangecircle);
	}

	/*bouncer->GetPosition(bouncerpos.x, bouncerpos.y);
	if (!collision)
	{
		App->renderer->Blit(table, bouncerpos.x, bouncerpos.y, &clickerrect);
	}
	else if (collision)
	{
		App->renderer->Blit(table, bouncerpos.x, bouncerpos.y, &brightclicker);
	}*/
	
	
	
	
	p2List_item<PhysBody*>* c = circles.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(table, x, y, &ballrect, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	/*c = clicker.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(table, x, y, &clickerrect, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	c = ricks.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(rick, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}*/
	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	if (bodyA != NULL && bodyB != NULL) 
	{	
		if (bodyA == ball && bodyB == bouncer || bodyA == bouncer && bodyB == ball)
		{
			counter++;
			if (counter == 1)
			{
				collision = true;
			}
			if (counter == 2)
			{
				collision = false;
				counter = 0;
			}
			App->audio->PlayFx(bonus_fx);
		}

		if (bodyA == ball && bodyB == sensor || bodyA == sensor && bodyB == ball)
		{
			counter2++;
			if (counter2 == 1)
			{
				collision2 = true;
			}
			if (counter2 == 2)
			{
				collision2 = false;
			}
		}
		
	}
	
}
