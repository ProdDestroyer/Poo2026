#include "Manager.h"
#include <random>

Manager::Manager()
{
	InitializePoos();
}

void Manager::Move()
{
	MovePoos();
}

void Manager::RenderPoos(Graphics& gfx)
{
	for (int i = 0; i < poosAmount; i++) {
		poos[i].Render(gfx);
	}
}

void Manager::InitializePoos()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float>  XDist(21.0f, Graphics::ScreenWidth - 21.0f);
	std::uniform_real_distribution<float>  YDist(21.0f, Graphics::ScreenHeight - 21.0f);
	std::uniform_real_distribution<float>  VDist(-1.0f, 1.0f);

	for (int i = 0; i < poosAmount; i++) {
		poos[i].Initialize(XDist(rng), YDist(rng), VDist(rng), VDist(rng));
	}
}

void Manager::MovePoos()
{
	for (int i = 0; i < poosAmount; i++) {
		poos[i].Move();
	}
}
