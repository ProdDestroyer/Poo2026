#pragma once
#include "Vec2D.h"
#include "Graphics.h"
class Dude {
public:
	Dude(const Vec2D& center);
	const Vec2D& GetCenterPosition() const;
	void Move(const Vec2D& mousePoint, const float dt);
	void Render(Graphics& gfx) const;
	static constexpr int radius = 15;
	static constexpr float speed = 60.0f;
private:
	Vec2D center;
	void ClampX();
	void ClampY();
};