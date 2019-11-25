#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdexcept>

template <class Type>
class MergeSort{
private:
	Type *arr;
	int n;
	int capacity;
	int left;
	int right;

public:
	MergeSort(int sz) : capacity(sz){
		n = 0;
		arr = new Type[capacity];
	}

	~MergeSort(void){
		delete[] arr;
	}

	int size(void){
		return n;
	}

	bool isEmpty(void){
		return n==0;
	}

	void insertElement(Type val) throw(std::exception){
		if (n >= capacity){
			throw std::out_of_range(" is full");
		}

		arr[n] = val;
		n++;
	}

	void printArray(){
	    int i;
	    for (int i=0; i < capacity; i++){
	        std::cout<< arr[i] << " ";
	    }
	    std::cout << std::endl;
	}

	void mergeSort(int left, int right){
	    if (left < right)
	    {
	        // Same as (l+r)/2, but avoids overflow for large left and right
	        int mid = left+(right-left)/2;
	 
	        // Sort the halves of the array, recursive calls
	        mergeSort(left, mid);
	        mergeSort(mid+1, right);

	 		//merge the two halves
	        merge(left, mid, right);
	    }
	}

	void merge(int left, int mid, int right){
	    int i, j, k;
	    int n1 = mid - left + 1;
	    int n2 =  right - mid;
	 
	    /* create temp arrays */
	    int LeftArr[n1], RightArr[n2];
	 
	    /* Copy data to temp arrays L[] and R[] */
	    for (i = 0; i < n1; i++)
	        LeftArr[i] = arr[left + i];
	    for (j = 0; j < n2; j++)
	        RightArr[j] = arr[mid + 1+ j];
	 
	    /* Merge the temp arrays back into arr[l..r]*/
	    i = 0; // Initial index of first subarray
	    j = 0; // Initial index of second subarray
	    k = left; // Initial index of merged subarray
	    while (i < n1 && j < n2)
	    {
	        if (LeftArr[i] <= RightArr[j])
	        {
	            arr[k] = LeftArr[i];
	            i++;
	        }
	        else
	        {
	            arr[k] = RightArr[j];
	            j++;
	        }
	        k++;
	    }
	 
	    /* Copy the remaining elements of L[], if there
	       are any */
	    while (i < n1)
	    {
	        arr[k] = LeftArr[i];
	        i++;
	        k++;
	    }
	 
	    /* Copy the remaining elements of R[], if there
	       are any */
	    while (j < n2)
	    {
	        arr[k] = RightArr[j];
	        j++;
	        k++;
	    }
	}
};

#endif