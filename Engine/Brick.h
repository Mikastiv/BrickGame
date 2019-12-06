#pragma once

#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
private:
	Rectf position;
	Color c;

public:
	Brick() = default;
	Brick(const Rectf& pRect, Color pC);
	void Draw(Graphics& gfx);
};