#include "Brick.h"
#include <assert.h>
#include <cmath>

Brick::Brick()
	: boxCollider(Rectf())
{
}

Brick::Brick(const Rectf& pRect, Color pC)
	: boxCollider(pRect), c(pC)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) gfx.DrawRect(boxCollider.GetExpendedRect(-padding), c);
}

bool Brick::CheckBallCollision(Ball& ball) const
{
	return !destroyed && boxCollider.IsOverlapping(ball.GetBoxCollider());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(!destroyed);
	assert(boxCollider.IsOverlapping(ball.GetBoxCollider()));

	const Vec2 ballCenter = ball.GetCenter();
	const Rectf ballCollider = ball.GetBoxCollider();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballCenter - GetCenterPosition()).x))
	{
		ball.BounceY();
		ball.AddToPosition(boxCollider.VecToPushOutsideRectY(ballCollider));
	}
	else if (ballCenter.x >= boxCollider.left && ballCenter.x <= boxCollider.right)
	{
		ball.BounceY();
		ball.AddToPosition(boxCollider.VecToPushOutsideRectY(ballCollider));
	}
	else
	{
		ball.BounceX();
		ball.AddToPosition(boxCollider.VecToPushOutsideRectX(ballCollider));
	}
	destroyed = true;
}

Vec2 Brick::GetCenterPosition() const
{
	return boxCollider.GetCenterPosition();
}
