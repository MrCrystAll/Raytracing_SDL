#pragma once

#include <Raytracing/Utils/Vector.h>

class Ray
{
public:
	Ray();
	Ray(Vector2D position, Vector2D direction, float refractionIndex);
	void Step(float timestep);
	void Reflect(Vector2D normal);

	Vector2D GetPosition() const;
protected:
	Vector2D direction, position;
	float refractionIndex;
};
