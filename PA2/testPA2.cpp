#include <stdio.h>
#include <iostream>
#include "Deque.h"

using namespace std;

int main ()
{
	Deque<int> intQ;

	cout << "isEmpty(1): " << intQ.isEmpty() << endl;;
	intQ.insertFirst(4);
	cout << "removeLast(4): " << intQ.removeLast() << endl;
	intQ.insertFirst(5);
	intQ.insertFirst(12);
	intQ.insertLast(7);
	intQ.insertLast(13);
	cout << "first(12): " << intQ.first() << endl;
	cout << "last(13): " << intQ.last() << endl;
	cout << "size(4): " << intQ.size() << endl;
	cout << "isEmpty(0): " << intQ.isEmpty()<< endl;
	cout << "removeLast(13) : " << intQ.removeLast() << endl;
	cout << "removeLast(7) : " << intQ.removeLast() << endl;
	cout << "removeLast(5) : " << intQ.removeLast() << endl;
	cout << "removeFirst(12) : " << intQ.removeFirst() << endl;
	cout << "size(0): " << intQ.size() << endl;
	cout << "isEmpty(1): " << intQ.isEmpty() << endl;

	return 0;
}

