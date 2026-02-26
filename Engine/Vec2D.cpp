#include "Vec2D.h"
#include <cmath>

Vec2D::Vec2D(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

Vec2D Vec2D::operator+(const Vec2D& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Vec2D& Vec2D::operator+=(const Vec2D& rhs)
{
	return *this = *this + rhs;
}

Vec2D Vec2D::operator*(const float scale) const
{
	return { x * scale, y * scale };
}

Vec2D& Vec2D::operator*=(const float scale)
{
	return *this = *this * scale;
}

Vec2D Vec2D::operator-(const Vec2D& rhs) const
{
	return *this + (rhs * -1);
}

Vec2D& Vec2D::operator-=(const Vec2D& rhs)
{
	return *this = *this - rhs;
}

Vec2D Vec2D::Normalize() const
{
	return (SqrdLength() == 0.0f) ? *this : *this * (1/Length());
}

Vec2D& Vec2D::Normalized()
{
	return *this = Normalize();
}

float Vec2D::SqrdLength() const
{
	return (x * x) + (y * y);
}

float Vec2D::Length() const
{
	return std::sqrt(SqrdLength());
}

float Vec2D::GetX() const
{
	return x;
}

float Vec2D::GetY() const
{
	return y;
}
