/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:19:57 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:20:41 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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
    this->numberValue = roundf(n * (1 << this->fractionalBits));
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

bool Fixed::operator>(const Fixed& other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+(Fixed const &other) const 
{
	Fixed	ret;
	ret.setRawBits(getRawBits() + other.getRawBits());
	return ret;
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	ret;
	ret.setRawBits(getRawBits() - other.getRawBits());
	return ret;
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	ret;
	long temp = (long)this->getRawBits() * (long)other.getRawBits();
	ret.setRawBits((temp >> this->fractionalBits));
	return ret;
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	ret;
	ret.setRawBits(getRawBits() / other.getRawBits() << this->fractionalBits);
	return ret;
}

Fixed &Fixed::operator++()
{
    this->numberValue += 1;
    return *this;        
}

Fixed &Fixed::operator--()
{
    this->numberValue -= 1;
    return *this;        
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;  
    this->numberValue += 1; 
    return temp;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this; 
    this->numberValue -= 1;
    return temp;
}


int Fixed::getRawBits(void) const
{
    return (this->numberValue);
}

void Fixed::setRawBits(int const raw)
{
    this->numberValue = raw;
}

std::ostream& operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
    if (one < two)
        return (one);
    return (two);
}

Fixed const &Fixed::min(const Fixed& one, const Fixed& two)
{
    if (one < two)
        return (one);
    return (two);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    if (one > two)
        return (one);
    return (two);
}

Fixed const &Fixed::max(const Fixed& one, const Fixed& two)
{
    if (one > two)
        return (one);
    return (two);
}
