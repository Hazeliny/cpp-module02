/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:22:57 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 12:21:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
        Point(float const x, float const y);
        Point(const Point &p);
        Point &operator=(const Point &p);
        ~Point(void);
        Fixed const &getX(void) const;
        Fixed const &getY(void) const;
//        void setX(Fixed const &x);
//        void setY(Fixed const &y);
};

std::ostream &operator<<(std::ostream &out, const Point &p);

bool bsp( Point const a, Point const b, Point const c, Point const point);
