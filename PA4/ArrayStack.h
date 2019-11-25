#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H 

#include "Stack.h"
#include <stdexcept>

template <class Type>
class ArrayStack : public Stack<Type>
{
  private:
    Type* s_array;
    int curr_sz; //curr_sz of stack 
    int cap; //capactiy 
  public:
    //FUNCTIONZZZ 
     ArrayStack() {
        cap = 10000; //set capacity of the array 
        s_array = new Type[cap]; //create new array
        curr_sz = -1; //no curr_sz yet, start outside stack 
     }

    ~ArrayStack(){
        delete[] s_array;
    }

     bool isEmpty() const {
          if (curr_sz < 0){
            return true; //if curr_sz is -1, nothing in stack
          }
          else{
            return false; 
          }
    }

    int size() const {
    //return the curr_sz counter + 1 for size (since it starts at 0)
     return (curr_sz + 1);
    }

    Type top() const {
    if (isEmpty()){
        throw std::out_of_range("Empty stack, nothing to top off");
      }
      else{
        return s_array[curr_sz];
     }
    }

    Type pop() {
      if (isEmpty()){
        throw std::out_of_range("Empty stack, nothing to pop off");
      }
      return s_array[curr_sz--];
    }


    void push(Type e){
        if (curr_sz + 1 == cap){
          resize(cap + 1000); // go to resize function and change array size to fit more in
        }
        curr_sz++;
        s_array[curr_sz] = e;
    }

    void resize(int newSize) { 
        Type *tempArray;
        tempArray = new Type[newSize];
        //copy over all elements from old array to new sized array
        for (int i=0; i < cap; i++){
          tempArray[i] = s_array[i];
        }
        // change capacity amount 
        cap = newSize; 
        //delete only array and assign new array to it 
        delete[] s_array;
        s_array = tempArray;
    }
};

#endif