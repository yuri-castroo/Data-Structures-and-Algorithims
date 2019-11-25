#include <iostream>
#include "unsortedPQ.h"
#include "sortedPQ.h"
#include "minHeap.h"
#include "Timer.h"
#include <fstream>
#include <cstdlib> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>   

using namespace std;

int main(){
	srand(time(NULL));
	ifstream infile("numbers.txt");
	
	int first, n;
	infile >> first >> n;
	
	cout << "number of remaining elements to be inserted into a priority queue is: " << n << endl;
	
	/*
	t.start();
	for (int j = 0; j < 100; j++){
		for (int i = 0; i < 1000; i++){
			int x = (rand() % 10) + 1;
			test.insertItem(x);
		}
		
	}	
	t.stop();
	*/
	Timer t;
	int a;
	
	switch(first){
		case 0: { 
			//unsorted PQ
			cout << "UNSORTED PQ" << endl;
			UnsortedPQ<int> test;
			
			cout << test.isEmpty() <<endl;
			 
			while(infile >> a){
				test.insertItem(a);
				cout << a << endl;

			}

			/*
			t.start();
			//do stff
			t.stop();

			cout<<"Code took " << t.ms() << "milliseconds" <<endl;
			*/
			while(!test.isEmpty()){
				cout << test.removeMin() << endl;
			}
			cout << "-" << endl;
			break;
		}
		case 1: {
			//sorted PQ
			cout << "SORTED PQ" << endl;
			SortedPQ<int> test;
			while(infile >> a){
				test.insertItem(a);
			}
			while(!test.isEmpty()){
				cout << test.removeMin() << endl;
			}
			
			break;
		}
		case 2: {
			//heap PQ
			cout << "HEAP PQ" << endl;
			MinHeap <int>test(n);
			while(infile >> a){
				test.insertItem(a);
			}
    		while(!test.isEmpty()){
    			cout << test.removeMin() << endl;
    		}
    		
			break;
		}
		default: {
			cout << "not a vaild type of PQ" <<endl;
		}
	}

	return 0;
}
