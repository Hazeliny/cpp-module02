/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:53:43 by linyao            #+#    #+#             */
/*   Updated: 2024/11/12 23:24:48 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(float const floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(floatValue * (1 << this->_fractionalBits)); // 左移8位，再取整
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits( int const raw ) {
//	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(this->_fixedValue) / static_cast<float>(1 << this->_fractionalBits));
}

int Fixed::toInt( void ) const {
	return (this->_fixedValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

