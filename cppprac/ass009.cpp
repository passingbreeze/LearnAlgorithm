#include <iostream>

using namespace std;

class point {
	int x, y;
public:
	point(int _x, int _y): x(_x), y(_y) {}
	void setx(int _x) {
		x = _x;
	}
	void sety(int _y) {
		y = _y;
	}
	int readx() const {
		return x;
	}
	int ready() const {
		return y;
	}
};

class rectangle {
	point *bottomleft, *upperright;
	bool isEmpty = true;
public:
	rectangle() {
		bottomleft->setx(0);
		bottomleft->sety(0);
		upperright->setx(0);
		upperright->sety(0);
	}
	rectangle(int x1, int x2, int y1, int y2) {
		bottomleft->setx(x1);
		bottomleft->sety(y1);
		upperright->setx(x2);
		upperright->sety(y2);
	}
	rectangle(point bl, point ur) {
		bottomleft = &bl;
		upperright = &ur;
	}
	friend istream& operator>>(istream& is, rectangle& r) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		cin >> x1 >> x2 >> y1 >> y2;
		if (x1 > x2 || y1 > y2) {
			cerr << "not available values\n";
			return is;
		}

		point p1(x1, y1);
		point p2(x2, y2);
		r(p1, p2);
		return is;
	}

	rectangle operator()(const point p1, const point p2) {
		return rectangle(p1, p2);
	}

	rectangle operator+(const rectangle& r) {
		rectangle result;

		int sumx = 0, sumy = 0;
		int blx = ((r.bottomleft)->readx());
		int bly = ((r.bottomleft)->ready());
		int urx = ((r.upperright)->readx());
		int ury = ((r.upperright)->ready());

		sumx = blx > urx ? urx : blx < urx ? blx : urx;
		sumy = bly > ury ? ury : bly < ury ? bly : ury;


		return result;
	}

	rectangle operator-(const rectangle& r) {
		rectangle result;
		return result;
	}

};


int main()
{
	/* code */
	return 0;
}