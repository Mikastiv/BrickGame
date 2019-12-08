#include "Rectf.h"

Rectf::Rectf(float pLeft, float pTop, float pRight, float pBottom)
	: top(pTop), left(pLeft), bottom(pBottom), right(pRight)
{
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

Rectf Rectf::ExpendedRect(float padding) const
{
	return Rectf(left - padding, top - padding, right + padding, bottom + padding);
}

Rectf Rectf::FromCenter(Vec2 center, float halfWidth, float halfHeight)
{
	return Rectf(Vec2(center.x - halfWidth, center.y - halfHeight), Vec2(center.x + halfWidth, center.y + halfHeight));
}
