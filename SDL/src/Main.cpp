#include "Game.h"

#include <iostream>

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	Game* game = new Game();

	game->Init("Untitled", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

	while (game->IsRunning())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime)
		{
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}
	
	game->Clean();


	return 0;
}

