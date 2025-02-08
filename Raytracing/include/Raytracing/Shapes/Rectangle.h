#pragma once

#include <Raytracing/Shapes/Shape.h>

class Rectangle : public Shape {
public:
	Rectangle(float x, float y, float width, float height, bool fill);
	virtual void Draw(SDL_Renderer* renderer) override;
protected:
	float width, height;
	bool fill;
};
