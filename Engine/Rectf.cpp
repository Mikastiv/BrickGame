#include "Rectf.h"
#include <assert.h>

Rectf::Rectf(float pLeft, float pTop, float pRight, float pBottom)
	: top(pTop), left(pLeft), bottom(pBottom), right(pRight)
{
	assert(top < bottom);
	assert(left < right);
}

Rectf::Rectf(const Vec2& pTopleft, const Vec2& pBottomRight)
	: Rectf(pTopleft.x, pTopleft.y, pBottomRight.x, pBottomRight.y)
{
}

Rectf::Rectf(const Vec2& pTopleft, float pWidth, float pHeight)
	: Rectf(pTopleft, pTopleft + Vec2(pWidth, pHeight))
{
}

bool Rectf::IsOverlapping(const Rectf& other) const
{
	return left <= other.right && right >= other.left && top <= other.bottom && bottom >= other.top;
}

Rectf Rectf::GetExpendedRect(float padding) const
{
	return Rectf(left - padding, top - padding, right + padding, bottom + padding);
}

Vec2 Rectf::GetCenterPosition() const
{
	return Vec2((left + right) / 2.0f, (top + bottom) / 2.0f);
}

Vec2 Rectf::VecToPushOutsideRectY(const Rectf& rect) const
{
	if (rect.top <= top)
	{
		return Vec2(0.0f, rect.bottom - top);
	}
	else if (rect.bottom >= bottom)
	{
		return Vec2(0.0f, bottom - rect.top);
	}

	return Vec2(0.0f, 0.0f);
}

Vec2 Rectf::VecToPushOutsideRectX(const Rectf& rect) const
{
	if (rect.left <= left)
	{
		return Vec2(rect.right - left, 0.0f);
	}
	else if (rect.right >= right)
	{
		return Vec2(right - rect.left, 0.0f);
	}

	return Vec2(0.0f, 0.0f);
}

Rectf Rectf::FromCenter(Vec2 center, float halfWidth, float halfHeight)
{
	return Rectf(Vec2(center.x - halfWidth, center.y - halfHeight), Vec2(center.x + halfWidth, center.y + halfHeight));
}
