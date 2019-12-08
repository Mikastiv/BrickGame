#include "Brick.h"

Brick::Brick(const Rectf& pRect, Color pC)
	: boxCollider(pRect), c(pC)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) gfx.DrawRect(boxCollider.ExpendedRect(-padding), c);
}

bool Brick::DoBallCollision(Ball& ball)
{
	Rectf ballCollider = ball.GetBoxCollider();
	if (!destroyed && boxCollider.IsOverlapping(ballCollider))
	{
		ball.BounceY();
		destroyed = true;
		return true;
	}
	return false;
}
