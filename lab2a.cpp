#include <iostream>

using namespace std;

class Shape{

public:
	virtual void draw()=0;
};

class Square: public Shape{

public:
	Square() {}
	virtual void draw() {
		cout << "Square" << endl;
	}
};

class Rectangle: public Shape{

public:
	Rectangle() {}
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class Triangle: public Shape{

public:
	Triangle() {}
	virtual void draw() {
		cout << "Triangle" << endl;
	}
};

class ShapeCreator{

public:
	virtual Shape *factory()=0;
};

class SquareCreator: public ShapeCreator{

public:
	virtual Shape* factory() {
		Square* s;
		return s;
	}
};

class RectangleCreator: public ShapeCreator{

public:
	virtual Shape* factory() {
		Rectangle* r;
		return r;
	}
};

class TriangleCreator: public ShapeCreator{

public:
	virtual Shape* factory() {
		Triangle* t;
		return t;
	}
};

int main() {

	SquareCreator s;
	RectangleCreator r;
	TriangleCreator t;

	auto square = s.factory();
	auto rectangle = r.factory();
	auto triangle = t.factory();

	square->draw();
	rectangle->draw();
	triangle->draw();
}