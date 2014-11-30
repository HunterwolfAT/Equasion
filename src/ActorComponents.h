#ifndef ACTORCOMPENENTS_H
#define ACTORCOMPENENTS_H

#include <SDL2/SDL.h>
#include "LTexture.h"
//#include "Actor.h"

class RenderComponent
{
	public:
		RenderComponent();
		~RenderComponent();
		int getPosX();
		int getPosY();
		void InitPos(int* x, int* y);
		void LoadTexture(SDL_Renderer* ren, std::string path);
		LTexture getTexture();
		void render(SDL_Renderer *ren, int x, int y);
	
	private:
		LTexture tex;
};

class InputComponent
{
	public: 
		InputComponent(/*Actor *owner*/);
		~InputComponent();
		void MoveThisActor(int x, int y);
	private:
		//Actor *mowner;
};

#endif
