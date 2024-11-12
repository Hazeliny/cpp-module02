/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:53:43 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 00:48:56 by linyao           ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &other) const {
	return (this->_fixedValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->_fixedValue < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->_fixedValue >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->_fixedValue <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->_fixedValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->_fixedValue != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedValue + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixedValue - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixedValue * other.getRawBits()) >> this->_fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixedValue << this->_fractionalBits) / other.getRawBits());
	return (result);
}

Fixed &Fixed::operator++(void) { // pre-increment
	this->_fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int) { // post-increment
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed &Fixed::operator--(void) { //pre-decrement
	this->_fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int) { //post-decrement
	Fixed tmp = *this;
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}	
