#include "ActorComponents.h"
#include <iostream>

using namespace std;

RenderComponent::RenderComponent()
{
}

RenderComponent::~RenderComponent()
{
	tex.free();
}

void RenderComponent::LoadTexture(SDL_Renderer* ren, string path)
{
	tex.loadFromFile(ren, path);
}

void RenderComponent::render(SDL_Renderer *ren, SDL_Rect *BBox)
{
		tex.render(ren, BBox->x, BBox->y);
}

// InputComponent PART

InputComponent::InputComponent(/*Actor *owner*/)
{
	//mowner = owner;
	cout << "Stub!" << endl;
}

InputComponent::~InputComponent()
{
	//mowner = NULL;
	cout << "Stub!" << endl;
}

void InputComponent::MoveThisActor(SDL_Keycode sym, SDL_Rect *BBox)
{
	printf("New Pos: %d - %d\n", BBox->x, BBox->y);
	switch(sym) {
	case SDLK_w:
		BBox->y -= 2;
		break;
	case SDLK_s:
		BBox->y += 2;
		break;
	case SDLK_a:
		BBox->x -= 2;
		break;
	case SDLK_d:
		BBox->x += 2;
		break;
	}
}
