#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* file, SDL_Renderer* renderer)
{
	SDL_Surface* tmpSurface = IMG_Load(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}