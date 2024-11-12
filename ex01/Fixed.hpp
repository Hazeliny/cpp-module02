/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:34:24 by linyao            #+#    #+#             */
/*   Updated: 2024/11/12 16:17:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _fixedValue;
		static const int _fractionalBits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

