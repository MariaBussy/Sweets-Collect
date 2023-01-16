#include "Game.h"
#include <iostream>
#include <vector>
#include "Map.h"
#include "Player.h"
#include "Sweets.h"

Map* map;

Player *player;

Sweets* sweets[3];

std::vector<Sweets*> collect;

Game::Game(): isRunning(false), window(nullptr), renderer(nullptr)
{
}

Game::~Game()
{
   delete player;
   for (int i = 0; i < 3; i++)
   {
	   /*for (int j = 0; j < 2; j++)
	   {
		   delete[] sweets[i][j];
	   }*/
		delete[] sweets[i];
   }
	//delete[] sweets;
}


void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialized" << std::endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window!=nullptr)
		{
			std::cout << "Window created" << std::endl;
		}
 
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	map = new Map(renderer);
   player = new Player ("assets/cupCake.png", renderer);
   player->init(0);


    sweets[0] = new Sweets("assets/lollipopFruitGreen.png", renderer, 2);
	sweets[1] = new Sweets("assets/lollipopFruitRed.png", renderer, 2);
	sweets[2] = new Sweets("assets/lollipopFruitYellow.png", renderer, 2);
   
   sweets[0]->init(0);
   sweets[1]->init(1);
   sweets[2]->init(2);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	default:
		break;
	}
}
void Game::update() const
{
	player->update(0);

	/*sweets[ord[0][0]]->update(ord[0][0]);
	sweets[ord[1][1]]->update(ord[1][1]);
	sweets[ord[2][2]]->update(ord[2][2]);*/
	
	sweets[0]->update(0);
	sweets[1]->update(1);
	sweets[2]->update(2);
	
}

void Game::render() const
{
	SDL_RenderClear(renderer);
	// this is where we would add stuff to render
	map->DrawMap();

	player->draw();

	sweets[0]->draw();
	sweets[1]->draw();
	sweets[2]->draw();

	SDL_RenderPresent(renderer);
}

void Game::clean() const
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_QUIT;
	std::cout << "Game cleaned" << std::endl;
}
