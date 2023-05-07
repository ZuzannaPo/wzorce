#include <iostream>
#include <cstring>

using namespace  std;


class Form {

public:
	string message;
	int buttons;
	Form(){}

	void message_(const string& message_){
		message = message_;
	}

	void buttons_(const int& buttons_){
		buttons = buttons_;
	}

	~Form(){}
	
};


class ButtonsBuilder {
public:
	ButtonsBuilder(){}
	virtual void addButton(Form* form) = 0;
	
};

class StudentsButtonsBuilder: public ButtonsBuilder {
public:
	StudentsButtonsBuilder(){}

	void addButton(Form* form){
		form->buttons++;
	}

	~StudentsButtonsBuilder(){}
	
};

class AdminButtonsBuilder: public ButtonsBuilder {
public:
	AdminButtonsBuilder(){}

	void addButton(Form* form){
		form->buttons++;
	}

	~AdminButtonsBuilder(){}
	
};

class WelcomeMessageBuilder {
public:
	WelcomeMessageBuilder(){}
	virtual void printWM(Form* form) = 0;
	
};

class StudentsWMBuilder: public WelcomeMessageBuilder {
public:
	StudentsWMBuilder(){}

	void printWM(Form* form) {
		form->message = "Student message";
	}

	~StudentsWMBuilder(){}
	
};

class AdminWMBuilder: public WelcomeMessageBuilder {
public:
	AdminWMBuilder(){}

	void printWM(Form* form){
		form->message = "Admin message";
	}

	~AdminWMBuilder(){}
	
};

class FormBuilder {

public:
	Form* form;
	ButtonsBuilder* bb;
	WelcomeMessageBuilder* wmb;
	FormBuilder(){}

	Form* getForm() {
		return form;
	}

	void constructForm() {
		form = new Form();
		bb->addButton(form);
		wmb->printWM(form);
	}

	void setButtonsBuilder(ButtonsBuilder *bb_) {
		bb = bb_;
	}

	void setWMBuilder(WelcomeMessageBuilder* wmb_) {
		wmb = wmb_;
	}

	~FormBuilder(){}
	
};


int main(){

	FormBuilder* fBuilder = new FormBuilder();
	StudentsButtonsBuilder* bBuilder = new StudentsButtonsBuilder();
	StudentsWMBuilder* wmBuilder = new StudentsWMBuilder();

	fBuilder->setButtonsBuilder(bBuilder);
	fBuilder->setWMBuilder(wmBuilder);
	fBuilder->constructForm();

	Form* form = fBuilder->getForm();
	cout << fBuilder->form->message << endl;


}

