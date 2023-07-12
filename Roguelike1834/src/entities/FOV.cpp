#include "FOV.h"
#include <cmath>

FOV::FOV()
{
	seen = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	visible = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
}

FOV::FOV(int width, int height)
{
	this->width = width;
	this->height = height;
	seen = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	visible = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
}

void FOV::Update(int x, int y, std::shared_ptr<Map> map)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
		{
			visible[i][j] = false;
		}
	}
	for (int i = -viewRange; i < viewRange; i++) {
		for (int j = -viewRange; j < viewRange; j++) {
			if (i * i + j * j < viewRange * viewRange)
			{
				LOS(x, y, x + i, y + j, map);
			}
		}
	}
}

void FOV::Resize(int width, int height)
{
	this->width = width;
	this->height = height;
	seen = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
	visible = std::vector<std::vector<bool>>(width, std::vector<bool>(height, false));
}

void FOV::UpdateFOV(int x, int y, std::shared_ptr<Map> map)
{
	Update(x, y, map);
	seen[x][y] = true;
	visible[x][y] = true;
}

void FOV::LOS(int x0, int y0, int x1, int y1, std::shared_ptr<Map> map)
{
	int sx = 0;
	int sy = 0;
	int xNext = 0;
	int yNext = 0;
	int dx = 0;
	int dy = 0;
	float dist = 0;

	dx = x1 - x0;
	dy = y1 - y0;

	//determine which quadrant to we're calculating: we climb in these two directions
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	
	xNext = x0;
	yNext = y0;

	// Calculate length of the line to cast
	dist = std::sqrt(dx * dx + dy * dy);

	while (xNext != x1 || yNext != y1) {
		// Casting a ray of length radius
		if (map.get()->InBounds(xNext, yNext)) {
			std::shared_ptr<Tile> tile = map.get()->GetTile(xNext, yNext);
			if (tile.get()->blocksVision) {
				visible[xNext][yNext] = true;
				seen[xNext][yNext] = true;
				return;
			}

			// Line-to-point distance formula < 0.5
			if (std::abs(dy * (xNext - x0 + sx) - dx * (yNext - y0)) / dist < 0.5) {
				xNext += sx;
			}
			else if (std::abs(dy * (xNext - x0) - dx * (yNext - y0 + sy)) / dist < 0.5) {
				yNext += sy;
			}
			else {
				xNext += sx;
				yNext += sy;
			}
		}
		visible[xNext][yNext] = true;
		seen[xNext][yNext] = true;
	}
}
