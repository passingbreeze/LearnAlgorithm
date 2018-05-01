#include <iostream>

using namespace std;

class point {
	int x, y;
public:
	point(): x(0), y(0) {}
	point(int _x, int _y) : x(_x), y(_y) {}
	point(const point& p) : x(p.x), y(p.y) {}
	void set(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int read_x() const {
		// cout << "in point class : " << x << endl;
		return x;
	}
	int read_y() const {
		// cout << "in point class : " << y << endl;
		return y;
	}
};

class rectangle {
	point *bottomleft, *upperright;
	bool isEmpty;
public:
	rectangle() {
		isEmpty = true;
		point bl;
		point ur;
		bottomleft = &bl;
		upperright = &ur;
	}
	rectangle(int x1, int x2, int y1, int y2) {
		isEmpty = false;
		bottomleft->set(x1, y1);
		upperright->set(x2, y2);
	}

	rectangle(point bl, point ur) {
		isEmpty = false;
		bottomleft = &bl;
		upperright = &ur;
	}

	bool getEmpty() const {
		return isEmpty;
	}
	int blxcor() const { // x1
		return bottomleft->read_x();
	}
	int blycor() const { // y1
		return bottomleft->read_y();
	}
	int upxcor() const { // x2
		return upperright->read_x();
	}
	int upycor() const { // y2
		return upperright->read_y();
	}

	rectangle operator+(const rectangle& r) {

		int sblx = 0, surx = 0, sbly = 0, sury = 0;

		int blx = blxcor();
		int bly = blycor();
		int urx = upxcor();
		int ury = upycor();

		int r_blx = r.blxcor();
		int r_bly = r.blycor();
		int r_urx = r.upxcor();
		int r_ury = r.upycor();

		sblx = r_blx > blx ? blx : r_blx;
		sbly = r_bly > bly ? bly : r_bly;
		surx = r_urx >= urx ? r_urx : urx;
		sury = r_ury >= ury ? r_ury : r_bly;

		rectangle result(sblx, surx, sbly, sury);
		return result;

	}

	rectangle operator-(const rectangle& r) {
		rectangle result;
		int sblx = 0, surx = 0, sbly = 0, sury = 0;

		int blx = blxcor();
		int bly = blycor();
		int urx = upxcor();
		int ury = upycor();

		int r_blx = r.blxcor();
		int r_bly = r.blycor();
		int r_urx = r.upxcor();
		int r_ury = r.upycor();

		if (urx - r_blx >= 0 || blx - r_urx >= 0) {
			isEmpty = true;
			surx = 0;
			sury = 0;
			sblx = 0;
			sbly = 0;
		}

		else {
			isEmpty = false;
			surx = urx;
			sury = ury;
			sblx = r_blx;
			sbly = r_bly;
		}

		(result.bottomleft)->set(sblx, sbly);
		(result.upperright)->set(surx, sury);

		return result;
	}

	friend istream& operator>>(istream& is, rectangle& r) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		is >> x1 >> y1 >> x2 >> y2;

		point a(x1, y1);
		point b(x2, y2);

		r = rectangle(a, b);
		return is;
	}

	friend ostream& operator<<(ostream& os, rectangle& r) {
		os << "bottomleft point : (" << r.blxcor() << ", " << r.blycor() << "), ";
		os << "upperright point : (" << r.upxcor() << ", " << r.upycor() << ")\n";
		return os;
	}
};


int main()
{
	rectangle r1, r2, r3;
	cin >> r1;
	cin >> r2;
	cout << "r1 bottomleft : (" << r1.blxcor() << ", " << r1.blycor() << ")\n";
	cout << "r1 upperright : (" << r1.upxcor() << ", " << r1.upycor() << ")\n";

	cout << "r2 bottomleft : (" << r2.blxcor() << ", " << r2.blycor() << ")\n";
	cout << "r2 upperright : (" << r2.upxcor() << ", " << r2.upycor() << ")\n";

	if (r1.blxcor() > r1.upxcor() || r1.blycor() > r1.upycor()) {
		cerr << "not available values\n";
		return -1;
	}

	if (r2.blxcor() > r2.upxcor() || r2.blycor() > r2.upycor()) {
		cerr << "not available values\n";
		return -1;
	}


	r3 = r1 + r2;
	cout << r3;
	r3 = r1 - r2;
	if (r3.getEmpty()) {
		cerr << "Empty Rectangle\n";
		return -1;
	}
	cout << r3;
	return 0;
}
