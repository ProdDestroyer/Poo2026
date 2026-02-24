#include "Dude.h"

Dude::Dude(const Position& center) :
	center(center)
{
}

const Position& Dude::GetCenterPosition() const
{
	return center;
}

void Dude::Move(const Position& direction, const float dt)
{
	center.Shift(Position{ dt * speed * direction.GetX(), dt * speed * direction.GetY() });
	ClampX();
	ClampY();
}

void Dude::ClampX() {
	const float XShift = (center.GetX() + radius > Graphics::ScreenWidth) ? -((radius + center.GetX()) - Graphics::ScreenWidth) : (center.GetX() - radius < 0) ? -(center.GetX() - radius) : 0;
	Position XShiftPosition{ XShift, 0 };
	center.Shift(XShiftPosition);
}

void Dude::ClampY() {
	const float YShift = (center.GetY() + radius > Graphics::ScreenHeight) ? -((radius + center.GetY()) - Graphics::ScreenHeight) : (center.GetY() - radius < 0) ? -(center.GetY() - radius) : 0;
	Position YShiftPosition{ 0, YShift };
	center.Shift(YShiftPosition);
}

void Dude::Render(Graphics& gfx) const
{
	gfx.DrawCircle(center.GetX(), center.GetY(), radius, Colors::Yellow);
}
