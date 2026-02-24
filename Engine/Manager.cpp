#include "Manager.h"
#include <random>

Manager::Manager() :
	dude({ Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2 })
{
	InitializePoos();
}

void Manager::Move(const Position& direction, const float dt)
{
	if (!gameOver) {
		MovePoos(dt);
		dude.Move(direction, dt);
		CheckDudeCollision();
	}
}

void Manager::RenderPoos(Graphics& gfx)
{
	for (int i = 0; i < poosAmount; i++) {
		poos[i].Render(gfx);
	}
	dude.Render(gfx);
}

void Manager::InitializePoos()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float>  XDist(21.0f, Graphics::ScreenWidth - 21.0f);
	std::uniform_real_distribution<float>  YDist(21.0f, Graphics::ScreenHeight - 21.0f);
	std::uniform_real_distribution<float>  VDist(-1.0f, 1.0f);

	for (int i = 0; i < poosAmount; i++) {
		poos[i].Initialize(XDist(rng), YDist(rng), VDist(rng) * 60.0f, VDist(rng) * 60.0f);
	}
}

void Manager::MovePoos(const float dt)
{
	for (int i = 0; i < poosAmount; i++) {
		poos[i].Move(dt);
	}
}

void Manager::CheckDudeCollision()
{
	bool notColliding = true;
	float collisionXDistance = 0;
	float collisionYDistance = 0;
	float distanceSquare = (Poo::radius + Dude::radius) * (Poo::radius + Dude::radius);
	for (int i = 0; i < poosAmount; i++) {
		collisionXDistance = dude.GetCenterPosition().GetX() - poos[i].center.GetX();
		collisionYDistance = dude.GetCenterPosition().GetY() - poos[i].center.GetY();
		notColliding = notColliding && !((collisionXDistance * collisionXDistance) + (collisionYDistance * collisionYDistance) < distanceSquare);
	}

	gameOver = !notColliding;
}
