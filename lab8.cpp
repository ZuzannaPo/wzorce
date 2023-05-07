#include <iostream>
#include <list>

using namespace std;

class Order {
public:
	string state;
	int numOfState;

	Order(string s, int n) {
		state = s;
		numOfState = n;
	}
	~Order(){}
	
};

class Colleague {
public:
	
	virtual Order order(Order *o) = 0;
	
};

class Mediator {
public:
	list<Colleague*> colleagues;
	virtual void call(Order *o) = 0;
	
};

class Reciever: public Colleague {
public:
	Reciever(){}
	Order order(Order *o) {
		if(o->numOfState == 0) {
			o->state = "Recieved";
			o->numOfState = 1;
		
		}
		return *o;
	}
	
};

class Verificator: public Colleague {
public:
	Verificator(){}
	Order order(Order *o) {
		if(o->numOfState == 1) {
			o->state = "Accepted";
			o->numOfState = 2;
			
		}
		else o->state = "Rejected";
		return *o;
	}
	
};

class Finisher: public Colleague {
public:
	Finisher(){}
	Order order(Order *o) {
		if(o->numOfState == 2) {
			o->state = "Completed";
			o->numOfState = 3;
			
		}
		return *o;
	}
	
};

class LoggerToFile: public Colleague {
public:
	LoggerToFile(){}
	Order order(Order *o) {
		if(o->numOfState == 3) {
			o->state = "LoggedToFile";
			o->numOfState = 4;
			
		}
		return *o;
	}
	
};

class MediatorC: public Mediator{
public:
	MediatorC() {
		colleagues.push_back(new Reciever());
		colleagues.push_back(new Verificator());
		colleagues.push_back(new Finisher());
		colleagues.push_back(new LoggerToFile());
	}
	
	void call(Order *o) {
		for(Colleague *c: colleagues) {
			c->order(o);
			cout << o->numOfState << " " << o->state << endl;
		}
	}
	
};

int main() {

	Order *o = new Order("start",0);
	Mediator *m = new MediatorC();
	cout << o->numOfState << " " << o->state << endl;
	m->call(o);
}