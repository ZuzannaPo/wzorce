#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

enum Color {blank, red, green, blue}

class Memento {
public:
	Color color;
	virtual Color state() = 0;
	
};

class ConcreteMemento: public Memento {
public:
	ConcreteMemento(Color c) {
		color = c;
	}
	Color state() {
		return color;
	}
	
};

class Handler {
public:
	virtual void setNext(Handler *h) = 0;
	virtual string handle(string request) = 0;
	
};

class AbstractHandler: public Handler {
public:
	Color color;
	Handler *next;

	void setNext(Handler *h) {
		next = h;
	}

	string handle(string request) {
		return next->handle(request);
	}

	Memento* save() {
		Memento *c = new ConcreteMemento(color);
		return *c;
	}

	void restore(Memento *m) {
		color = m->state();
	}
};

class RightClickHandler: public AbstractHandler {
public:
	string handle(string request) {
		string m = "RightClick";
		if(stricmp(request,m) == 0) {
			return request;
		}
		else {
			AbstractHandler a;
			return a.handle(request);
		}
	}
	
};

class LeftClickHandler: public AbstractHandler {
public:
	string handle(string request) {
		string m = "LeftClick";
		if(stricmp(request,m) == 0) {
			return request;
		}
		else {
			AbstractHandler a;
			return a.handle(request);
		}
	}
	
};

class ScrollHandler: public AbstractHandler {
public:
	string handle(string request) {
		string m = "Scroll";
		if(stricmp(request,m) == 0) {
			return request;
		}
		else {
			AbstractHandler a;
			return a.handle(request);
		}
	}

	void handle(Handler *handler) {
		vector<string> clicks;
		clicks.push_back("LeftClick");
		clicks.push_back("RightClick");
		clicks.push_back("Scroll");

		for(string s : clicks) {
			string result = handler->handle(s);
			if(!result.empty()) {
				cout << result << endl;
			}
		}
	}
	
};

class Command {
public:
	virtual void Execute(AbstractHandler aH) = 0;
	
};

class ConcreteCommand: public Command {
public:
	Color color;
	ConcreteCommand(Color c) {
		color = c;
	}

	void Execute(AbstractHandler aH) {
		aH.color = this.color;
		cout << "Changing color to: " << this.color << endl;
	}
	
};


class ReversibleAction {
public:
	
	vector<Memento> mementos;
	AbstractHandler abstractHandler;

	ReversibleAction(AbstractHandler aH) {
		abstractHandler = aH;
	}

	void Backup() {
		this.mementos.push_back(this.abstractHandler.save());
	}

	void DoAction(Command *command) {
		command->Execute(this.abstractHandler);
	}

	void UndoAction() {
		if(this.mementos.empty()) {
			return;
		}

		Memento memento = this.mementos.back();
		mementos.pop_back();
		abstractHandler.restore(memento);
	}

};
