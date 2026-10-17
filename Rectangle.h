#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : Shape {
	protected:
		Point2D* vs;
	public:
		Rectangle();
		Rectangle(std::string color, Point2D* vertices);
		Rectangle(const Rectangle &r);
		~Rectangle();
		Point2D get_vertex(int ind) const;
		Point2D operator[] (int ind) const;
		virtual void set_vertices(Point2D* vertices);
		Rectangle& operator=(const Rectangle &r);
		friend std::ostream& operator <<(ostream &out, const Rectangle &r);
		static bool check(Point2D* vertices);
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		virtual void print() override;
};

#endif
