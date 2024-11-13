/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:34:24 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 10:38:59 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _fixedValue;
		static const int _fractionalBits;
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
		bool operator>(const Fixed &other) const; // const在函数签名末尾,该函数不会修改调用该函数的对象（即this指针指向的对象）的成员变量
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++(void); // pre-increment 返回引用是前置递增通常直接操作当前对象返回递增后的对象本身，避免返回值的拷贝，提高效率，同时允许表达式链式操作
		Fixed operator++(int); // post-increment 先返回递增前的对象值，然后再对对象执行递增操作，返回递增前的副本，需要一个独立的副本，而不是对当前对象的引用
		Fixed &operator--(void); //pre-decrement
		Fixed operator--(int); //post-decrement
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b); // 常量引用，即返回的Fixed对象不能通过这个引用被修改，调用方不能修改返回值，且const Fixed 实例调用 min 函数时只有返回const才能保证返回值的类型兼容
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

