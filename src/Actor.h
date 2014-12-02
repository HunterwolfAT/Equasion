#ifndef ACTOR_H
#define ACTOR_H

#include "ActorComponents.h"

class Actor
{
	public:
		Actor(int x = 0, int y = 0, RenderComponent *ren = NULL, InputComponent *input = NULL);
		~Actor();
		
		void render(SDL_Renderer* ren);
		void passInput(SDL_Keycode sym);

		bool hasRenderComponent();
		RenderComponent* getRenderComponent();

		void setPos(int x, int y);
		SDL_Rect getRect();
		

	private:
		RenderComponent *mrender;
		InputComponent *minput;
		SDL_Rect mBBox; // Bounding Box
};

#endif
