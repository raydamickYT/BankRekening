#pragma once


class Overload
{
public:
    float x, y;

    Overload(float x, float y) : x(x), y(y) {}
};

Overload operator+(const Overload& v1, const Overload& v2){
    return Overload(v1.x + v2.x, v1.y + v2.y);
}

Overload operator-(const Overload& v1, const Overload& v2){
    return Overload(v1.x - v2.x, v1.y - v2.y);
}

bool operator==(const Overload& v1, const Overload& v2){
    return (v1.x == v2.x, v1.y == v2.y);
}