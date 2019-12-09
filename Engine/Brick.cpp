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
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballCenter - GetCenterPosition()).x))
	{
		ball.BounceY();
		PushBallOutsideBrickY(ball);
	}
	else if (ballCenter.x >= boxCollider.left && ballCenter.x <= boxCollider.right)
	{
		ball.BounceY();
		PushBallOutsideBrickY(ball);
	}
	else
	{
		ball.BounceX();
		PushBallOutsideBrickX(ball);
	}
	destroyed = true;
}

Vec2 Brick::GetCenterPosition() const
{
	return boxCollider.GetCenterPosition();
}

void Brick::PushBallOutsideBrickY(Ball& ball) const
{
	assert(!destroyed);
	assert(boxCollider.IsOverlapping(ball.GetBoxCollider()));

	const Rectf ballCollider = ball.GetBoxCollider();
	if (ballCollider.top <= boxCollider.top)
	{
		ball.AddToPosition(Vec2(0.0f, ballCollider.bottom - boxCollider.top));
	}
	else if (ballCollider.bottom >= boxCollider.bottom)
	{
		ball.AddToPosition(Vec2(0.0f, boxCollider.bottom - ballCollider.top));
	}
}

void Brick::PushBallOutsideBrickX(Ball& ball) const
{
	assert(!destroyed);
	assert(boxCollider.IsOverlapping(ball.GetBoxCollider()));

	const Rectf ballCollider = ball.GetBoxCollider();
	if (ballCollider.left <= boxCollider.left)
	{
		ball.AddToPosition(Vec2(ballCollider.left - boxCollider.left, 0.0f));
	}
	else
	{
		ball.AddToPosition(Vec2(boxCollider.right - ballCollider.right, 0.0f));
	}
}
