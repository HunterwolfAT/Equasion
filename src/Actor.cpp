#include "Actor.h"

using namespace std;

Actor::Actor(RenderComponent *ren)
{
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

void Actor::render(SDL_Renderer* ren)
{
	if (mrender != NULL) 
	{
		mrender->render(ren);
	}
}

Actor::~Actor()
{
	mrender = NULL;
}
