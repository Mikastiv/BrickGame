#pragma once

#include "Vec2.h"
#include "Rectf.h"
#include "Graphics.h"

class Ball
{
private:
	static constexpr float radius = 7.0f;
	Vec2 center;
	Vec2 velocity;
	Rectf boxCollider;

public:
	Ball(const Vec2& pCenter, const Vec2& pVelocity);
	void Draw(Graphics& gfx) const;
	void Update(float pDeltaTime);
};