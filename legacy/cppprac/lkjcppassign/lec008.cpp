#include <iostream>

using namespace std;

class Point {
	int X;
	int Y;
	int Z;
public:
	void printout() {
		cout << "(" << X << "," << Y << "," << Z << ")\n";
	}
	void setVaues(int &m) {
		X = Y = Z = m++;
	}

	void setValues(int a, int b, int c);
};

int main()
{
	Point myPoint;
	int a = 10;
	myPoint.setValues(a);
	cout << "a = " << a << endl;
	myPoint.setValues(30); //??
	return 0;
}
