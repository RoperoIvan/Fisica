#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleAudio.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	flipperfx = App->audio->LoadFx("pinball/FlipperDown.wav");

	idle.PushBack({ 21,665,21,60 });

	dockanim.PushBack({ 20,764,20,60 });
	dockanim.PushBack({ 78,708,20,70 });
	dockanim.loop = false;
	dockanim.speed = 0.05f;

	flipRpos = { 279,697 };
	flipLpos = { 178,697 };
	dockpos = { 415, 650 };

	dock = App->physics->CreateDock(dockpos.x, dockpos.y, 21, 60);

	flipperL = App->physics->CreateFlipper(flipLpos.x, flipLpos.y, 68, 33, false);
	flipperR = App->physics->CreateFlipper(flipRpos.x, flipRpos.y, 68, 33, true);

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
	current_animation = &idle;
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{
		flipperR->body->ApplyForceToCenter({ 0,-1000 }, true);
		App->audio->PlayFx(flipperfx);
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		flipperL->body->ApplyForceToCenter({ 0,-1000 }, true);
		App->audio->PlayFx(flipperfx);
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		current_animation = &dockanim;
	}

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		dock->body->ApplyForceToCenter({ 0,100 }, true);
		dockanim.Reset();
	}

	App->renderer->Blit(App->scene_intro->table, dockpos.x - 10, dockpos.y - 30, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}



