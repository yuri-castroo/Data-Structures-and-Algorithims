//UNSORTED PQ 
#ifndef UNSORTED_PQ_H
#define UNSORTED_PQ_H

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

class UnsortedPQ
{
private:
	// data here
	int numElements; 
public:
   list<Type> queueList;

   UnsortedPQ() : queueList() {

   }

   // Performs an insertion of "n" items from dataArray into the priority queue
   // BONUS: perform a bottomup heap construction for the heap.  Compare the time it takes to perform a
   // bottom up construction to inserting n items in your experimental section of your report.
   UnsortedPQ ( Type *dataArray, int n ){
   	list<Type> queueList(dataArray, dataArray+sizeof(dataArray)/sizeof(int));
   	// for(Type val:dataArray){
   	// 	queueList.push_back(val);
   	// }
   	numElements = queueList.size();
   }

   ~UnsortedPQ(void){
   }

   bool isEmpty(void){
   	return queueList.empty();
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

   	typename list<Type>::iterator min = queueList.begin();

   	typename list<Type>::iterator it = queueList.begin();

   	for(; it != queueList.end(); it++){
   		if(*it < *min){
   			min = it;
   		}
         //cout << *it << ", ";
   	}
      //cout << endl;

      Type elem = *min;
   	queueList.erase(min);
      numElements--;
      return elem;
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
