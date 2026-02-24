#pragma once
#include "Position.h"
#include "Graphics.h"
class Poo {
public:
	void Initialize(const float x, const float y, const float vx, const float vy);
	Position center;
	Position speed;
	void Render(Graphics& gfx) const;
	void Move(const float dt);
	static constexpr int radius = 20;
private:
	void ClampX();
	void ClampY();
	const Position& GetCenter() const;
	const Position& GetSpeed() const;
};
