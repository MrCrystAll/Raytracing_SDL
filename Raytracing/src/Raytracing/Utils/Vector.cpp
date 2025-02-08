#include <Raytracing/Utils/Vector.h>
#include <cmath>

Vector2D::Vector2D() : Vector2D(0, 0) {};

Vector2D::Vector2D(float x, float y): x(x), y(y)
{
}

float Vector2D::Magnitude() const
{
	return (float)std::sqrt( std::pow(this->x, 2) + std::pow(this->y, 2) );
}

float Vector2D::Dist(Vector2D other) const
{
	return (*this - other).Magnitude();
}

void Vector2D::operator-=(Vector2D v2)
{
	this->x -= v2.x;
	this->y -= v2.y;
}

void Vector2D::operator+=(Vector2D v2)
{
	this->x += v2.x;
	this->y += v2.y;
}

void Vector2D::operator*=(float scaleFactor)
{
	this->x *= scaleFactor;
	this->y *= scaleFactor;
}

void Vector2D::operator/=(float scaleFactor)
{
	this->x /= scaleFactor;
	this->y /= scaleFactor;
}

float Vector2D::Dot(Vector2D other) const
{
	return this->x * other.x + this->y * other.y;
}

Vector2D operator-(Vector2D v1, Vector2D v2)
{
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}

Vector2D operator+(Vector2D v1, Vector2D v2)
{
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D operator*(Vector2D v, float scaleFactor)
{
	return Vector2D(v.x * scaleFactor, v.y * scaleFactor);
}

Vector2D operator/(Vector2D v, float scaleFactor)
{
	return Vector2D(v.x / scaleFactor, v.y / scaleFactor);
}

float Vector2D::GetX() const {
	return this->x;
}

float Vector2D::GetY() const {
	return this->y;
}
