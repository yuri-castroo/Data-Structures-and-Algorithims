//Yuri Castr0
//UIN: 626003324
//CSCE 221-200
//1/22/17
#include <iostream>
using namespace std; 

struct Point 
{
	int x;
	int y; 
	Point(){
		x = 0;
		y = 0;
	}
	Point(int i, int j){
		x = i;
		y = j; 
	}
	Point& operator =(Point &point){
		x = point.x;
		y = point.y; 
		return *this;
	}
	int get_x(){
		return x;
	}
	int get_y(){
		return y;
	}
	void set_x(int a){
		x = a;
	}
	void set_y(int b){
		y = b;
	}
};

class Shape: protected Point{
protected: 
	Point m_p; 
	virtual void Print() = 0; 
};

class Circle: public Shape{
public: 
	Point c;
	Circle(int r, int a, int b){
		c.set_x(a);
		c.set_y(b);
		radius = r; 
	}
	void Print(){
		cout << "Circle at postion " << c.get_x() << "," << c.get_y() << " with radius " << radius << endl; 
	}
private:
	int radius; 
};

class Square: public Shape{
public:
	Point z; 
	Square(int s, int a, int b){
		z.set_x(a);
		z.set_y(b);
		sides = s; 
	}
	void Print(){
		cout << "Square at postion " << z.get_x() << "," << z.get_y() << " with side lengths of " << sides << endl; 
	}
private: 
	int sides;
};

int main()
{
	Square square(5,1,2);
	square.Print();
	Circle circle(3,2,1);
	circle.Print(); 
	return 0;
}