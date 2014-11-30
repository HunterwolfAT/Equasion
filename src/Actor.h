#ifndef ACTOR_H
#define ACTOR_H

#include "ActorComponents.h"

class Actor
{
	public:
		Actor(int x = 0, int y = 0, RenderComponent *ren = NULL);
		~Actor();
		
		int posx, posy;

		void render(SDL_Renderer* ren);

		bool hasRenderComponent();
		RenderComponent* getRenderComponent();

		void setPosX(int x);
		void setPosY(int y);
		

	private:
		RenderComponent *mrender;
};

#endif
