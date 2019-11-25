#ifndef DOUBLINGARRAYSTACK
#define DOUBLINGARRAYSTACK

#include"Stack.h"
#include <stdexcept>

template <class Type>
class DoublingArrayStack : public Stack<Type>
{
private:
Type *s2_array;
  int curr_sz2; //current size of stack 
  int cap2; //capactiy 

public:
  //FUNCTIONZZ #2
  DoublingArrayStack() {
    cap2 = 8; //set capacity of the array 
    s2_array = new Type[cap2]; //create new array
    curr_sz2 = -1; //no curr_sz yet, start outside stack 
  }

  ~DoublingArrayStack(){
    delete[] s2_array;
  }

  bool isEmpty() const {
    if (curr_sz2 < 0){
      return true; //if curr_sz is -1, nothing in stack
    }
    else{
      return false; 
    }
  }

  int size() const{
    return (curr_sz2 +1);
  }

  Type top() const {
    if (isEmpty()){
        throw std::out_of_range("Empty stack, nothing to pop off");
      }
    return s2_array[curr_sz2];
 }


  Type pop(){
    if (isEmpty()){
      throw std::out_of_range("Empty stack, nothing to pop off");
    }
     //return the curr_sz of the array and then increment the curr_sz counter down 
    return s2_array[curr_sz2 --]; 
 }

  void push (Type e) {
    if (++curr_sz2 == cap2 -1){
      resize(cap2 * 2);
    }
    s2_array[curr_sz2] = e;
  }

   void resize(int newSize) {
      Type *tempArray;
      tempArray = new Type[newSize];
      //copy over all elements from old array to new sized array
      for (int i=0; i < cap2; i++){
        tempArray[i] = s2_array[i];
      }

      cap2 = newSize;
       //delete only array and assign new array to it 
      delete[] s2_array;
      s2_array = tempArray;
  }

};

#endif