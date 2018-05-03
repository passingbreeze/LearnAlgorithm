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
		return x;
	}
	int read_y() const {
		return y;
	}
};

class rectangle {
	point *bottomleft, *upperright;
	bool isEmpty;
public:
	rectangle() {
		isEmpty = true;
		bottomleft = new point();
		upperright = new point();
	}
	rectangle(int x1, int x2, int y1, int y2) {
		isEmpty = false;
		bottomleft = new point(x1, y1);
		upperright = new point(x2, y2);
	}

	rectangle(point bl, point ur) {
		isEmpty = false;
		bottomleft = new point(bl);
		upperright = new point(ur);
	}

	/*
		Compiler에 따라 다른 것 같다.
		clang은 굳이 destructor가 없어도 돌아가긴한다.

		~rectangle() {
			delete[] bottomleft;
			delete[] upperright;
		}
	*/
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

	rectangle operator++(int a) {
		rectangle result(*this);

		int blx = blxcor();
		int bly = blycor();
		int urx = upxcor();
		int ury = upycor();

		if (result.isEmpty == true) result.isEmpty = false;

		(result.bottomleft)->set(blx + a, bly + a);
		(result.upperright)->set(urx + a, ury + a);

		return result;
	}

	rectangle& operator++() {
		return *this;
	}

	rectangle operator+(const rectangle& r) {

		int sblx = 0, surx = 0, sbly = 0, sury = 0;
		rectangle result(sblx, surx, sbly, sury);

		int blx = blxcor();
		int bly = blycor();
		int urx = upxcor();
		int ury = upycor();

		int r_blx = r.blxcor();
		int r_bly = r.blycor();
		int r_urx = r.upxcor();
		int r_ury = r.upycor();

		if (blx == r_blx || urx == r_urx || bly == r_bly || ury == r_ury) {
			result.isEmpty = true;
			return result;
		}

		sblx = r_blx > blx ? blx : r_blx;
		sbly = r_bly > bly ? bly : r_bly;
		surx = r_urx >= urx ? r_urx : urx;
		sury = r_ury >= ury ? r_ury : r_bly;

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

		if (r_blx - urx >= 0 || r_blx - urx <= 0 || bly - r_ury >= 0 || r_bly - ury >= 0) {
			isEmpty = true;
			surx = 0;
			sury = 0;
			sblx = 0;
			sbly = 0;
		}

		else {
			isEmpty = false;
			if (r_urx > urx && r_blx > blx) {
				surx = urx;
				sury = ury;
				sblx = r_blx;
				sbly = r_bly;
			}

			else if (r_urx < urx && r_blx < blx) {
				surx = r_urx;
				sury = r_ury;
				sblx = blx;
				sbly = bly;
			}

			else {
				isEmpty = true;
				surx = 0;
				sury = 0;
				sblx = 0;
				sbly = 0;
			}

		}
		cout << surx << ' ' << sury << ' '; // for debug
		cout << sblx << ' ' << sbly << endl;
		(result.bottomleft)->set(sblx, sbly);
		(result.upperright)->set(surx, sury);

		return result;
	}

	friend istream& operator>>(istream& is, rectangle& r) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		is >> x1 >> y1 >> x2 >> y2;
		(r.bottomleft)->set(x1, y1);
		(r.upperright)->set(x2, y2);
		return is;
	}

	friend ostream& operator<<(ostream& os, rectangle& r) {
		os << "bottomleft point : (" << (r.bottomleft)->read_x() << ", " << (r.bottomleft)->read_y() << "), ";
		os << "upperright point : (" << (r.upperright)->read_x() << ", " << (r.upperright)->read_y() << ")\n";
		return os;
	}
};


int main()
{
	rectangle r1, r2, r3;
	cin >> r1;
	cin >> r2;
	cout << "r1 -> " << r1;
	cout << "r2 -> " << r2;

	if (r1.blxcor() > r1.upxcor() || r1.blycor() > r1.upycor()) {
		cerr << "not available values\n";
		return -1;
	}

	if (r2.blxcor() > r2.upxcor() || r2.blycor() > r2.upycor()) {
		cerr << "not available values\n";
		return -1;
	}


	r3 = r1 + r2;
	if (r3.getEmpty()) {
		cerr << "Empty Rectangle\n";
		return -1;
	}
	cout << r3;
	r3 = r1 - r2;
	if (r3.getEmpty()) {
		cerr << "Empty Rectangle\n";
		return -1;
	}
	cout << r3;
	return 0;
}
