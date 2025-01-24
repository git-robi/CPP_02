#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:

    Fixed const x;
    Fixed const y;

    public:

    Point();
    ~Point();

    Point(float const one, float const two);
    Point(Point const& other);
    Point& operator=(Point const& other);

    Fixed const &getX(void) const;
	Fixed const &getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif