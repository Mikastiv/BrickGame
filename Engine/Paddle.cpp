#include "Paddle.h"

Paddle::Paddle(Vec2 pCenter, float pWidth, float pHeight, float pSpeed)
	: center(pCenter), width(pWidth), height(pHeight), halfWidth(width / 2.0f), halfHeight(height / 2.0f), speed(pSpeed)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	float wingsWidth = width / 7.0f;
	gfx.DrawRect(GetRect(), c);
	gfx.DrawRect(Rectf(GetTopLeft() + Vec2(wingsWidth / 2.0f, 0.0f), wingsWidth, height), wingsColor);
	gfx.DrawRect(Rectf(GetTopRight() - Vec2(1.5f * wingsWidth, 0.0f), wingsWidth, height), wingsColor);
}

void Paddle::Update(const Keyboard& kbd, float deltatime)
{
	if (kbd.KeyIsPressed('A'))
	{
		center.x -= speed * deltatime;
	}
	else if (kbd.KeyIsPressed('D'))
	{
		center.x += speed * deltatime;
	}
}

Rectf Paddle::GetRect() const
{
	return Rectf::FromCenter(center, halfWidth, halfHeight);
}

Vec2 Paddle::GetTopLeft() const
{
	return Vec2(center.x - halfWidth, center.y - halfHeight);
}

Vec2 Paddle::GetTopRight() const
{
	return Vec2(center.x + halfWidth, center.y - halfHeight);
}

bool Paddle::DoWallCollision(const Rectf& walls)
{
	bool hasCollided = false;
	Rectf boxCollider = GetRect();

	if (boxCollider.left <= walls.left)
	{
		center.x += walls.left - boxCollider.left;
		hasCollided = true;
	}
	else if (boxCollider.right >= walls.right)
	{
		center.x -= boxCollider.right - walls.right;
		hasCollided = true;
	}

	return hasCollided;
}

bool Paddle::DoBallCollision(Ball& ball) const
{
	bool hasCollided = false;
	Rectf boxCollider = GetRect();

	if (ball.GetVelocity().y > 0.0f)
	{
		if (boxCollider.IsOverlapping(ball.GetBoxCollider()))
		{
			hasCollided = true;
			ball.BounceY();
		}
	}

	return hasCollided;
}
