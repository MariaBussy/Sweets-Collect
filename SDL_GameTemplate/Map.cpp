#include "Map.h"
#include "TextureManager.h"
#include <SDL.h>

int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0},

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

Map::Map(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	dirt = TextureManager::LoadTexture("assets/cakeCenter.png", renderer);
	frosting = TextureManager::LoadTexture("assets/frosting.png", renderer);
	top = TextureManager::LoadTexture("assets/cakeHalfAltMid.png", renderer);
	sky = TextureManager::LoadTexture("assets/Sky.png", renderer);
	cloud = TextureManager::LoadTexture("assets/cloud2.png", renderer);

	LoadMap(lvl1);

	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;
	dest.x = 0;
	dest.y = 0;
	dest.w = 32;
	dest.h = 32;

}

Map::~Map()
{

}

void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;
			switch (type)
			{
			case 0:
				{
				TextureManager::Draw(sky, src, dest, renderer);
					break;
				}
			case 1:
			{
				TextureManager::Draw(top, src, dest, renderer);
				break;
			}
			case 2:
			{
				TextureManager::Draw(dirt, src, dest, renderer);
				break;
			}
			case 3:
			{
				TextureManager::Draw(frosting, src, dest, renderer);
				break;
			}
			case 4:
			{
				TextureManager::Draw(cloud, src, dest, renderer);
				break;
			}
			default:
				break;
			}
		}
	}
}
