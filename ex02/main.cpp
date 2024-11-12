/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:04 by linyao            #+#    #+#             */
/*   Updated: 2024/11/12 23:44:51 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
//定点数（Fixed-point number）将固定数量的位分配给整数部分和小数部分,通常具有固定的小数位数
//每个定点数能表示的精度是确定的,适用于银行、财务等对精度要求严格的领域
//定点数的优点是精度高、运算速度快、存储空间小,适用于需要高精度的计算、信号处理、图像处理等领域
//它没有指数部分，定点数的范围比浮点数更小
//浮点数输出的精度位数不是由 Fixed 类定义的，而是由 std::cout 本身的默认设置控制的，实际显示位数会有所不同
//用 std::fixed 和 std::setprecision 操作符可以控制输出的精度位数
