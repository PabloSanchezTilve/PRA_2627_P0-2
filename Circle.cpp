#include<iostream>
#include<cmath>
#include<ostream>
#include "Circle.h"


Circle::Circle(): Shape("red"), center(0.0,0.0),radius(1){}


Circle::Circle(std::string  color, Point2D center, double radius):Shape(color),center(center),radius(radius){
	if(radius<=0){
		throw std::invalid_argument("Valor del radio no permitido");
	}
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center=p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius=r;
}

std::ostream& operator <<(std::ostream &out, const Circle &c){
	out<<"Centro del círculo: ("<<c.center.x<<","<<c.center.y<<")"<<std::endl;
	out<<"Radio del círculo: " <<c.radius<<std::endl;
	out<<"Color del círculo: "<< c.get_color()<<std::endl;
	return out;
}

double Circle::area() const{
	return M_PI * pow(radius,2);
}
double Circle::perimeter() const{
	return 2 * M_PI * radius;
}
void Circle::translate(double incX, double incY){
	center.x+=incX;
	center.y+=incY;
}
void Circle::print(){
	std::cout<<*this<<std::endl;
}

