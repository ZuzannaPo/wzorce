#include <iostream>
#include <cstring>
using namespace std;

class Tax {
public:
	double rate;

	Tax() {
		this->rate = 0;
	}

	virtual void f() = 0;

	double calculate(double base) {
		return ((rate/100) * base);
	}
	virtual ~Tax(){}
	

	
};

class Poland: public Tax {
	public:
		Poland(bool isLow) {
			if (isLow) {
				this->rate = 18;
			}
			else {
				this->rate = 32;
			}
		}

		void f() {}
		~Poland() {}
		
	};

	class USA: public Tax {
	public:
		USA(bool isLow) {
	        if (isLow) {
	            this->rate = 10;
	        } else {
	            this->rate = 20;
	        }
	    }
	    void f() {}
		~USA() {}
		
	};

	class Szwecja: public Tax {
	public:
		Szwecja(bool isLow) {
	        if (isLow) {
	            this->rate = 15;
	        } else {
	            this->rate = 25;
	        }
	    }
	    void f() {}
		~Szwecja() {}
		
	};

class SuplementaryPayment {
public:
	double rate;

	SuplementaryPayment() {
		this->rate = 0;
	}
	
	virtual void f() = 0;

	double calculate(double base) {
        return ((base / 100) * base);
    }
	virtual ~SuplementaryPayment() {}

	
	
};


class sPoland: public SuplementaryPayment {
	public:
		sPoland(bool isLow) {
			if (isLow) {
				this->rate = 28;
			}
			else {
				this->rate = 42;
			}
		}
		void f() {}
		~sPoland(){}
		
	};

	class sUSA: public SuplementaryPayment {
	public:
		sUSA(bool isLow) {
	        if (isLow) {
	            this->rate = 20;
	        } else {
	            this->rate = 40;
	        }
	    }
	    void f() {}
		~sUSA(){}
		
	};

	class sSzwecja: public SuplementaryPayment {
	public:
		sSzwecja(bool isLow) {
	        if (isLow) {
	            this->rate = 25;
	        } else {
	            this->rate = 45;
	        }
	    }
	    void f() {}
		~sSzwecja(){}
		
	};


class Factory {
public:
	string country;
	bool isLower;
	Factory(string c, bool is) {
		this->country = c;
		this->isLower = is;
	}

	Factory get() {
		Factory f = Factory(this->country,this->isLower); 
		return f;
	}

	SuplementaryPayment* createSP() {
		SuplementaryPayment *SP;
		if (country == "Poland") {
			SP = new sPoland(isLower);
			
		}
        
        else if (country == "USA") {
        	SP = new sUSA(isLower);
        	
        }

        else if (country == "Szwecja") {
        	SP = new sSzwecja(isLower);
        	
        }
        return SP;
    }
    Tax* createTax() {
		Tax *T;
        if (country == "Poland") {
			T = new Poland(isLower);
		}
        
        else if (country == "USA") {
        	T = new USA(isLower);
        }

        else if (country == "Szwecja") {
        	T = new Szwecja(isLower);
        }
        
        return T;
    }

	~Factory(){}
	
};


int main() {
	
	double baseAmount = 100000.0;

	Factory* fact = new Factory("Poland", true);
	SuplementaryPayment *sp = fact->createSP();
	double amount = sp->calculate(baseAmount);

	Tax *tax = fact->createTax();
	double t = tax->calculate(amount);
	cout << t << endl;

}
