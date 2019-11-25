#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <exception>
#include <stdexcept>
#include <iostream>

template <class Type>
class BubbleSort{
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
	
	BubbleSort(int sz){
		n = 0;
		capacity = sz;
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

	void bubbleSort(){
		Type a,b;
		//starting from the beginning of the lost until the last element
		for (int i = 0; i < n-1; i++){
			//starting from beginning of the list, one ahead of i
			for (int j = 0; j < n - i - 1; j++){
				//if the one ahead is bigger, swap values
				if (bubArr[j] > bubArr[j+1]){
					//swap bubArr[j] and bubArr[j+1]
					Type temp = bubArr[j];
					bubArr[j] = bubArr[j+1];
					bubArr[j+1] = temp;
				}
			}
		}
	}

};

#endif