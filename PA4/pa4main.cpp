#include <iostream>
#include <fstream>
#include "mergesort.h"
#include "heap.h" 
#include "bubblesort.h"
#include "quicksort.h"
#include "Timer.h"

using namespace std; 

int main(){
	ifstream infile("randddd2.txt");
	
	int first, n, a;
	infile >> first >> n;
	
	cout << "number of remaining elements to be inserted into a priority queue is: " << n << endl;

	switch(first){
		case 1: {
			cout << "Bubble Sort" << endl;
			Timer t;
			t.start();
			BubbleSort<int> test(n);
			while(infile >> a){
				test.insertElement(a);
			}
			//test.printArray();
			test.bubbleSort();
			//test.printArray();
			t.stop();
			
			break;
		}
		case 2: {
			//ofstream myfile("sorted4.txt");
			cout << "Heap Sort" << endl;
			Timer t;
			t.start();
			Heap<int> test(n);
			while(infile >> a){
				test.insertItem(a);
			}
			
			while(!test.isEmpty()){
    			test.removeMin();
    			//myfile << test.removeMin() << endl;
    		}
    		t.stop();
			
    		//cout << endl;
    		//myfile.close();
			break;
		}
		case 3: {
			cout << "Merge Sort" << endl;
			Timer t;
			t.start();
			MergeSort<int> test(n);
			while(infile >> a){
				test.insertElement(a);
			}
			//test.printArray();
			int arr_size = test.size();
			int l = 0;
			int r = arr_size -1;
			test.mergeSort(l,r);
			//test.printArray();
			t.stop();
			
			break;
		}
		case 4: {
			cout << "Quick Sort" << endl; 
			Timer t;
			t.start();
			QuickSort<int> test(n);
			while(infile >> a){
				test.insertElement(a);
			}
			//test.printArray();
			int arr_size = test.size();
			int l = 0;
			int r = arr_size - 1;
			test.quickSort(l,r);
			//test.printArray();
			t.stop();
			
			break;
		}
		default:{
			cout << "ummm not valid number yoo" << endl;
		}
	}

	//myfile.close();
}
