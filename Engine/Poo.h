#pragma once
#include "Vec2D.h"
#include "Graphics.h"
class Poo {
public:
	void Initialize(const float x, const float y, const float vx, const float vy);
	Vec2D center;
	Vec2D speed;
	void Render(Graphics& gfx) const;
	void Move(const float dt);
	static constexpr int radius = 20;
private:
	void ClampX();
	void ClampY();
	const Vec2D& GetCenter() const;
	const Vec2D& GetSpeed() const;
};
