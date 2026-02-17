#pragma once
#include "Poo.h"
class Manager {
public:
	Manager();
	void Move();
	void RenderPoos(Graphics& gfx);
private:
	void InitializePoos();
	void MovePoos();
	static constexpr int poosAmount = 20;
	Poo poos[poosAmount];
};