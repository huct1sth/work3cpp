
#include "Point.hpp"
namespace adas
{
Point::Point(const int x, const int y) noexcept : x(x), y(y)
{
}
Point::Point(const Point& point) noexcept
{
    x = point.x;
    y = point.y;
}
Point& Point::operator=(const Point& point) noexcept
{
    x = point.x;
    y = point.y;
    return *this;
}
Point& Point::operator+=(const Point& point) noexcept
{
    x += point.x;
    y += point.y;
    return *this;
}
Point& Point::operator-=(const Point& point) noexcept
{
    x -= point.x;
    y -= point.y;
    return *this;
}
int Point::GetX(void) const noexcept
{
    return x;
}
int Point::GetY(void) const noexcept
{
    return y;
}
}
