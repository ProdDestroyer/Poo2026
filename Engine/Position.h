#pragma once
class Position {
public:
	Position() = default; 
	Position(const float x, const float y);
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
