#include <ostream>
#include <cmath>
#include "Point2D.h"

double Point2D::distance(const Point2D &a,const  Point2D &b){
	return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2)); //pow(valor,exponente)
}

bool Point2D::operator==(const Point2D &other) {
	return x == other.x && y == other.y ;
}

bool Point2D::operator!=(const Point2D &other) {
    return x != other.x || y != other.y;
}

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out<<"posición x: "<<p.x<<std::endl<<"posición y: "<<p.y<<std::endl;
    return out;
}

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}
