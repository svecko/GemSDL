#pragma once

#include "Game.h"

class GameObject
{
public:
	GameObject(const char* texture, SDL_Renderer* renderer, int xPos, int yPos);
	~GameObject();

	void Update();
	void Render();

private:
	int m_XPos, m_YPos;

	SDL_Texture* m_ObjTexture;
	SDL_Rect m_SrcRect, m_DstRect;
	SDL_Renderer* m_Renderer;
};