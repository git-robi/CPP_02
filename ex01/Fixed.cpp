/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:17:26 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:17:29 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : numberValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    
    this->numberValue = n << this->fractionalBits; 
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;

    int mult = 2;
    for (int i = 1; i < this->fractionalBits; i++)
        mult = mult * 2;
    this->numberValue = n * mult;
}

int Fixed::toInt( void ) const
{
    return ((int)this->numberValue >> this->fractionalBits);
}

float Fixed::toFloat( void ) const
{
    int div = 2;
    for (int i = 1; i < this->fractionalBits; i++)
        div = div * 2;
    
    return ((float)this->numberValue / div);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
     std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->numberValue = other.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits(void) const
{
 //   std::cout << "getRawBits member function called" << std::endl;
    return (this->numberValue);
}

void Fixed::setRawBits(int const raw)
{
    this->numberValue = raw;
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}
