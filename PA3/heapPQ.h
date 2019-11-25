#ifndef HEAP_PQ
#define HEAP_PQ 

#include <exception>
#include <iostream> 
#include <vector> 

template <class Type>
class HeapPQ{
private:
	int size;
public:
	minHeap ()
	void heapify(Type arr[], int i){
		int left = 2*i;
		int right = (2*i)+1; 
		int min = i;
		if (left <= size && arr[left] < arr[i]){
			min = left; 
		}
		if (right <= size && arr[right] < arr[min]){
			min = right; 
		}
		if (min != i){
			Type temp = arr[i];
			arr[i] = arr[min];
			arr[min] = i;
			heapify(arr,min);
		}
	}
	void buildHeap(Type arr[]){
		for (int i = size/2; i >= 1; i--){
			heapify(arr,i);
		}
	}
	void sortHeap(int arr[]){ 
		buildHeap(arr);
		int n = size;
		for (int i = size; i >= 2; i--){
			Type temp = arr[1];
			arr[1] = arr[i]; 
			arr[i] = temp;
			n--;
			heapify(arr,1,n);
		}
	}
	void changeVal(Type arr[], int i, Type data){
		if (data < arr[i]){
			cout << "uhhh" <<endl;
			return;
		}
		else{
			arr[i] = data;
			while(i > 1 && arr[i/2] < arr[i]){
				Type temp = arr[i/2];
				arr[i/2] = arr[i];
				arr[i] = temp;
				i = i/2; 
			}
		}
	}
	void insertItem (Type arr[], Type data){
		size++;
		arr[size] = -1;
		changeVal(arr, size, data);
	}
	Type minValue(Type arr[]){
		return arr[1]; //min is the root of the heap
	}
	Type removeMin(Type arr[]){
		if (size == 0){
			throw std::out_of_range("Empty heap");
		}
		int min = arr[1];
		arr[1] = arr[size];
		size--;
		heapify(arr,1);
		return min;
	}
};

#endif
