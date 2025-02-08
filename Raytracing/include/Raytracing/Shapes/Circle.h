#pragma once

#include <Raytracing/Shapes/Shape.h>

class Circle : public Shape {
public:
	Circle(float x, float y, float radius, bool fill);
	virtual void Draw(SDL_Renderer* renderer) override;
protected:
	float radius;
	bool fill;
};
