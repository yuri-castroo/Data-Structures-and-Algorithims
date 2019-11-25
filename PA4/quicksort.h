#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <exception>

template <class Type>
class QuickSort{
private:
	Type *arr;
	int n;
	int capacity;
	int left;
	int right;

public:
	QuickSort(int sz) : capacity(sz){
		n = 0;
		arr = new Type[capacity];
	}

	~QuickSort(void){
		delete[] arr;
	}

	int size(void){
		return n;
	}

	bool isEmpty(void){
		return n==0;
	}

	void printArray(){
	    int i;
	    for (int i=0; i < capacity; i++){
	        std::cout<< arr[i] << " ";
	    }
	    std::cout << std::endl;
	}

	void insertElement(Type val) throw(std::exception){
		if (n >= capacity){
			throw std::out_of_range(" is full");
		}

		arr[n] = val;
		n++;
	}

	/* The main function that implements QuickSort
	 arr[] --> Array to be sorted,
	  low  --> Starting index,
	  high  --> Ending index */
	void quickSort(int left, int right){
	    if (left < right)
	    {
	        /* index is partitioning index, arr[p] is now
	           at right place */
	        int index = partition(left, right);
	 
	        // Separately sort elements before
	        // partition and after partition
	        quickSort(left, index - 1);
	        quickSort(index + 1, right);
	    }
	}

	int partition (int left, int right){
	    int pivot = arr[right];    // pivot
	    int i = (left - 1);  // Index of smaller element
	 
	    for (int j = left; j <= right- 1; j++)
	    {
	        if (arr[j] <= pivot)
	        {
	            i++;
	            //swap arr[i] and arr[j]
	            Type temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
	        }
	    }
	    //swap arr[i + 1] and arr[right]
	    Type temp = arr[i + 1];
		arr[i + 1] = arr[right];
		arr[right] = temp;
		
	    return (i + 1);
	}
 


};
#endif