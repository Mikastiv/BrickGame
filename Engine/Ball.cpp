#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pCenter, const Vec2& pVelocity)
	: center(pCenter), velocity(pVelocity)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

void Ball::Update(float pDeltaTime)
{
	center += velocity * pDeltaTime;
}

Rectf Ball::GetBoxCollider() const
{
	return Rectf(Vec2(center.x - radius, center.y - radius), Vec2(center.x + radius, center.y + radius));
}

bool Ball::DoWallCollision(const Rectf& pWalls)
{
	bool hasCollided = false;
	const Rectf boxCollider = GetBoxCollider();

	if (boxCollider.left <= pWalls.left)
	{
		BounceX();
		center.x += pWalls.left - boxCollider.left;
		hasCollided = true;
	}
	else if (boxCollider.right >= pWalls.right)
	{
		BounceX();
		center.x -= boxCollider.right - pWalls.right;
		hasCollided = true;
	}
	
	if (boxCollider.top <= pWalls.top)
	{
		BounceY();
		center.y += pWalls.top - boxCollider.top;
		hasCollided = true;
	}
	else if (boxCollider.bottom >= pWalls.bottom)
	{
		BounceY();
		center.y -= boxCollider.bottom - pWalls.bottom;
		hasCollided = true;
	}

	return hasCollided;
}

void Ball::BounceX()
{
	velocity.x = -velocity.x;
}

void Ball::BounceY()
{
	velocity.y = -velocity.y;
}

const Vec2& Ball::GetVelocity() const
{
	return velocity;
}

const Vec2& Ball::GetCenter() const
{
	return center;
}

void Ball::AddToPosition(const Vec2& v)
{
	center += v;
}
