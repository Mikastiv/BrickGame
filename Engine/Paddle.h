#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "Ball.h"

class Paddle
{
private:
	Vec2 center;
	float width;
	float height;
	float halfWidth;
	float halfHeight;
	float speed;
	Color c = Colors::White;
	Color wingsColor = Colors::Red;

public:
	Paddle(Vec2 pCenter, float pWidth, float pHeight, float pSpeed);
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd, float deltatime);
	Rectf GetRect() const;
	bool DoWallCollision(const Rectf& walls);
	bool DoBallCollision(Ball& ball) const;
	void SetPosition(float x);

private:
	Vec2 GetTopLeft() const;
	Vec2 GetTopRight() const;
};