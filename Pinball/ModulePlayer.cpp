#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"


ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	flipRpos = { 289,713 };
	flipLpos = { 175,713 };
	dockpos = { 415, 650 };

	dock = App->physics->CreateDock(dockpos.x, dockpos.y, 21, 60);

	flipperL = App->physics->CreateFlipper(flipLpos.x, flipLpos.y, 78, 48, false);
	flipperR = App->physics->CreateFlipper(flipRpos.x, flipRpos.y, 78, 48, true);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		flipperR->body->ApplyForceToCenter({ 0,-100 }, true);
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		flipperL->body->ApplyForceToCenter({ 0,-100 }, true);
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		dock->body->ApplyForceToCenter({ 0,100 }, true);
	}

	return UPDATE_CONTINUE;
}



