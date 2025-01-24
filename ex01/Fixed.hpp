#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
 private:

    int numberValue;
    static const int fractionalBits = 8;

public:

    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    ~Fixed();

    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed& other);

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif