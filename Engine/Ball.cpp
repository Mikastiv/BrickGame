#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pCenter, const Vec2& pVelocity)
	: center(pCenter), velocity(pVelocity), boxCollider(Vec2(center.x - radius, center.y - radius), Vec2(center.x + radius, center.y + radius))
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
