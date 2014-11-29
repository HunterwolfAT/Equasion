#ifndef ACTOR_H
#define ACTOR_H

#include "ActorComponents.h"

class Actor
{
	public:
		Actor(RenderComponent *ren = NULL);
		~Actor();

		void render(SDL_Renderer* ren);

		bool hasRenderComponent();
		RenderComponent* getRenderComponent();

	private:
		RenderComponent *mrender;
};

#endif
