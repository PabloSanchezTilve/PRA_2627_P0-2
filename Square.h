#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "Point2D.h"
#include <iostream>
#include <ostream>
#include "Rectangle.h"

class Square: public Rectangle{
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator <<(std::ostream &out, const Square &square);
		void set_vertices(Point2D* vertices) override;
		static bool check(Point2D* vertices);
		void print() override;
};

#endif
