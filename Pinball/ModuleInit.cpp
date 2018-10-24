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


ModuleInit::ModuleInit(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	initTex = nullptr;
}

ModuleInit::~ModuleInit()
{}

bool ModuleInit::Start()
{
	initRect = {291,20,441,728};
	initTex = App->textures->Load("pinball/init_scene.png");
	App->scene_intro->Disable();
	App->player->Disable();
	App->physics->Disable();
	App->endScene->Disable();
	play = App->physics->CreateRectangleSensor(215, 390, 200,50);
	
	return true;
}

update_status ModuleInit::Update()
{
	if (App->input->GetMouseX() >= 115 && App->input->GetMouseX() <= 215 && App->input->GetMouseY() >= 340 && App->input->GetMouseY() <= 390)
	{
		if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN)
		{		
			App->physics->Enable();
			App->scene_intro->Enable();
			App->player->Enable();

			this->Disable();
		}
	}
	App->renderer->Blit(initTex, 0, 0, &initRect);
	return UPDATE_CONTINUE;
}

bool ModuleInit::CleanUp()
{
	App->textures->Unload(initTex);
	return true;
}
