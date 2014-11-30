#ifndef ACTOR_H
#define ACTOR_H

#include "ActorComponents.h"

class Actor
{
	public:
		Actor(int x = 0, int y = 0, RenderComponent *ren = NULL, InputComponent *input = NULL);
		~Actor();
		
		Uint32 posx, posy;

		void render(SDL_Renderer* ren);
		void passInput(SDL_Keycode sym);

		bool hasRenderComponent();
		RenderComponent* getRenderComponent();

		void setPosX(int x);
		void setPosY(int y);
		

	private:
		RenderComponent *mrender;
		InputComponent *minput;
};

#endif
