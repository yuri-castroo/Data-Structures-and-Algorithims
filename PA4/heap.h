#ifndef HEAP_H
#define HEAP_H

// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
#include <stdexcept>
using namespace std;
 
// A class for Min Heap
template <class Type>
class Heap
{
    Type *arr; // pointer to array of elements in heap
    int cap; // maximum possible size of min heap
    int numElements; // Current number of elements in min heap
public:
 
    Heap(int N){
        numElements = 0;
        cap = N;
        arr = new Type[cap];
    }

    ~Heap(){
        delete[] arr;
    }

    int parent(int i){
        return (i-1)/2;
    }
 
    int left(int i){
        return (2*i + 1);
    }
 
    int right(int i){
        return (2*i + 2);
    }
 
    bool isEmpty(void){
    if (numElements == 0){
         return true; 
      }
      else{
         return false;
      }
    }

    int minValue() throw(exception){
        if (numElements <= 0){
            throw std::out_of_range("Empty heap");
        }
        return arr[0];
        //root should be min 
    } 
    
    void insertItem(int data){
        if (numElements == cap)
        {
            cout << "no space left" << endl;
            return;
        }
     
        numElements++;
        int i = numElements - 1;
        arr[i] = data;
     
        while (i != 0 && arr[parent(i)] > arr[i])
        {
           Type temp = arr[i];
           arr[i] = arr[parent(i)];
           arr[parent(i)] = temp;

           i = parent(i);
        }
        minHeapify(0);
    }
     
    void changeKey(int i, Type new_val){
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            Type temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }
     
    int removeMin() throw(exception){
        if (numElements <= 0)
            throw std::out_of_range("Empty heap");
        if (numElements == 1)
        {
            numElements--;
            return arr[0];
        }
     
        int min = arr[0];
        //change the new root to be the last node in the heap
        arr[0] = arr[numElements-1];
        /*
        for (int i = 0; i < numElements; i++){
            arr[i] = arr[i+1];
        }
        arr[numElements-1] = 0;
        */
        numElements--;
        //heapify from the new root 
        minHeapify(0);
     
        return min;
    }
     
    void minHeapify(int i){
        int l = left(i);
        int r = right(i);
        int min = i;
        if (l < numElements && arr[l] < arr[min])
            min = l;
        if (r < numElements && arr[r] < arr[min])
            min = r;
        if (min != i)
        {
            Type temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            minHeapify(min);
        }
    }
};

#endif
