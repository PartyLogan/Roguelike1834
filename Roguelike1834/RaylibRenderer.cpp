#include "RaylibRenderer.h"

RaylibRenderer::RaylibRenderer()
{
}

void RaylibRenderer::DrawTile()
{
}

void RaylibRenderer::DrawMap(int x, int y, int tileSize, Texture tileMap ,std::shared_ptr<Map> map)
{
	for (int i = 0; i < map.get()->width; i++) {
		for (int j = 0; j < map.get()->height; j++) {
			Tile tile = map.get()->tiles[i][j];
			Vector2 tilePos = Tile::GetMapTile(tile.mapTile);
			Rectangle source = { tilePos.x * tileSize, tilePos.y * tileSize, tileSize, tileSize };
			Vector2 pos = { x + i * tileSize, y + j * tileSize };
			DrawTextureRec(tileMap, source, pos, tile.fg);

		}
	}
}

void RaylibRenderer::DrawEntity()
{
}
