//UNSORTED PQ 
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <exception>
#include <iostream>
#include <list>

using namespace std;

/**
 * Note: in order to try to make things easier, the queue below will only have a single type of value
 * in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would
 * make a priority queue that stored an object with both the key/value in it and a comparison operator
 * that only compared the keys.
 */


template <class Type>

class PriorityQueue
{
private:
	// data here
	int numElements; 
public:
   list<Type> queueList;

   PriorityQueue(void){
      list<Type> queueList;
   }

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   PriorityQueue ( Type *dataArray, int n ){
   	list<Type> queueList(dataArray, dataArray+sizeof(dataArray)/sizeof(int));
   	// for(Type val:dataArray){
   	// 	queueList.push_back(val);
   	// }
   	numElements = queueList.size();
   }

   ~PriorityQueue(void){
      list<Type> queueList;
   }

   bool isEmpty(void){
   	if (numElements == 0){
         return true; 
      }
      else{
         return false;
      }
   }

   int size(void){
   	return numElements;
   }

   // inserts a piece of data into the priority queue
   void insertItem ( Type data ){
   	queueList.push_back(data);
      numElements++;
   }

   // removes and returns the minimum value in the queue
   // throws an exception if the queue is empty
   Type removeMin ( void ) throw(exception){
      if (numElements == 0){
         throw std::out_of_range("Empty list");
      }

   	Type min = queueList.front();

   	typename list<Type>::iterator it;

   	for(it = queueList.begin(); it != queueList.end(); it++){
   		Type now = *it;
   		if(now<min){
   			min=now;
   		}
   	}

   	queueList.remove(min);
      numElements --;
      return min;
   }
   // to print out the list. 
   void toString(){
      typename list<Type>::iterator it;

      for(it = queueList.begin(); it != queueList.end(); ++it){
         cout << *it << endl;
      }
   }

   // return the minimum value in the queue without removing it
   // throws an exception if the queue is empty
   Type minValue ( void ) throw(exception){
      if (numElements == 0){
         throw std::out_of_range("Empty list");
      }

      Type min = queueList.front();

      typename list<Type>::iterator it;

      for(it = queueList.begin(); it != queueList.end(); it++){
         Type now = *it;
         if(now<min){
            min=now;
         }
      }
      return min;
   }
};

#endif
