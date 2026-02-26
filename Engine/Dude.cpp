#include "Dude.h"

Dude::Dude(const Vec2D& center) :
	center(center)
{
}

const Vec2D& Dude::GetCenterPosition() const
{
	return center;
}

void Dude::Move(const Vec2D& mousePoint, const float dt)
{
	if (mousePoint.SqrdLength() != 0.0f) {
		center += ((mousePoint - center).Normalized() * (dt * speed));
		ClampX();
		ClampY();
	}
}

void Dude::ClampX() {
	const float XShift = (center.GetX() + radius > Graphics::ScreenWidth) ? -((radius + center.GetX()) - Graphics::ScreenWidth) : (center.GetX() - radius < 0) ? -(center.GetX() - radius) : 0;
	Vec2D XShiftPosition{ XShift, 0 };
	center += XShiftPosition;
}

void Dude::ClampY() {
	const float YShift = (center.GetY() + radius > Graphics::ScreenHeight) ? -((radius + center.GetY()) - Graphics::ScreenHeight) : (center.GetY() - radius < 0) ? -(center.GetY() - radius) : 0;
	Vec2D YShiftPosition{ 0, YShift };
	center += YShiftPosition;
}

void Dude::Render(Graphics& gfx) const
{
	gfx.DrawCircle(center.GetX(), center.GetY(), radius, Colors::Yellow);
}
