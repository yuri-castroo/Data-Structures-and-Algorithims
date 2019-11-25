//Created by Giuseppe Rizzi 2018
//basic timer for timing code execution and outputting in millisecond

#include <ctime>
#include <stdexcept>

#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
	long long int start_time;
	long long int stop_time;
	bool going;
	bool finished;
public:
	Timer(): going(false), finished(false), start_time(0), stop_time(0) {}
	void start() {
		going=true;
		finished=false;
		start_time=clock();
	}	

	void stop() {
		if (going) {
			stop_time=clock();
			finished=true;
			going=false;
		}
	}
	long long int ms() {
		if (finished)
			//this code stolen from http://www.cplusplus.com/forum/beginner/40563/
			return (stop_time-start_time)/double(CLOCKS_PER_SEC)*1000;
		else
			 throw runtime_error("The timer hasn't been run or hasn't finished running.");
		 return -1;
	}
};

#endif
