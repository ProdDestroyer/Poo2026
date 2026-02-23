#include "Position.h"

Position::Position(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

void Position::Initialize(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

void Position::Shift(const Position& position)
{
	this->x += position.GetX();
	this->y += position.GetY();
}

void Position::Copy(const Position& position)
{
	this->x = position.GetX();
	this->y = position.GetY();
}

float Position::GetX() const
{
	return x;
}

float Position::GetY() const
{
	return y;
}

void Position::InvertX()
{
	x *= -1;
}

void Position::InvertY()
{
	y *= -1;
}
