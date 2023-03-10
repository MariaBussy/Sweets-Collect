#pragma once
#include "Component.h"
#include "SDL.h"

class Player : public Component
{
	SDL_Texture* texture{};
	SDL_Renderer* renderer{};
	SDL_Rect srcRect{}, destRect{};

public:
   Player() = default;
   Player(const char* path, SDL_Renderer* renderer);

	void setTex(const char* path);

	void init(int x) override;

	void update(int x) override;

	void draw() override;
};
