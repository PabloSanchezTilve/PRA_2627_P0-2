#include<ostream>
#include<cmath>
#include<iostream>

#include"Rectangle.h"

Rectangle::Rectangle(): Shape(){
	vs=new Point2D[N_VERTICES];
	vs[0]=Point2D(-1,0.5);
	vs[1]=Point2D(1,0.5);
	vs[2]=Point2D(1,-0.5);
	vs[3]=Point2D(-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices): Shape(color){
	if(Point2D::distance(vertices[0],vertices[1]) != Point2D::distance(vertices[2],vertices[3]) || Point2D::distance(vertices[1],vertices[2]) != Point2D::distance(vertices[3],vertices[0])){
			throw std::invalid_argument("Estos vértices no forman un rectángulo");
			}
			vs= new Point2D[N_VERTICES];
			vs[0]=vertices[0];
			vs[1]=vertices[1];
			vs[2]=vertices[2];
			vs[3]=vertices[3];
			}


Rectangle::Rectangle(const Rectangle &r):Shape(r){ 
             vs= new Point2D[N_VERTICES];
	     vs[0]=r.vs[0];
	     vs[1]=r.vs[1];
	     vs[2]=r.vs[2];
	     vs[3]=r.vs[3];
	     }
	     Rectangle::~Rectangle(){
	     delete[] vs;
	     }
Point2D Rectangle::get_vertex(int ind) const{
	if(ind<0 || ind >=N_VERTICES){
		throw std::out_of_range("Indice imposible");
	}
	return vs[ind];
}

Point2D Rectangle::operator[] (int ind) const{
	return get_vertex(ind);
}
void Rectangle::set_vertices(Point2D* vertices){
	if(Point2D::distance(vertices[0],vertices[1]) != Point2D::distance(vertices[2],vertices[3]) || Point2D::distance(vertices[1],vertices[2]) != Point2D::distance(vertices[3],vertices[0])){
                        throw std::invalid_argument("Estos vértices no forman un rectángulo");
                        }
			delete [] vs;
			vs= new Point2D[N_VERTICES];
			vs[0]=vertices[0];
			vs[1]=vertices[1];
			vs[2]=vertices[2];
			vs[3]=vertices[3];
			}
Rectangle& Rectangle::operator =(const Rectangle &r){
	if(this != &r){
		Shape::operator=(r);
		delete[] vs;
		vs = new Point2D[N_VERTICES];
		vs[0]=r.vs[0];
		vs[1]=r.vs[1];
		vs[2]=r.vs[2];
		vs[3]=r.vs[3];
	}
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out<<"color: "<< r.get_color()<<std::endl;
	out<<"Vértices: ("<<r.vs[0]<<","<<r.vs[1]<<","<<r.vs[2]<<","<<r.vs[3]<<")"<<std::endl;
	return out;
}

bool Rectangle::check(Point2D* vertices){
	return !(Point2D::distance(vertices[0],vertices[1]) != Point2D::distance(vertices[2],vertices[3]) || Point2D::distance(vertices[1],vertices[2]) != Point2D::distance(vertices[3],vertices[0]));
}

double Rectangle::area() const{
	return Point2D::distance(vs[0],vs[1]) * Point2D:: distance(vs[1],vs[2]);
}
double Rectangle::perimeter() const{
	return Point2D::distance(vs[0],vs[1]) + Point2D::distance(vs[1],vs[2]) + Point2D::distance(vs[2],vs[3]) + Point2D::distance(vs[3],vs[0]);
}
void Rectangle::translate(double incX,double incY){
	for(int i=0; i<4 ; i++){
		vs[i].x+=incX;
		vs[i].y+=incY;
	}
}


void Rectangle::print(){
	std::cout<<*(this);
}






