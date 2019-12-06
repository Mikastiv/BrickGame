#include "Brick.h"

Brick::Brick(const Rectf& pRect, Color pC)
	: position(pRect), c(pC)
{
}

void Brick::Draw(Graphics& gfx)
{
	gfx.DrawRect(position, c);
}
