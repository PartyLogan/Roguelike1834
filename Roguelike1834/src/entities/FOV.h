#pragma once
#include <vector>
#include <memory>
#include "../maps/Map.h"
class FOV
{
public:
	int width = 80;
	int height = 50;
	int viewRange = 10;
	std::vector<std::vector<bool>> seen;
	std::vector<std::vector<bool>> visible;

	FOV();
	FOV(int width, int height);

	void UpdateFOV(int x, int y, std::shared_ptr<Map> map);

	void Resize(int width, int height);
private:

	void Update(int x, int y, std::shared_ptr<Map> map);
	void LOS(int x0, int y0, int x1, int y1, std::shared_ptr<Map> map);

};

