#pragma once

#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int x, int y, int w, int h, Uint32 flags);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool IsRunning() { return m_IsRunning; }

private:
	bool m_IsRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	int m_NumberOfItems;
	int m_FrameCount;

};

