#pragma once

#include "Vec2.h"

class Rectf
{
public:
	float top;
	float left;
	float bottom;
	float right;

public:
	Rectf() = default;
	Rectf(float pLeft, float pTop, float pRight, float pBottom);
	Rectf(const Vec2& pTopleft, const Vec2& pBottomRight);
	Rectf(const Vec2& pTopleft, float pWidth, float pHeight);
};