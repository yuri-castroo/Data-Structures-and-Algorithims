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
	
	int n = 100000;
	
	cout << "number of remaining elements to be inserted into a priority queue is: " << n << endl;
	
	Timer ti;
	Timer tr;
	int a;
	
	switch(0){
		case 0: { 
			//unsorted PQ
			cout << "UNSORTED PQ" << endl;
			UnsortedPQ<int> test;
			tr.start();
			ti.start();
			for(int i = 1; i <= n; i++){
				test.insertItem((rand() % 10)+1);
			}
			ti.stop();

			cout<<"Code took " << ti.ms() << " milliseconds to insert" <<endl;

			
			while(!test.isEmpty()){
				test.removeMin();
			}
			tr.stop();

			cout<<"Code took " << tr.ms() << " milliseconds to remove" <<endl;

			break;
		}
		case 1: {
			//sorted PQ
			cout << "SORTED PQ" << endl;
			SortedPQ<int> test;
			tr.start();
			ti.start();
			for(int i = 0; i <= n; i++){
				test.insertItem((rand() % 10)+1);
			}
			ti.stop();

			cout<<"Code took " << ti.ms() << " milliseconds to insert" <<endl;

			while(!test.isEmpty()){
				test.removeMin();
			}
			tr.stop();

			cout<<"Code took " << tr.ms() << " milliseconds to remove" <<endl;
			
			break;
		}
		case 2: {
			//heap PQ
			cout << "HEAP PQ" << endl;
			MinHeap <int>test(n);
			tr.start();
			ti.start();
			for(int i = 0; i <= n; i++){
				test.insertItem((rand() % 10)+1);
			}
			ti.stop();

			cout<<"Code took " << ti.ms() << " milliseconds to insert" <<endl;

			while(!test.isEmpty()){
				test.removeMin();
			}
			tr.stop();

			cout<<"Code took " << tr.ms() << " milliseconds to remove" <<endl;
			
			break;
		}
		default: {
			cout << "not a vaild type of PQ" <<endl;
		}
	}

	return 0;
}