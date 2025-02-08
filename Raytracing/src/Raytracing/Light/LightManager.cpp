#include <Raytracing/Light/LightManager.h>
#include <Raytracing/Raytracing.h>

LightManager::LightManager(int nRays)
{
	this->rays = std::vector<Ray>(nRays);
}

LightManager::LightManager(std::vector<Ray> rays) {
	this->rays = rays;
}

std::vector<Vector2D> LightManager::Step(int nSteps) {
	std::vector<Vector2D> positions = std::vector<Vector2D>();

	for (Ray& r : this->rays) {
		r.Step(nSteps);
		positions.push_back(r.GetPosition());
	}

	return positions;
}
