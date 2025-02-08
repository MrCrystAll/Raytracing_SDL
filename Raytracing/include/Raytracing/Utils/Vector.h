#pragma once

class Vector2D {
public:
	Vector2D();
	Vector2D(float x, float y);

	float Magnitude() const;
	float Dist(Vector2D other) const;

	friend Vector2D operator -(Vector2D v1, Vector2D v2);
	friend Vector2D operator +(Vector2D v1, Vector2D v2);

	void operator -=(Vector2D v2);
	void operator +=(Vector2D v2);
	void operator *=(float scaleFactor);
	void operator /=(float scaleFactor);

	friend Vector2D operator *(Vector2D v, float scaleFactor);
	friend Vector2D operator /(Vector2D v, float scaleFactor);

	float Dot(Vector2D other) const;

	float GetX() const;
	float GetY() const;
protected:
	float x, y;
};
