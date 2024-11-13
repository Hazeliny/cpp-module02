/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:23:19 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 14:04:47 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::Point(const Point &p) : _x(p.getX()), _y(p.getY()) {
//  operator= cannot be used because the private attributes in this class Point are all const which cannot be modified after initialization
//    *this = p;
}

Point &Point::operator=(const Point &p) {
//    if (this != &p)
//        this->_x = p.getX();
//        this->_y = p.getY();
    if (this == &p)
        return (*this);
    // Here is empty code...
    return (*this);
}

Point::~Point(void) {}

Fixed const &Point::getX(void) const {
    return (this->_x);
}

Fixed const &Point::getY(void) const {
    return (this->_y);
}

//void Point::setX(Fixed const &x) {}

// void Point::setY(Fixed const &y);
        
std::ostream &operator<<(std::ostream &out, const Point &p) {
    out << "(" << p.getX() << ", " << p.getY() << ")" << std::endl;
    return (out);
}
