#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "LinkedLists.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game()
{
}

Game::~Game()
{
}

GameObject* items[100];
int index = 0;

void Game::Init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	srand(time(nullptr));
	m_NumberOfItems = rand() % 91 + 10;
	m_FrameCount = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "[LOG]: SubSystems Initialized..." << std::endl;

		m_Window = SDL_CreateWindow(title, x, y, w, h, flags);

		if (m_Window)
		{
			std::cout << "[LOG]: Window Constructed..." << std::endl;
		}

		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);

		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(m_Renderer, 236, 240, 241, 100);
			std::cout << "[LOG]: Renderer Constructed..." << std::endl;
		}

		m_IsRunning = true;
		std::cout << "[LOG]: Application is Running..." << std::endl;
	}
	else
	{
		m_IsRunning = false;
	}

	std::cout << "[LOG]: Constructing " << m_NumberOfItems << " Items..." << std::endl;
	for (size_t i = 0; i < m_NumberOfItems; i++)
	{
		SinglyLinkedList::Node::Push(rand() % (1920 + 1 - 64), rand() % (1080 + 1 - 64));
		items[i] = new GameObject("assets/items/RedGem.png", m_Renderer, SinglyLinkedList::Node::GetPosition(i).x, SinglyLinkedList::Node::GetPosition(i).y);
	}
	std::cout << "[LOG]: " << m_NumberOfItems << " Items Constructed..." << std::endl;
}

void Game::HandleEvents()
{
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type)
	{
	case SDL_QUIT:
		m_IsRunning = false;
		break;

	default:
		break;
	}
}

void Game::Update()
{
	for (size_t i = 0; i < m_NumberOfItems; i++)
	{
		items[i]->Update();
	}
	m_FrameCount++;
}

void Game::Render()
{
	SDL_RenderClear(m_Renderer);
	/* Render here */
	if (m_FrameCount % 60 == 0)
	{
		if (index < m_NumberOfItems - 1)
		{
			index++;
		}
		else
		{
			index = 0;
		}
	}
	items[index]->Render();
	SDL_RenderPresent(m_Renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
	SDL_Quit();

	std::cout << "[LOG]: Application Deconstructed..." << std::endl;
}
