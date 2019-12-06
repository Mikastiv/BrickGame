#include "Rectf.h"

Rectf::Rectf(float pTop, float pLeft, float pBottom, float pRight)
	: top(pTop), left(pLeft), bottom(pBottom), right(pRight)
{
}

Rectf::Rectf(const Vec2& pTopleft, const Vec2& pBottomRight)
	: Rectf(pTopleft.y, pTopleft.x, pTopleft.y, pTopleft.x)
{
}

Rectf::Rectf(const Vec2& pTopleft, float pWidth, float pHeight)
	: Rectf(pTopleft, pTopleft + Vec2(pWidth, pHeight))
{
}
