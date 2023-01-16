#include "Player.h"
#include "TextureManager.h"

Player::Player(const char* path, SDL_Renderer* renderer): renderer(renderer)
{
   setTex(path);
}

void Player::setTex(const char* path)
{
   texture = TextureManager::LoadTexture(path, renderer);
}


void Player::init(int x)
{
   srcRect.x = 219;
   srcRect.y = 419;

   destRect.x = 219;
   destRect.y = 419;
   destRect.w = destRect.h = 64;
}

void Player::update(int x)
{
   destRect.x++;
   //destRect.y++;;
}


void Player::draw()
{
   TextureManager::Draw(texture, srcRect, destRect, renderer);
}