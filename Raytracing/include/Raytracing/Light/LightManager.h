#pragma once

#include <vector>
#include <Raytracing/Light/Light.h>

class LightManager {
public:
	LightManager(int nRays);
	LightManager(std::vector<Ray> rays);
	std::vector<Vector2D> Step(int nSteps);
protected:
	std::vector<Ray> rays;
};
