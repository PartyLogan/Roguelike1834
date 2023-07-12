#include "Renderer.h"
#include "../entities/Actor.h"

void Renderer::DrawTile()
{
}

void Renderer::DrawMap(int x, int y, int tileSize, Texture tileMap, std::shared_ptr<Map> map, std::shared_ptr<Actor> player)
{
}

void Renderer::DrawActors(int x, int y, int tileSize, Texture tileMap, std::vector<std::shared_ptr<Actor>> actors, std::shared_ptr<Actor> player)
{
}

void Renderer::DrawSprite(int x, int y, Texture tileMap, Rectangle source, Vector2 pos, int tileSize, Color fg, Color bg)
{
}

void Renderer::DrawEntity()
{
}
