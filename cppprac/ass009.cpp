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
		if (x1 == x2 || y1 == y2) {
			isEmpty = true;
		}
		bottomleft = new point(x1, y1);
		upperright = new point(x2, y2);
	}

	rectangle(point bl, point ur) {
		isEmpty = false;
		if (bl.read_x() == ur.read_x() || bl.read_y() == ur.read_y()) {
			isEmpty = true;
		}
		bottomleft = new point(bl);
		upperright = new point(ur);
	}

	rectangle(const rectangle& r) {
		isEmpty = r.isEmpty;
		bottomleft = new point(*(r.bottomleft));
		upperright = new point(*(r.upperright));
	}

	~rectangle() {
		delete upperright;
		delete bottomleft;
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
		rectangle result(sblx, surx, sbly, sury);

		int blx = bottomleft->read_x();
		int bly = bottomleft->read_y();
		int urx = upperright->read_x();
		int ury = upperright->read_y();

		int r_blx = (r.bottomleft)->read_x();
		int r_bly = (r.bottomleft)->read_y();
		int r_urx = (r.upperright)->read_x();
		int r_ury = (r.upperright)->read_y();

		if (urx < r_urx && ury < r_ury) {
			sblx = r_blx > blx ? blx : r_blx;
			sbly = r_bly > bly ? bly : r_bly;
			surx = r_urx >= urx ? r_urx : urx;
			sury = r_ury >= ury ? r_ury : r_bly;
		}

		else if (r_urx < urx && r_ury < ury) {
			sblx = blx > r_blx ? r_blx : blx;
			sbly = bly > r_bly ? r_bly : bly;
			surx = urx >= r_urx ? urx : r_urx;
			sury = ury >= r_ury ? ury : bly;
		}

		(result.bottomleft)->set(sblx, sbly);
		(result.upperright)->set(surx, sury);
		if (sblx != surx && sbly != sury) {
			result.isEmpty = false;
		}
		return result;

	}

	rectangle operator-(const rectangle& r) {
		int sblx = 0, surx = 0, sbly = 0, sury = 0;
		rectangle result(sblx, sbly, surx, sury);

		int blx = bottomleft->read_x();
		int bly = bottomleft->read_y();
		int urx = upperright->read_x();
		int ury = upperright->read_y();

		int r_blx = (r.bottomleft)->read_x();
		int r_bly = (r.bottomleft)->read_y();
		int r_urx = (r.upperright)->read_x();
		int r_ury = (r.upperright)->read_y();


		if (urx <= r_blx || r_urx <= blx) { // r1 < r2 || r1 > r2
			return result;
		}

		else if (r_blx < urx) {
			sblx = r_blx;
			surx = urx;
		}

		else if (blx < r_urx) {
			sblx = blx;
			surx = r_urx;
		}


		if (ury <= r_bly || r_ury <= bly) { // r1 < r2 || r1 > r2
			return result;
		}

		else if (r_bly < ury) {
			sbly = r_bly;
			sury = ury;
		}

		else if (r_ury > bly) {
			sbly = bly;
			sury = r_ury;
		}

		(result.bottomleft)->set(sblx, sbly);
		(result.upperright)->set(surx, sury);
		if (sblx != surx && sbly != sury) {
			result.isEmpty = false;
		}
		return result;
	}

	rectangle& operator=(const rectangle& r) {
		isEmpty = r.isEmpty;
		bottomleft->set(r.blxcor(), r.blycor());
		upperright->set(r.upxcor(), r.upycor());
		return *this;
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
	cout << "result of + operation -> ";
	if (r3.getEmpty() == false) cout << r3;
	else cout << "Empty Rectangle\n";

	r3 = r1 - r2;
	cout << "result of - operation -> ";
	if (r3.getEmpty() == false) cout << r3;
	else cout << "Empty Rectangle\n";
	return 0;
}
