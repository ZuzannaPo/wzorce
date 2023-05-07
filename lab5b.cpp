#include <iostream>
#include <iterator>
#include <list>

using namespace std;

class Subject {
public:
	int click;
	virtual void notifyObserver() = 0;
	
};

class Observer {
public:
	Subject *button;
	virtual void update(Subject* s) = 0;

	
};

class Button: public Subject {
public:
	list<Observer*> observers;

	void notifyObserver() {
		list<Observer*>::iterator i;
		for(i = this->observers.begin(); i != this->observers.end(); ++i) {
			*i->update(this);
			
		}
	}

	virtual void clik() = 0;
	
};

class Button1: public Button {
public:
	Button1() {
		click = 1;
	}
	
	void clik() {
		click = 10;
		notifyObserver();
	}

	
};

class Button2: public Button {
public:
	Button2() {
		click = 2;
	}

	
	void clik() {
		click = 20;
		notifyObserver();
	}
	
};

class Ob1: public Observer {
public:
	//Button *button;

	Ob1(Button *b) {
		this->button = b;
	}

	void update(Subject *b) {
		button->click = b->click;
	}
};

class Ob2: public Observer {
public:
	//Button *button;

	Ob2(Button *b) {
		this->button = b;
	}

	void update(Subject *b) {
		button->click = b->click;
	}
};

int main() {

	Button *b1 = new Button1();
	Observer *one = new Ob1(b1);
	Observer *two = new Ob2(b1);

	cout << one->button->click << "  " << two->button->click << endl;

	b1->clik();

	cout << one->button->click << "  " << two->button->click << endl;		
}