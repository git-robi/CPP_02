/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:18:29 by rgiambon          #+#    #+#             */
/*   Updated: 2025/03/10 11:18:33 by rgiambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
