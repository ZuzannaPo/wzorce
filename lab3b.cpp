#include <iostream>
#include <cstring>
#include <vector>

using namespace  std;

class Type {
public:
    int type;

    Type(int x) {
        type = x;
    }
};

class Multimedia {
public:
	Type* type;
	string name;

	virtual Multimedia* clone() = 0;
	virtual void toString() = 0;
	
};

class Picture: public Multimedia {
public:
	Picture(Type* t, string s) {
		this->type = t;
		this->name = s;
	}

	Multimedia* clone() {
		return new Picture(this->type,this->name);
	}

	void toString() {
		cout << this->name;
	}
	~Picture(){}
	
};

class Music: public Multimedia {
public:
	Music(Type* t, string s) {
		this->type = t;
		this->name = s;
	}

	Multimedia* clone() {
		return new Music(this->type,this->name);
	}

	void toString() {
		cout << this->name;
	}
	~Music(){}
	
};

class Movie: public Multimedia {
public:
	Movie(Type* t, string s) {
		this->type = t;
		this->name = s;
	}

	Multimedia* clone() {
		return new Movie(this->type,this->name);
	}

	void toString() {
		cout << this->name;
	}
	~Movie(){}
	
};

int main() {
	std::vector<Multimedia*> my_multimedia;
	my_multimedia.push_back(new Picture(new Type(0),"Picture"));
	my_multimedia.push_back(new Music(new Type(1),"Music"));
	my_multimedia.push_back(new Movie(new Type(2),"Movie"));

	std::vector<Multimedia*> multimedia_copy;

	for(std::vector<Multimedia*>::iterator it = my_multimedia.begin(); it!=my_multimedia.end(); ++it) {
		multimedia_copy.push_back((*it)->clone());
	}

	for(std::vector<Multimedia*>::iterator it2 = my_multimedia.begin(); it2!=my_multimedia.end(); ++it2) {
		(*it2)->toString();
	}
}