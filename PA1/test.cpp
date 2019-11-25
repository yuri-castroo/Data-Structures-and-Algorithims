#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#include "Stack.h"
#include "ArrayStack.h"
#include "DoublingArrayStack.h"
#include "LinkedStack.h"
#include "Timer.h"

using namespace std;

int main(){

	//ArrayStack<double> normArray; 
	//DoublingArrayStack<double> doubArray; 
	LinkedStack<double> linkArray;


	srand(time(NULL));
	Timer t; 
	
	t.start();
	for (int j = 0; j < 15000; j++){
		for (int i = 0; i < 1000; i++){
			double x = rand() % 10 + 1;
			//normArray.push(x);
			//doubArray.push(x);
			linkArray.push(x);
		}
		
	}	
	t.stop();

	cout<<"Code took " << t.ms() << "milliseconds" <<endl;
}