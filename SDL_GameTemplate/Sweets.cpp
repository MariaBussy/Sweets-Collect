#include "Sweets.h"
#include "TextureManager.h"

Sweets::Sweets(const char* path, SDL_Renderer* renderer, int r) : renderer(renderer)
{
	setTex(path);
	rep = r;
}

void Sweets::setTex(const char* path)
{
	texture = TextureManager::LoadTexture(path, renderer);
}


void Sweets::init(int x)
{
	switch (x)
	{
		case 0:
		{
			srcRect.x = 79;
			srcRect.y = 100;

			destRect.x = 79;
			destRect.y = 100;

			break;
		}
		case 1:
		{
			srcRect.x = 319;
			srcRect.y = 200;

			destRect.x = 319;
			destRect.y = 200;

			break;
		}
		case 2:
		{
			srcRect.x = 619;
			srcRect.y = 150;

			destRect.x = 619;
			destRect.y = 150;

			break;
		}
		default:
			break;
	}

	destRect.w = destRect.h = 64;
}

void Sweets::update(int x)
{
	switch (x)
	{
		case 0:
		{
			destRect.y+=2;
			if (destRect.y == 220)
			{
				Sweets* NEW= new Sweets("assets/lollipopFruitGreen.png", renderer, 2);
				NEW->init(x);
				/*srcRect.x = 79;
				srcRect.y = 100;

				destRect.x = 79;
				destRect.y = 100;*/
				NEW->draw();

			}
			break;
		}
		case 1:
		{
			destRect.y+=6;
			break;
		}
		case 2:
		{
			destRect.y+=4;
			break;
		}
		default:
			break;
	}
}

void Sweets::multipleupdate(int x) 
{
	switch (x)
	{
	case 0:
	{
		destRect.y += 2;
		break;
	}
	case 1:
	{
		destRect.y += 6;
		break;
	}
	case 2:
	{
		destRect.y += 4;
		break;
	}
	default:
		break;
	}
}
void Sweets::draw()
{
	TextureManager::Draw(texture, srcRect, destRect, renderer);
}