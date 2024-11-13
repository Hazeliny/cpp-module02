/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:04 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 14:10:04 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);
	// inside triangle
	std::cout << "Is the 1st point( x= " << point.getX() << ",\ty= " << point.getY() << " ) inside the triangle?\n";
	std::cout << "\ta( x= " << a.getX() << "\ty= " << a.getY() << " )\n";
	std::cout << "\tb( x= " << b.getX() << "\ty= " << b.getY() << " )\n";
	std::cout << "\tc( x= " << c.getX() << "\ty= " << c.getY() << " )\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
		
	std::cout << "\n-----------------------------Splitting Line-----------------------------\n" << std::endl;
	
	const Point a1(-1.5, -1.5);
	const Point b1(2.5, 2.5);
	const Point c1(-1, -2);
	const Point point1(8.35, -9.25);
	// outside triangle
	std::cout << "Is the 2nd point( x= " << point1.getX() << ",\ty= " << point1.getY() << " ) inside the triangle?\n";
	std::cout << "\ta( x= " << a1.getX() << "\ty= " << a1.getY() << " )\n";
	std::cout << "\tb( x= " << b1.getX() << "\ty= " << b1.getY() << " )\n";
	std::cout << "\tc( x= " << c1.getX() << "\ty= " << c1.getY() << " )\n" << std::endl;
	if (bsp(a1, b1, c1, point1) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;

	std::cout << "\n-----------------------------Splitting Line-----------------------------\n" << std::endl;
	
	const Point a2(2, 1);
	const Point b2(2, 4);
	const Point c2(6, 1);
	const Point point2(4, 2.5);
	// on the edge of triangle
	std::cout << "Is the 3rd point( x= " << point2.getX() << ",\ty= " << point2.getY() << " ) inside the triangle?\n";
	std::cout << "\ta( x= " << a2.getX() << "\ty= " << a2.getY() << " )\n";
	std::cout << "\tb( x= " << b2.getX() << "\ty= " << b2.getY() << " )\n";
	std::cout << "\tc( x= " << c2.getX() << "\ty= " << c2.getY() << " )\n" << std::endl;
	if (bsp(a2, b2, c2, point2) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;

	std::cout << "\n-----------------------------Splitting Line-----------------------------\n" << std::endl;
	
	const Point a3(2, 1);
	const Point b3(2, 4);
	const Point c3(6, 1);
	const Point point3(6, 1);
	// on the vertex of triangle
	std::cout << "Is the 4th point( x= " << point3.getX() << ",\ty= " << point3.getY() << " ) inside the triangle?\n";
	std::cout << "\ta( x= " << a3.getX() << "\ty= " << a3.getY() << " )\n";
	std::cout << "\tb( x= " << b3.getX() << "\ty= " << b3.getY() << " )\n";
	std::cout << "\tc( x= " << c3.getX() << "\ty= " << c3.getY() << " )\n" << std::endl;
	if (bsp(a3, b3, c3, point3) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
		
	std::cout << "\n-----------------------------Splitting Line-----------------------------\n" << std::endl;
	
	const Point a4(2, 1);
	const Point b4(2, 4);
	const Point c4(6, 1);
	const Point point4(3, 1);
	// on another edge of triangle
	std::cout << "Is the 5th point( x= " << point4.getX() << ",\ty= " << point4.getY() << " ) inside the triangle?\n";
	std::cout << "\ta( x= " << a4.getX() << "\ty= " << a4.getY() << " )\n";
	std::cout << "\tb( x= " << b4.getX() << "\ty= " << b4.getY() << " )\n";
	std::cout << "\tc( x= " << c4.getX() << "\ty= " << c4.getY() << " )\n" << std::endl;
	if (bsp(a4, b4, c4, point4) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;

	return 0;
}

