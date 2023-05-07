#include <iostream>
#include <cstring>

using namespace std;

class Bike {
public:
	int wheels;
	string frame;
	
	virtual void print() = 0;

	virtual ~Bike(){}
	
};

class ConcreteBike: public Bike {
public:
	
	void print() {
		cout << "concrete bike" << endl;
	}
	
};

class Decorator: public Bike {
public:
	
	void print() {
		cout << "decorator" << endl;
	}

};

class DecoratorWheel: public Decorator {
public:
	DecoratorWheel(Bike *b) {
		this->wheels = 2;
		this->frame = b->frame;
	}
	
	void print() {
		cout << "i have " << this->wheels << " wheels" << endl;
	}
	
};

class DecoratorFrame: public Decorator {
public:
	DecoratorFrame(Bike *b) {
		this->wheels = b->wheels;
		this->frame = "blue";
	}
	
	void print() {
		cout << "i have " << this->frame << " frame" << endl;
	}
	
};


int main() {


	Bike* bike = new DecoratorFrame(new DecoratorWheel(new ConcreteBike()));
	cout << "i have " << bike->wheels << " wheels and " << bike->frame << " frame" << endl;
	bike->print();

}