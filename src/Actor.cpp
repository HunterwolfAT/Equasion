#include "Actor.h"
#include <iostream>

using namespace std;

Actor::Actor(int x, int y, RenderComponent *ren, InputComponent *input)
{
	mrender = ren;
	minput = input;

	mBBox.x = x;
	mBBox.y = y;
	//TODO(max): Height and Width should not be static like here
	mBBox.w = 220;
	mBBox.h = 231;
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

void Actor::setPos(int x, int y)
{
	if (x >= 0)
		mBBox.x = x;
	if (y >= 0)
		mBBox.y = y;
}

SDL_Rect Actor::getRect() 
{
	return mBBox;
}

void Actor::render(SDL_Renderer* ren)
{
	if (mrender != NULL) 
	{
		mrender->render(ren, &mBBox );
	}
}

void Actor::passInput(SDL_Keycode sym)
{
	if (minput != NULL)
	{
		//printf("Stub!\n");
		minput->MoveThisActor(sym, &mBBox);
	}
}

Actor::~Actor()
{
	mrender = NULL;
}
