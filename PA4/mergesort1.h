#ifndef MERGESORT_H
#define MERGESORT_H

#include <exception>

template <class Type>
class MergeSort{
private:
	Type *bubArr;
	int n;
	int capacity;

public:
	bool isEmpty(void){
		return n==0;
	}

	int size(void){
		return n;
	}
	
	BubbleSort(int sz) : capacity(sz){
		n = 0;
		bubArr = new Type[capacity];
	}

	~BubbleSort(void){
		delete[] bubArr;
	}

	void insertElement(Type val) throw(exception){
		if (n >= capacity){
			throw std::out_of_range("Heap is full");
		}

		bubArr[n] = val;
		n++;
	}

	void printArray()
	{
	    int i;
	    for (int i=0; i < capacity; i++){
	        cout<< bubArr[i] << " ";
	    }
	    cout << endl;
	}

	void sort(){
		Type a,b;
		for (int i = 0; i < n-1; i++){
			for (int j = 0; j < n - i - 1; j++){
				if (bubArr[j] > bubArr[j+1]){
					//swap(&bubArr[j], &bubArr[j+1]);
					Type temp = bubArr[j];
					bubArr[j] = bubArr[j+1];
					bubArr[j+1] = temp;
				}
			}
		}
	}

};

#endif