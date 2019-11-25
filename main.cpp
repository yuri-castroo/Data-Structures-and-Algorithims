#include <iostream>
#include "PriorityQueue.h"
#include <fstream>

using namespace std;

int main(){
	ifstream infile("numbers.txt");
	PriorityQueue<int> test;
	int num; 
	int first; 
	int second;

	if (infile.is_open()){

		first = getline(infile,num);
		second = getline(infile,num);

		while(getline(infile,num)){
			test.insertItem.(num);
		}
		infile.close();
	}
	/*
	while(infile >> a){
		test.insertItem(a);
	}
	*/
	cout << "First: " << first << endl;
	cout << "Second: " << second << endl;
	test.toString();
	test.removeMin();
	cout << "New list after removeMin :D!!!" << endl;
	test.toString();


	return 0;
}