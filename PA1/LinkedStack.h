#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdexcept>
#include "Stack.h"

template <class Type>
class Node{
public:
	Node<Type>* next;
	Node<Type>* prev;
	Type element;

	Node(Type e) : element(e) {}
	~Node(){
		
	}
};

template <class Type>
class LinkedStack{
private:
	int numNodes;
	Node<Type>* head;
	Node<Type>* tail;
public:

	LinkedStack(){
		head = nullptr;
		tail = nullptr;
		numNodes = 0;
	}

	~LinkedStack(){
		Node<Type>* temp; 
		while(head->next != nullptr){
			temp = head->next;
			delete head;
			head = temp;
		}
		delete head;
	}

	bool isEmpty() const{
		if (numNodes == 0){
			return true; 
		}
		else{
			return false;
		}
	}

	int size() const{
		return numNodes;
	}

	Type top() const{
		if (tail == nullptr){
			throw std::out_of_range("Empty stack, nothing to pop off");	
		}
		return tail->element; 
	}

	Type pop() {
		
		if (tail == nullptr){
	    	throw std::out_of_range("Empty stack, nothing to pop off");
	    }
	  	Type temp = tail->element;
	  	tail = tail->prev; 
	  	delete tail->next;
	  	tail->next = nullptr;
	  	numNodes--;
	  	return temp;
	}

	void push(Type x){
		Node<Type>* new_node = new Node<Type>(x);

		if(tail == nullptr){
			head = tail = new_node;
			numNodes++;
		}
		else{
			new_node->prev = tail;
			tail->next = new_node;
			tail = tail->next;
			numNodes++;
		}
	}
};

#endif