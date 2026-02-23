#pragma once
#include "Poo.h"
#include "Dude.h"
class Manager {
public:
	Manager();
	void Move(const Position& direction);
	void RenderPoos(Graphics& gfx);
private:
	void InitializePoos();
	void MovePoos();
	void CheckDudeCollision();
	static constexpr int poosAmount = 20;
	Poo poos[poosAmount];
	Dude dude;
	bool gameOver = false;
};