#include <iostream>

using namespace std;

class Button {
public:
	int click;
	virtual ~Button() {}
	
};

class Button1: public Button {
public:
	Button1(){
		click = 1;
	}
	
};

class Button2: public Button {
public:
	Button2(){
		click = 2;
	}
	
};

class Handler {
public:
	Handler *next;

	virtual void hadleRequest(Button *button) = 0;
	virtual void click() = 0;
	
};

class AH1: public Handler {
public:
	AH1();
	
	void hadleRequest(Button *button);

	void click();
	
};

class AH2: public Handler {
public:
	AH2();
	
	void hadleRequest(Button *button);

	void click();
	
};

class HandlerHelper: public Handler {
public:
	void hadleRequest(Button *button) {
		if(button->click == 1) {
			next = new AH1();
			next->hadleRequest(button);
		}
		else {
			next = new AH2();
			next->hadleRequest(button);
		}
	}

	void click() {
		next->click();
	}
	
};

AH1::AH1(){}
AH2::AH2(){}

void AH1::hadleRequest(Button *button) {
		cout << "Button1" << endl;
		next = new AH2();
		next->click();
	}

void AH1::click() {
		cout << "Button1" << endl;
	}

void AH2::hadleRequest(Button *button) {
		cout << "Button2" << endl;
		next = new AH1();
		next->click();
	}

void AH2::click() {
		cout << "Button2" << endl;
	}



int main() {
	Button *one = new Button1();
	Handler *handler = new HandlerHelper();
	handler->hadleRequest(one);

	Button *two = new Button2();
	handler->hadleRequest(two);
}