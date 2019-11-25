#include <iostream>
#include <string>
#include <fstream>

#include <algorithm>
#include "ArrayStack.h"
using namespace std;

int main()
{
    std::ifstream instream;
    instream.open("sorted1d.txt");
    std::ofstream outfile("reversed1d.txt");
    int a;
    ArrayStack<int> test;
    if (instream)
    {
        // string line;
        // reads through the file line by line
        //while (!instream.eof())
        //{
            while (instream >> a){
                test.push(a);
            }
        //}

        
        while (!test.isEmpty()){
            outfile << test.pop() << endl;
        }
    }


    // if failed to open the file
    else
        cout << "Cannot open the file. Make sure the file name is correct" << endl;

    instream.close();

    return 0;
}