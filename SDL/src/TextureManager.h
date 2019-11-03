#pragma once

#include "Game.h"

struct TextureManager
{
	static SDL_Texture* LoadTexture(const char* file, SDL_Renderer* renderer);
};