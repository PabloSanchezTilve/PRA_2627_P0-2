#include"Square.h"
#include<cmath>


Square::Square():Rectangle(){
	vs=new Point2D[N_VERTICES];
	vs[0]=Point2D(-1,1);
	vs[1]=Point2D(1,1);
	vs[2]=Point2D(1,-1);
	vs[3]=Point2D(-1,-1);
}

Square::Square(std::string color, Point2D* vertices):Rectangle(color,vertices){
	if(!check(vertices)){
		throw std::invalid_argument("Estos vértices no forman un cuadrado");
	}
	set_vertices(vertices);
}

void Square::set_vertices(Point2D* vertices){
	if (!check(vertices)) {
        throw std::invalid_argument("Estos vértices no forman un cuadrado válido");
    }
        delete[] vs;
	vs= new Point2D[N_VERTICES];
	vs[0]=vertices[0];
	vs[1]=vertices[1];
	vs[2]=vertices[2];
	vs[3]=vertices[3];
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Color: " << square.get_color() << std::endl;
    out << "Vértices del cuadrado: ("
        << square[0] << ", " << square[1] << ", "
        << square[2] << ", " << square[3] << ")";
    return out;
}


bool Square::check(Point2D* vertices){
	double d1 = Point2D::distance(vertices[0], vertices[1]);
    double d2 = Point2D::distance(vertices[1], vertices[2]);
    double d3 = Point2D::distance(vertices[2], vertices[3]);
    double d4 = Point2D::distance(vertices[3], vertices[0]);
    
    
    return (d1 == d2 && d2 == d3 && d3 == d4);
}

void Square::print(){
	std::cout<<*(this)<<std::endl;
}





