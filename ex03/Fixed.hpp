/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:24:54 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:24:58 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;

    Fixed& operator++(); // Pre-increment
    Fixed& operator--(); // Pre-decrement
    Fixed operator++(int); // post-increment
    Fixed operator--(int); // post-decrement



    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;

    static Fixed& min(Fixed& one, Fixed& two);
    static const Fixed& min(const Fixed& one, const Fixed& two);

    static Fixed& max(Fixed& one, Fixed& two);
    static const Fixed& max(const Fixed& one, const Fixed& two);

};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif
