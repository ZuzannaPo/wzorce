#include <iostream>

using namespace std;


const int n = 12;
int arr[n] = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};

void swap(int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void out() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

class Strategy {
public:
	virtual void sort() = 0;
	virtual ~Strategy() {}
	
};

class BubbleSort: public Strategy {
public:
	void sort() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n-1; ++j) {
				if(arr[j] > arr[j+1]) swap(j,j+1);
			}

		}
		
	}
	
};


class SelectionSort: public Strategy {
public:
	void sort() {
		for (int i = 0; i < n-1; ++i) {
			int min = i;
			for (int j = 0; j < n; j++) {
				if(arr[min] > arr[j]) min = j;
			}
			swap(i,min);
		}
	}
	
};


class InsertionSort: public Strategy {
public:
	void sort() {
		for (int i = 0; i < n-1; ++i) {
			for (int j = i; j > 0; --j) {
				if(arr[j-1] > arr[j]) swap(j,j-1);
			}
		}
	}
	
};

class Context {
public:
	Strategy *strategy;
	void bubbleHandler () {
		strategy = new BubbleSort();
	}

	void selectionHandler() {
		strategy = new SelectionSort();
	}

	void insertionHandler() {
		strategy = new InsertionSort();
	}

	void sort() {
		strategy->sort();
	}
};

int main() {

	Context context;

	out();

	context.bubbleHandler();
	context.sort();
	out();
}