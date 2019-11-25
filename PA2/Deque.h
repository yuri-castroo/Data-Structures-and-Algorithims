/*
Yuri Castro 
CSCE 221 - 200
2-23-18
Programming Assignment 2 - Deques and Doubly Lists
*/

#ifndef DEQUE_H
#define DEQUE_H

#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

template <class Type>
class Node{
public:
   Node<Type>* next;
   Node<Type>* prev;
   Type element;

   Node(Type e) : element(e) {}
   ~Node(){}
};

template <class Type>
class Deque
{
private:
	// data here
   int numNodes;
   Node<Type>* head;
   Node<Type>* tail;

public:
   Deque(void){
      head = nullptr;
      tail = nullptr;
      numNodes = 0;
   }

   //deletes all the elements from deque 
   ~Deque(void){
      Node<Type>* temp; 
      //only need to delete if there is something to delete
      if (head != nullptr){
         while(head->next != nullptr){
            temp = head->next;
            delete head;
            head = temp;
         }
         
            delete head;
      }
   }
//debugging function
/*
   void printList(){
      cout << "\n----Listing---" << endl;
      Node<Type>* temp = head;
      if (head == nullptr){
         cout << "HEAD null" << endl;
      } else {
         cout << "Head: " << head->element << endl;
      }
      if (tail == nullptr){
         cout << "tail null" << endl;
      } else {
         cout << "Tail: " << tail->element << endl;
      }
      while (temp != nullptr){
         // cout << "Printing" << endl;
         cout << temp->element << " ";
         temp = temp->next;
      }
      cout << endl;
      
      temp = tail;
      while (temp != nullptr){
         cout << temp->element << " ";
         temp = temp->prev;
      }

      cout << "\n----Listing----" << endl;
   }
*/

   //says if deque is empty or not
   bool isEmpty(void) const{
      if (numNodes == 0){
         return true; 
      }
      else{
         return false;
      }
   }

   //returns the number of elements 
   int size(void) const{
      return numNodes;
   }

   //returns the front item of queue
   Type first(void) throw(exception){
     if (head == nullptr){
         throw std::out_of_range("Empty deque");
     }
     else{
         return head->element;
     }
   }

   //returns the last item of the queue
   Type last(void) throw(exception){
      if (tail == nullptr){
         throw std::out_of_range("Empty deque");
      }
      else{
         return tail->element;
      }
   }

   //add element front of deque
   void insertFirst(Type o){
      Node<Type>* new_node = new Node<Type>(o);

      if (head == nullptr){
         head = new_node;
         tail = new_node;
         head->prev = tail->prev = nullptr;
         head->next = tail->next = nullptr;
         numNodes++;
      }
      else {
         //assign the new node's next to head
         new_node->next = head;
         // the new head is the new node
         head = new_node;
         //nothing behind the new head
         head->prev = nullptr;
         //the old head's prev is now the new node 
         new_node->next->prev = new_node;
         numNodes++;
      }
   }

   //add element back of deque 
   void insertLast(Type o){
      Node<Type>* new_node = new Node<Type>(o);

      if(tail == nullptr){
         head = new_node;
         tail = new_node;
         head->prev = tail->prev = nullptr;
         head->next = tail->next = nullptr;
         numNodes++;
      }
      else{
         new_node->prev = tail;
         tail = new_node;
         tail->next = nullptr;
         //old tail's next is the new node
         new_node->prev->next = new_node;
         numNodes++;
      }
   }

   //delete item from front
   Type removeFirst(void) throw(exception){
      if (head == nullptr){
         //Remove First pointer null
         throw std::out_of_range("Empty deque");
      }
      else{
         Type temp = head->element;
         //if only one element 
         if (numNodes == 1){
            //only one node left, assigning both to null
            tail = nullptr;
            delete head;
            head = nullptr;
         }
         else{
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
         }
         numNodes--; 
         return temp;
      }
   }

   //delete item from back
   Type removeLast(void) throw(exception){
      //Currently removing last
      if (tail == nullptr){
         //Remove Last pointer null
         throw std::out_of_range("Empty deque");
      }
      else{
         Type temp = tail->element;
         //if only one element 
         if (numNodes == 1){
            //only one node left, assigning both to null
            head = nullptr;
            delete tail;
            tail = nullptr;
         }
         else{
            tail = tail->prev; 
            delete tail->next;
            tail->next = nullptr;
         }
         // Decrements count of elements by 1
         numNodes--;
         return temp;   
      }
   }
};

#endif