#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInit.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleSceneIntro.h"
#include "ModuleEnd.h"

ModuleEnd::ModuleEnd(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	initTex = nullptr;
}

ModuleEnd::~ModuleEnd()
{}

bool ModuleEnd::Start()
{
	initRect = { 165,37,443,727 };
	initTex = App->textures->Load("pinball/Lost_scene.png");
	App->scene_intro->Disable();
	App->player->Disable();
	App->physics->Disable();
	App->initScene->Disable();
	play = App->physics->CreateRectangleSensor(215, 390, 200, 50);

	return true;
}

update_status ModuleEnd::Update()
{
	if (App->input->GetMouseX() <= 215 && App->input->GetMouseX() >= 15 && App->input->GetMouseY() >= 340 && App->input->GetMouseY() <= 390)
	{
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
		{
			App->initScene->Enable();
			this->Disable();
		}
	}
	App->renderer->Blit(initTex, 0, 0, &initRect);
	return UPDATE_CONTINUE;
}

bool ModuleEnd::CleanUp()
{
	App->textures->Unload(initTex);
	return true;
}
