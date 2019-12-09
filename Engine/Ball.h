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

public:
	Ball(const Vec2& pCenter, const Vec2& pVelocity);
	void Draw(Graphics& gfx) const;
	void Update(float pDeltaTime);
	Rectf GetBoxCollider() const;
	bool DoWallCollision(const Rectf& pWalls);
	void BounceX();
	void BounceY();
	const Vec2& GetVelocity() const;
	const Vec2& GetCenter() const;
	void AddToPosition(const Vec2& v);
};