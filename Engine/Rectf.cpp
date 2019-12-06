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
