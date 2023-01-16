#pragma once
#include "Component.h"
#include "SDL.h"

class Sweets : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};
	int rep;

public:
	Sweets() = default;
	Sweets(const char* path, SDL_Renderer* renderer, int r);

	void setTex(const char* path);

	void init(int x) override;

	void update(int x) override;

	void draw() override; 

	void multipleupdate(int x);
};