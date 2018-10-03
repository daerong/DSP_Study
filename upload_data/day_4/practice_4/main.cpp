#include "circleClass.h"

int main() {

	Circle *p, *q;
	p = new Circle;
	q = new Circle(30);
		
	cout << p->getArea() << endl << q->getArea() << endl;
	delete p;
	delete q;


	return 0;
}