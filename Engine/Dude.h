#pragma once
#include "Position.h"
#include "Graphics.h"
class Dude {
public:
	Dude(const Position& center);
	const Position& GetCenterPosition() const;
	void Move(const Position& direction);
	void Render(Graphics& gfx) const;
	static constexpr int radius = 15;
	static constexpr float speed = 1.0f;
private:
	Position center;
	void ClampX();
	void ClampY();
};