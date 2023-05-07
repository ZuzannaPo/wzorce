#include <iostream>
#include <vector>

using namespace std;

class Visitor;

class AutoPart {
public:
	virtual int fabricationCost() = 0;
	virtual int fabricationTime() = 0;
	virtual int avgUsageTime() = 0;
	virtual int yearlyCost() = 0;
	virtual void accept(Visitor *visitor) = 0;

};

class Visitor {
public:
	AutoPart *ap;

	virtual int getFC() = 0;
	virtual int getFT() = 0;
	virtual int getAUT() = 0;
	virtual int getYC() = 0;
	
};

class Visitor1: public Visitor {
public:
	
	int getFC() {
		return ap->fabricationCost();
	}

	int getFT() {
		return ap->fabricationTime();
	}

	int getAUT() {
		return ap->avgUsageTime();
	}

	int getYC() {
		return ap->yearlyCost();
	}
	
};

class ElectricalPart: public AutoPart {
public:
	
    int fabricationCost() {
        return 1;
    }

    int fabricationTime() {
        return 2;
    }

    int avgUsageTime() {
        return 3;
    }

    int yearlyCost() {
        return 4;
    }

    void accept(Visitor *visitor) {
        visitor->ap = this;
    }
	
};

class SuspentionPart: public AutoPart {
public:
	
    int fabricationCost() {
        return 1;
    }

    int fabricationTime() {
        return 2;
    }

    int avgUsageTime() {
        return 3;
    }

    int yearlyCost() {
        return 4;
    }

    void accept(Visitor *visitor) {
        visitor->ap = this;
    }
	
};

class BodyPart: public AutoPart {
public:
	
    int fabricationCost() {
        return 1;
    }

    int fabricationTime() {
        return 2;
    }

    int avgUsageTime() {
        return 3;
    }

    int yearlyCost() {
        return 4;
    }

    void accept(Visitor *visitor) {
        visitor->ap = this;
    }
	
};


int main() {

	ElectricalPart *ep = new ElectricalPart();
	SuspentionPart *sp = new SuspentionPart();
	BodyPart *bp = new BodyPart();

	Visitor1 *visitor = new Visitor1();

	std::vector<AutoPart*> v;
	v.push_back(ep);
	v.push_back(sp);
	v.push_back(bp);

	int fc = 0, ft=0, aut=0, yc=0;

	for(AutoPart *ap: v) {
		ap->accept(visitor);
		fc+=visitor->getFC();
		ft+=visitor->getFT();
		aut+=visitor->getAUT();
		yc+=visitor->getYC();
	}

	cout << fc << endl << ft << endl << aut << endl << yc << endl;

}