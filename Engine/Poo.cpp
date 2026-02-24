#include "Poo.h"

void Poo::Initialize(const float x, const float y, const float vx, const float vy)
{
	center.Initialize(x, y);
	speed.Initialize(vx, vy);
}

void Poo::Render(Graphics& gfx) const
{
	gfx.DrawCircle(center.GetX(), center.GetY(), radius, {139, 69, 19});
}

void Poo::Move(const float dt)
{
	ClampX();
	ClampY();
	center.Shift({speed.GetX() * dt, speed.GetY() * dt});
}


void Poo::ClampX()
{
	if (center.GetX() + speed.GetX() - radius < 0 || center.GetX() + radius + speed.GetX() > Graphics::ScreenWidth) {
		speed.InvertX();
	}
}

void Poo::ClampY()
{
	if (center.GetY() + speed.GetY() - radius < 0 || center.GetY() + radius  + speed.GetY() > Graphics::ScreenHeight) {
		speed.InvertY();
	}
}

const Position& Poo::GetCenter() const
{
	return center;
}

const Position& Poo::GetSpeed() const
{
	return speed;
}
