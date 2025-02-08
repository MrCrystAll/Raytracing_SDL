#include <Raytracing/Light/Light.h>
#include <Raytracing/Raytracing.h>

Ray::Ray() : Ray(Vector2D(1, 0), Vector2D(0, 0), 1.0f) {};

Ray::Ray(Vector2D position, Vector2D direction, float refractionIndex): direction(direction), position(position), refractionIndex(refractionIndex)
{
}

void Ray::Step(float timestep)
{
	if (this->position.GetX() > 500) {
		this->Reflect(Vector2D(-1, 0));
	}
	Vector2D displacement = this->direction * timestep / this->refractionIndex;
	this->position += displacement;
}

void Ray::Reflect(Vector2D normal) {
	Vector2D displacement = normal * 2 * this->direction.Dot(normal);

	this->direction -= displacement;
}

Vector2D Ray::GetPosition() const 
{
	return this->position;
}
