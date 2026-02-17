#pragma once
class Position {
public:
	void Initialize(const float x, const float y);
	void Shift(const Position& position);
	void Copy(const Position& position);
	float GetX() const;
	float GetY() const;
	void InvertX();
	void InvertY();
private:
	float x;
	float y;
};
