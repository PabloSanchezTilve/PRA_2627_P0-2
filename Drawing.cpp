#include "Drawing.h"
#include "Circle.h"
#include "Square.h"



Drawing::Drawing(){
	shapes= new ListArray<Shape*>();
}

Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->insert(0,shape);
}

void Drawing::add_back(Shape* shape) {
	shapes->append(shape);
}

void Drawing::print_all(){
	for(int i=0; i<shapes->size(); i++){
		shapes->get(i)->print();
	}
}

double Drawing::get_area_all_circles(){
	double totalArea=0;
	for(int i=0; i<shapes->size();i++){
		Circle* c=dynamic_cast<Circle*>(shapes->get(i));
		if(c != nullptr){
			totalArea += c->area();
		}
	}
	return totalArea;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr) { // Si es un cuadrado
            s->translate(incX, incY);
        }
    }
}
