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

void InputComponent::MoveThisActor(int x, int y)
{
	/*if(mowner->hasRenderComponent())
	{
		RenderComponent *actorRender = mowner->getRenderComponent();
		actorRender->setPosX(actorRender->getPosX() + x);
		actorRender->setPosY(actorRender->getPosY() + y);
	}*/
	cout << "Stub!" << endl;
}
