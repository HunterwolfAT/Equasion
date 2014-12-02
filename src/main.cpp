#include <SDL2/SDL.h>

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#include "LTexture.h"
#include "Actor.h"
#include "ActorComponents.h"

using namespace std;

// Some globally used pointers
SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;

bool Editor = false;

int init()
{
	// SDL Initialisieren
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	// Fenster erzeugen
	win = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if (win == NULL){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	// Renderer erzeugen
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
}

int cleanup() {
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	win = NULL;
	ren = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main(int argc, const char *argv[])
{
	// Initialise SDL and make a Window and everything
	if (!init())
		return 1;

	// Some Testing stuff so we can see what we are doing
	RenderComponent PipRender;
	PipRender.LoadTexture(ren, "../data/hesitating.png");
	InputComponent PipController;
	Actor LittlePip(10, 10, &PipRender, &PipController);
	Actor DontRender;	//Note(hunter): No parenthesis, or g++ will think DontRender is a function

	cout << "LittlePip has PipRender: " << LittlePip.hasRenderComponent() << endl;
	//cout << "DontRender has PipRender: " << DontRender.hasRenderComponent() << endl;

	// ============== MAIN LOOP ==========
	// Main loop flag
	bool quit = false;

	// Event Handler
	SDL_Event e;

	while( !quit )
	{
		// Handle events on queue
		while ( SDL_PollEvent( &e ) != 0 ) 	//NOTE: SDL_PollEvent internally calls SDL_PumpEvent()
		{
			// User requests quit
			if ( e.type == SDL_QUIT )
				quit = true;
			if ( e.type == SDL_KEYDOWN ) {
				LittlePip.passInput(e.key.keysym.sym);
			}
			if ( e.type == SDL_MOUSEMOTION ) {
				int mx, my;
				SDL_GetMouseState( &mx, &my );
				printf("Mouse Position: %d, %d\n", mx, my );
			}
		}

		// Clear screen
		SDL_RenderClear(ren);

		// Render stuff here!
		LittlePip.render(ren);
		DontRender.render(ren);

		// Update screen
		SDL_RenderPresent(ren);

	}


	cleanup();
	return 0;
}
