#pragma once
class Vec2D {
public:
	Vec2D() = default;
	Vec2D(const float x, const float y);
	Vec2D operator +(const Vec2D& rhs) const;
	Vec2D& operator +=(const Vec2D& rhs);
	Vec2D operator *(const float scale) const;
	Vec2D& operator *=(const float scale);
	Vec2D operator -(const Vec2D& rhs) const;
	Vec2D& operator -=(const Vec2D& rhs);
	Vec2D Normalize() const;
	Vec2D& Normalized();
	float SqrdLength() const;
	float Length() const;
	float GetX() const;
	float GetY() const;
private:
	float y;
	float x;
};