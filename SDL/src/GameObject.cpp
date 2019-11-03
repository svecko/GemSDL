#include "GameObject.h"
#include "TextureManager.h"

const int SCALE = 4;

GameObject::GameObject(const char* texture, SDL_Renderer* renderer, int xPos, int yPos)
{
	m_Renderer = renderer;
	m_ObjTexture = TextureManager::LoadTexture(texture, renderer);

	m_XPos = xPos;
	m_YPos = yPos;
}

void GameObject::Update()
{
	m_SrcRect.h = 16;
	m_SrcRect.w = 16;
	m_SrcRect.x = m_SrcRect.w * static_cast<int>((SDL_GetTicks() / 100) % 4);
	m_SrcRect.y = 0;

	m_DstRect.x = m_XPos;
	m_DstRect.y = m_YPos;
	m_DstRect.w = m_SrcRect.w * SCALE;
	m_DstRect.h = m_SrcRect.h * SCALE;

}

void GameObject::Render()
{
	SDL_RenderCopy(m_Renderer, m_ObjTexture, &m_SrcRect, &m_DstRect);
}
