////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
template <typename V>
Rect<V>::Rect() :
left  (0),
top   (0),
width (0),
height(0)
{

}


////////////////////////////////////////////////////////////
template <typename V>
Rect<V>::Rect(V rectLeft, V rectTop, V rectWidth, V rectHeight) :
left  (rectLeft),
top   (rectTop),
width (rectWidth),
height(rectHeight)
{

}


////////////////////////////////////////////////////////////
template <typename V>
Rect<V>::Rect(const Vector2<V>& position, const Vector2<V>& size) :
left  (position.x),
top   (position.y),
width (size.x),
height(size.y)
{

}


////////////////////////////////////////////////////////////
template <typename V>
template <typename U>
Rect<V>::Rect(const Rect<U>& rectangle) :
left  (static_cast<V>(rectangle.left)),
top   (static_cast<V>(rectangle.top)),
width (static_cast<V>(rectangle.width)),
height(static_cast<V>(rectangle.height))
{
}


////////////////////////////////////////////////////////////
template <typename V>
bool Rect<V>::contains(V x, V y) const
{
    // Rectangles with negative dimensions are allowed, so we must handle them correctly

    // Compute the real min and max of the rectangle on both axes
    V minX = std::min(left, static_cast<V>(left + width));
    V maxX = std::max(left, static_cast<V>(left + width));
    V minY = std::min(top, static_cast<V>(top + height));
    V maxY = std::max(top, static_cast<V>(top + height));

    return (x >= minX) && (x < maxX) && (y >= minY) && (y < maxY);
}


////////////////////////////////////////////////////////////
template <typename V>
bool Rect<V>::contains(const Vector2<V>& point) const
{
    return contains(point.x, point.y);
}


////////////////////////////////////////////////////////////
template <typename V>
bool Rect<V>::intersects(const Rect<V>& rectangle) const
{
    Rect<V> intersection;
    return intersects(rectangle, intersection);
}


////////////////////////////////////////////////////////////
template <typename V>
bool Rect<V>::intersects(const Rect<V>& rectangle, Rect<V>& intersection) const
{
    // Rectangles with negative dimensions are allowed, so we must handle them correctly

    // Compute the min and max of the first rectangle on both axes
    V r1MinX = std::min(left, static_cast<V>(left + width));
    V r1MaxX = std::max(left, static_cast<V>(left + width));
    V r1MinY = std::min(top, static_cast<V>(top + height));
    V r1MaxY = std::max(top, static_cast<V>(top + height));

    // Compute the min and max of the second rectangle on both axes
    V r2MinX = std::min(rectangle.left, static_cast<V>(rectangle.left + rectangle.width));
    V r2MaxX = std::max(rectangle.left, static_cast<V>(rectangle.left + rectangle.width));
    V r2MinY = std::min(rectangle.top, static_cast<V>(rectangle.top + rectangle.height));
    V r2MaxY = std::max(rectangle.top, static_cast<V>(rectangle.top + rectangle.height));

    // Compute the intersection boundaries
    V interLeft   = std::max(r1MinX, r2MinX);
    V interTop    = std::max(r1MinY, r2MinY);
    V interRight  = std::min(r1MaxX, r2MaxX);
    V interBottom = std::min(r1MaxY, r2MaxY);

    // If the intersection is valid (positive non zero area), then there is an intersection
    if ((interLeft < interRight) && (interTop < interBottom))
    {
        intersection = Rect<V>(interLeft, interTop, interRight - interLeft, interBottom - interTop);
        return true;
    }
    else
    {
        intersection = Rect<V>(0, 0, 0, 0);
        return false;
    }
}


////////////////////////////////////////////////////////////
template <typename V>
inline bool operator ==(const Rect<V>& left, const Rect<V>& right)
{
    return (left.left == right.left) && (left.width == right.width) &&
           (left.top == right.top) && (left.height == right.height);
}


////////////////////////////////////////////////////////////
template <typename V>
inline bool operator !=(const Rect<V>& left, const Rect<V>& right)
{
    return !(left == right);
}
