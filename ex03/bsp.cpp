/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:50:51 by linyao            #+#    #+#             */
/*   Updated: 2024/11/13 14:05:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float   crossProduct(Point const a, Point const b, Point const p) {
    return (((b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX())).toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    float area1, area2, area3;
    bool allpositive, allnegative;
    
    area1 = crossProduct(a, b, point);
    area2 = crossProduct(b, c, point);
    area3 = crossProduct(c, a, point);
    
    allpositive = (area1 > 0) && (area2 > 0) && (area3 > 0);
    allnegative = (area1 < 0) && (area2 < 0) && (area3 < 0);

    return (allpositive || allnegative);
}
