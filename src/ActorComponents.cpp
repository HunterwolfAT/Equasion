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

void RenderComponent::render(SDL_Renderer *ren, int x, int y)
{
		tex.render(ren, x, y);
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

void InputComponent::MoveThisActor(SDL_Keycode sym, Uint32 *x, Uint32 *y)
{
	printf("New Pos: %d - %d\n", *x, *y);
	switch(sym) {
	case SDLK_w:
		*y -= 2;
		break;
	case SDLK_s:
		*y += 2;
		break;
	case SDLK_a:
		*x -= 2;
		break;
	case SDLK_d:
		*x += 2;
		break;
	}
}
