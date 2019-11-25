#include <iostream>
#include <math.h>
using namespace std; 

template<class T, int n>
class Point{
private: 
	T m_array[n];
public:
	Point(){
		for (int i = 0; i < n; i++){
			m_array[i] = 0; 
		}
	}
	void setPoint(int elem, T val){
		m_array[elem] = val;
	}
	void getPoint() {
		for (int i = 0; i < n; i++){
			cout << m_array[i] << endl;
		}
	}
	
	T getDistance(Point &a, Point &b){
		T sum = 0; 
		for (int i = 0; i < n; i++){
			sum += pow((a.m_array[i]-b.m_array[i]),2);
		}
		return sqrt(sum);
	}
};

int main(){
	Point<double, 3> p1; 
	Point<double, 3> p2;
	p1.setPoint(1,3);
	p2.setPoint(2,2); 

	Point<int, 2> p3; 
	Point<int, 2> p4; 
	p3.setPoint(0,1);
	p4.setPoint(1,2);

	cout << "Distance1: " << p1.getDistance(p1,p2) << endl;
	cout << "Distance2: " << p4.getDistance(p3,p4) << endl;
	return 0;
}