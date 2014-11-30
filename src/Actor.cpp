#include "Actor.h"
#include <iostream>

using namespace std;

Actor::Actor(int x, int y, RenderComponent *ren, InputComponent *input)
{
	posx = x;
	posy = y;

	mrender = ren;
	minput = input;
}

bool Actor::hasRenderComponent()
{
	if (mrender == NULL)
		return false;
	return true;
}

RenderComponent* Actor::getRenderComponent()
{
	return mrender;
}

void Actor::setPosX(int x)
{
	posx = x;
}

void Actor::setPosY(int y)
{
	posy = y;
}

void Actor::render(SDL_Renderer* ren)
{
	if (mrender != NULL) 
	{
		mrender->render(ren, posx, posy );
	}
}

void Actor::passInput(SDL_Keycode sym)
{
	if (minput != NULL)
	{
		//printf("Stub!\n");
		minput->MoveThisActor(sym, &posx, &posy);
	}
}

Actor::~Actor()
{
	mrender = NULL;
}
