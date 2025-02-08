#include <Raytracing/Shapes/Rectangle.h>

Rectangle::Rectangle(float x, float y, float width, float height, bool fill): Shape(x, y), width(width), height(height), fill(fill)
{
}

void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_FRect dims = SDL_FRect{ x, y, width, height };
	if (this->fill) SDL_RenderFillRect(renderer, &dims);
	else  SDL_RenderRect(renderer, &dims);
}
