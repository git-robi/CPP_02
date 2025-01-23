#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
 private:

    int numberValue;
    static const int fractionalBits = 8;

public:

    Fixed();
    ~Fixed();

    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed& other);

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif