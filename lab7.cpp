#include <iostream>
#include <list>

using namespace std;

class OutputFile {
public:
	virtual void write() = 0;
	
};

class OutputFileCSV: public OutputFile {
public:
	OutputFileCSV(){}
	void write() {
		cout << "CSV with ";
	}
	
};

class OutputFileXML: public OutputFile {
public:
	OutputFileXML(){}
	void write() {
		cout << "XML with ";
	}
	
};

class OutputFileFIXED: public OutputFile {
public:
	OutputFileFIXED(){}
	void write() {
		cout << "FIXED with ";
	}
	
};

class Format {
public:
	virtual void write() = 0;
};


class YYYYMMDD: public Format {
public:
	YYYYMMDD(){}
	void write() {
		cout << "YYYYMMDD" << endl;
	}
	
};

class MMDDYYYY: public Format {
public:
	MMDDYYYY(){}
	void write() {
		cout << "MMDDYYYY" << endl;
	}
	
};

class DDMMYYYY: public Format {
public:
	DDMMYYYY(){}
	void write() {
		cout << "DDMMYYYY" << endl;
	}
	
};

class DateFormat {
public:
	OutputFile* outputfile;
	Format *format;

	DateFormat(OutputFile *o) {
		outputfile = o;
	}
	
	void write() {
		outputfile->write();
		format->write();
	}

	
};


int main() {

	
	DateFormat *csv = new DateFormat(new OutputFileCSV());
	DateFormat *xml = new DateFormat(new OutputFileXML());
	DateFormat *fixed = new DateFormat(new OutputFileFIXED());

	
	csv->format = new YYYYMMDD();
	csv->write();
	csv->format = new MMDDYYYY();
	csv->write();
	csv->format = new DDMMYYYY();
	csv->write();
	

	xml->format = new YYYYMMDD();
	xml->write();
	xml->format = new MMDDYYYY();
	xml->write();
	xml->format = new DDMMYYYY();
	xml->write();

	fixed->format = new YYYYMMDD();
	fixed->write();
	fixed->format = new MMDDYYYY();
	fixed->write();
	fixed->format = new DDMMYYYY();
	fixed->write();

}