#include <iostream>
using namespace std; 

class Point{
private:
	int* x;
	int* y;
public:
	void print(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
	Point(){
		x = 0;
		y = 0;
	}
	Point(int a, int b){
		x = a;
		y = b;

	}
	~Point(){
		cout << "destructor called" << endl; 
		delete x;
		delete y;

	} 

};

int main(){

	int SIZE = 10;

	Point s_array[SIZE];

	for (int i = 0; i < 10; i++){
		int x = i;
		Point p(i,++x);
		s_array[i] = p; 
	}

	for (int x = 0; x < SIZE; x++){
		s_array[x].print();
	}

	Point *h_array = new Point[SIZE];

	for (int i = 0; i < 10; i++){
		int x = i;
		Point p(i,++x); 
		h_array[i] = p; 
	}

	for (int x = 0; x < SIZE; x++){
		h_array[x].print();
	}

	delete [] h_array;

	return 0;
}