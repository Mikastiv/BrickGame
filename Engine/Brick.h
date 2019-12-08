#pragma once

#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
private:
	static constexpr int padding = 1;

	Rectf boxCollider;
	Color c;
	bool destroyed = false;

public:
	Brick() = default;
	Brick(const Rectf& pRect, Color pC);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);

};