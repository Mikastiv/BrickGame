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
	Rectf(float pTop, float pLeft, float pBottom, float pRight);
	Rectf(const Vec2& pTopleft, const Vec2& pBottomRight);
	Rectf(const Vec2& pTopleft, float pWidth, float pHeight);
};