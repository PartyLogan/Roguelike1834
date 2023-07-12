#include "RaylibRenderer.h"

RaylibRenderer::RaylibRenderer()
{
}

void RaylibRenderer::DrawTile()
{
}

void RaylibRenderer::DrawMap(int x, int y, int tileSize, Texture tileMap ,std::shared_ptr<Map> map)
{
	Vector2 bgPos = Tile::GetMapTile(Tile::Background);
	Rectangle bgSource = { bgPos.x * tileSize, bgPos.y * tileSize, tileSize, tileSize };

	for (int i = 0; i < map.get()->width; i++) {
		for (int j = 0; j < map.get()->height; j++) {
			std::shared_ptr<Tile> tile = map.get()->tiles[i][j];
			// Position of the tile in the tile map
			Vector2 tilePos = Tile::GetMapTile(tile.get()->mapTile);
			// Rectangle of the image to draw
			Rectangle source = { tilePos.x * tileSize, tilePos.y * tileSize, tileSize, tileSize };
			// Position on the map to draw
			Vector2 pos = { x + i * tileSize, y + j * tileSize };
			// Draw the BG
			DrawTextureRec(tileMap, bgSource, pos, tile.get()->bg);
			// Draw the FG
			DrawTextureRec(tileMap, source, pos, tile.get()->fg);
		}
	}
}

void RaylibRenderer::DrawActors(int x, int y, int tileSize, Texture tileMap, std::vector<std::shared_ptr<Actor>> actors)
{
	Vector2 bgPos = Tile::GetMapTile(Tile::Background);
	Rectangle bgSource = { bgPos.x * tileSize, bgPos.y * tileSize, tileSize, tileSize };

	for (int i = 0; i < actors.size(); i++) {
		std::shared_ptr<Actor> actor = actors[i];
		// Position of the tile in the tile map
		Vector2 tilePos = Tile::GetActorTile(actor.get()->tileType);
		// Rectangle of the image to draw
		Rectangle source = { tilePos.x * tileSize, tilePos.y * tileSize, tileSize, tileSize };
		// Position on the map to draw
		Vector2 pos = { x + actor.get()->x * tileSize, y + actor.get()->y * tileSize };
		// Draw the BG
		DrawTextureRec(tileMap, bgSource, pos, actor.get()->bg);
		// Draw the FG
		DrawTextureRec(tileMap, source, pos, actor.get()->fg);
	}
}

void RaylibRenderer::DrawEntity()
{
}
