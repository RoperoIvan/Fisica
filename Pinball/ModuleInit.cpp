#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleInit.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"


ModuleInit::ModuleInit(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	initTex = nullptr;
}

ModuleInit::~ModuleInit()
{}

bool ModuleInit::Start()
{
	/*initRect = {291,20,441,728};
	initTex = App->textures->Load("pinball/init_scene.png");

	App->player->CleanUp();*/

	return true;
}

update_status ModuleInit::Update()
{
	/*App->renderer->Blit(initTex, 0, 0, &initRect);*/

	return UPDATE_CONTINUE;
}

bool ModuleInit::CleanUp()
{
	//App->textures->Unload(initTex);
	return true;
}
