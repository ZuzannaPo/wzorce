#include <iostream>
#include <cstring>



using namespace std;

class Context;

class State {
public:
	virtual void validate(Context *context) = 0;
	virtual void inValidate(Context *context) = 0;
	virtual void replace(Context *context) = 0;
	virtual void include(Context *context) = 0;
	virtual void build(Context *context) = 0;
	virtual void orphane(Context *context) = 0;
	virtual void commit(Context *context) = 0;
	
};

class Context{
public:
	string payload;
	State *state;

	Context();
	void setState(State *s);
	void handlerValidate();
	void handlerinValidate();
	void handlerReplace();
	void handlerInclude();
	void handlerBuild();
	void handlerOrphane();
	void handlerCommit();

	~Context();
	
};

class Created: public State {
public:
	Created();
	void validate(Context *context);
    void inValidate(Context *context);
    void replace(Context *context);
    void include(Context *context);
    void build(Context *context);
    void orphane(Context *context);
    void commit(Context *context);
	~Created();
	
};

class Valid: public State {
public:
	Valid();
	void validate(Context *context);
    void inValidate(Context *context);
    void replace(Context *context);
    void include(Context *context);
    void build(Context *context);
    void orphane(Context *context);
    void commit(Context *context);
	~Valid();
	
};

class Invalid: public State {
public:
	Invalid();
	void validate(Context *context);
    void inValidate(Context *context);
    void replace(Context *context);
    void include(Context *context);
    void build(Context *context);
    void orphane(Context *context);
    void commit(Context *context);
	~Invalid();
	
};

class Mined: public State {
public:
	Mined();
	void validate(Context *context);
    void inValidate(Context *context);
    void replace(Context *context);
    void include(Context *context);
    void build(Context *context);
    void orphane(Context *context);
    void commit(Context *context);
	~Mined();
	
};

class DurablyCommited: public State {
public:
	DurablyCommited();
	void validate(Context *context);
    void inValidate(Context *context);
    void replace(Context *context);
    void include(Context *context);
    void build(Context *context);
    void orphane(Context *context);
    void commit(Context *context);
	~DurablyCommited();
	
};


Context::Context() {
	payload = "created";
	state = new Created();
}

void Context::setState(State *s) {
	state = s;
}

void Context::handlerValidate() {
	state->validate(this);
}

void Context::handlerinValidate() {
	state->inValidate(this);
}

void Context::handlerReplace(){
    state->replace(this);
}
void Context::handlerInclude(){
    state->include(this);
}
void Context::handlerBuild(){
    state->build(this);
}
void Context::handlerOrphane(){
    state->orphane(this);
}
void Context::handlerCommit(){
    state->commit(this);
}


Created::Created(){}

void Created::validate(Context *context) {
    context->payload = "validated";
    State *v = new Valid();
    context->setState(v);
}
void Created::inValidate(Context *context) {
    context->payload = "invalidated";
    State *i = new Invalid();
    context->setState(i);
}
void Created::replace(Context *context) {

}
void Created::include(Context *context) {

}
void Created::build(Context *context) {

}
void Created::commit(Context *context) {

}
void Created::orphane(Context *context){

}

Valid::Valid() {}

void Valid::validate(Context *context) {

}
void Valid::inValidate(Context *context) {
    
}
void Valid::replace(Context *context) {
	context->payload = "replaced";
	State *i = new Invalid();
	context->setState(i);
}
void Valid::include(Context *context) {
	context->payload = "included(mined)";
	State *m = new Mined();
	context->setState(m);
}
void Valid::build(Context *context) {

}
void Valid::commit(Context *context) {

}
void Valid::orphane(Context *context){

}

Invalid::Invalid(){}

void Invalid::validate(Context *context) {

}
void Invalid::inValidate(Context *context) {
    
}
void Invalid::replace(Context *context) {
	
}
void Invalid::include(Context *context) {
	
}
void Invalid::build(Context *context) {

}
void Invalid::commit(Context *context) {

}
void Invalid::orphane(Context *context){

}

Mined::Mined() {}

void Mined::validate(Context *context) {

}
void Mined::inValidate(Context *context) {
    
}
void Mined::replace(Context *context) {
	
}
void Mined::include(Context *context) {
	
}
void Mined::build(Context *context) {
	context->payload = "built (mined)";
	State *m = new Mined();
	context->setState(m);
}
void Mined::commit(Context *context) {
	context->payload = "commited";
	State *d = new DurablyCommited();
	context->setState(d);
}
void Mined::orphane(Context *context){
	context->payload = "orphaned";
	State *c = new Created();
	context->setState(c);
}

DurablyCommited::DurablyCommited(){}

void DurablyCommited::validate(Context *context) {

}
void DurablyCommited::inValidate(Context *context) {
    
}
void DurablyCommited::replace(Context *context) {
	
}
void DurablyCommited::include(Context *context) {
	
}
void DurablyCommited::build(Context *context) {

}
void DurablyCommited::commit(Context *context) {

}
void DurablyCommited::orphane(Context *context){

}

int main() {
	Context *context = new Context();
	cout << context->payload << endl;
	context->handlerValidate();
	cout << context->payload << endl;
	context->handlerInclude();
	cout << context->payload << endl;
	context->handlerBuild();
	cout << context->payload << endl;
	context->handlerCommit();
	cout << context->payload << endl;
}