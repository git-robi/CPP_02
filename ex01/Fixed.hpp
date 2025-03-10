/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:17:47 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:17:49 by rgiambon         ###   ########.fr       */
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

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);

#endif
