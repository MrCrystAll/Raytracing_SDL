#pragma once

#include <Raytracing/Raytracing.h>

class Shape {
public:
	Shape(float x, float y);
	virtual void Draw(SDL_Renderer* renderer) = 0;
protected:
	float x, y;
};
