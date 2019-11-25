#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

int main(){
	ofstream myFile;
	int num; 
	myFile.open("randddd2.txt");
	for (int i = 1; i <= 1000000; i++){
		num = rand() % 1000 + 1; 
		myFile << num << endl;
	}
	myFile.close();
	return 0;
}