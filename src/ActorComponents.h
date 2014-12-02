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
		void render(SDL_Renderer *ren, SDL_Rect *BBox);
	
	private:
		LTexture tex;
};

class InputComponent
{
	public: 
		InputComponent();
		~InputComponent();
		void MoveThisActor(SDL_Keycode sym, SDL_Rect *BBox);
};

#endif
