#include "Actor.h"
#include <iostream>

using namespace std;

Actor::Actor(int x, int y, RenderComponent *ren)
{
	posx = x;
	posy = y;

	mrender = ren;
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

Actor::~Actor()
{
	mrender = NULL;
}
