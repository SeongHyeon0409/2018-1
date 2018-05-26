#include "MyLineSegment.h"
// constructors
MyLineSegment::MyLineSegment ()
: p1(0,0), p2(0,0)
{
}
MyLineSegment::MyLineSegment (const MyPoint& p, const MyPoint& q)
: p1(p), p2(q)
{
}
MyLineSegment::MyLineSegment (const MyLineSegment& s)
: p1(s.p1), p2(s.p2)
{
}
// 점 p 가 삼각형의 꼭지점에 위치하는 지를 검사
bool MyLineSegment::isEndOfSegment(const MyPoint & p) const
{
 if(p == p1 || p == p2)
 return true;
 else
 return false;
}
// 점 p 가 삼각형의 꼭지점을 제외한 삼각형의 변 위에 위치하는 지를 검사
bool MyLineSegment::isOnSegment(const MyPoint& p) const
{
     if (isEndOfSegment(p))
        return false;
    else {
        if ((p2.getX() - p1.getX())*(p.getY() - p1.getY()) == (p.getX() - p1.getX())*(p2.getY() -p1.getY()))
            return true;
        else
            return false;
    }
}
bool MyLineSegment::properIntersection(const MyLineSegment &s) const 
{
    if ((isLeftSide(s.p1) && getArea2(s.p2)<0) || (isLeftSide(s.p2) && getArea2(s.p1)<0)) {
        if ((s.isLeftSide(p1) && s.getArea2(p2)<0) || (s.isLeftSide(p2) && s.getArea2(p1)<0)) {
            return true;
        }
        else {
            return false;
        }
    }
    else
        return false;

}
bool MyLineSegment::improperIntersection(const MyLineSegment &s) const
{
    if (isEndOfSegment(s.p1) || isEndOfSegment(s.p2) || isOnSegment(s.p1) || isOnSegment(s.p2)
        || s.isEndOfSegment(p1) || s.isEndOfSegment(p2) || s.isOnSegment(p1) || s.isOnSegment(p2)
        ||isCollinear(s.p1)||isCollinear(s.p2)||s.isCollinear(p1)||s.isCollinear(p2))
        return true;
    else
        return false;
}
// square of (Euclidean) length
int MyLineSegment::length2sqr() const
{
 return p1.dist2sqr(p2);
}
// signed area of triangle p1, p2, p
int MyLineSegment::getArea2(const MyPoint &p) const // signed area of triangle p1, p2, p
{
 int p1x, p2x, px, p1y, p2y, py;
 p1x = p1.getX();
 p1y = p1.getY();
 p2x = p2.getX();
 p2y = p2.getY();
 px = p.getX();
 py = p.getY();
 return p1x * p2y - p1y * p2x +
 p1y * px - p1x * py +
 p2x * py - px * p2y;
}
// test whether p is to the left side of the direction from p1 to p2
bool MyLineSegment::isLeftSide(const MyPoint &p) const
{
 return getArea2(p) > 0;
}
// test whether p1, p2, p3 is collinear
bool MyLineSegment::isCollinear(const MyPoint &p) const
{
 return getArea2(p) == 0;
} 