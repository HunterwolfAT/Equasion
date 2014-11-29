#include "ActorComponents.h"
#include <iostream>

using namespace std;

RenderComponent::RenderComponent()
{
	posx = posy = 0;
}

RenderComponent::~RenderComponent()
{
	tex.free();
}

int RenderComponent::getPosX()
{
	return posx;
}

int RenderComponent::getPosY()
{
	return posy;
}

void RenderComponent::setPosX(int x)
{
	posx = x;
}

void RenderComponent::setPosY(int y)
{
	posy = y;
}

void RenderComponent::LoadTexture(SDL_Renderer* ren, string path)
{
	tex.loadFromFile(ren, path);
}

void RenderComponent::render(SDL_Renderer *ren) {
	tex.render(ren, posx, posy);
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
