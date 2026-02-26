#include "Poo.h"

void Poo::Initialize(const float x, const float y, const float vx, const float vy)
{
	center = Vec2D(x, y);
	speed = Vec2D(vx, vy);
}

void Poo::Render(Graphics& gfx) const
{
	gfx.DrawCircle(center.GetX(), center.GetY(), radius, {139, 69, 19});
}

void Poo::Move(const float dt)
{
	ClampX();
	ClampY();
	center += speed * dt;
}


void Poo::ClampX()
{
	if (center.GetX() + speed.GetX() - radius < 0 || center.GetX() + radius + speed.GetX() > Graphics::ScreenWidth) {
		speed = Vec2D(-speed.GetX(), speed.GetY());
	}
}

void Poo::ClampY()
{
	if (center.GetY() + speed.GetY() - radius < 0 || center.GetY() + radius  + speed.GetY() > Graphics::ScreenHeight) {
		speed = Vec2D(speed.GetX(), -speed.GetY());
	}
}

const Vec2D& Poo::GetCenter() const
{
	return center;
}

const Vec2D& Poo::GetSpeed() const
{
	return speed;
}
