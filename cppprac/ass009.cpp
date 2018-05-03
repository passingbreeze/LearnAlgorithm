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
	rectangle(): bottomleft(new point()), upperright(new point()), isEmpty(true) {}
	rectangle(int x1, int y1, int x2, int y2): bottomleft(new point(x1, y1)), upperright(new point(x2, y2)) {
		isEmpty = false;
		if (x1 == x2 || y1 == y2) {
			isEmpty = true;
		}
	}

	rectangle(point bl, point ur): bottomleft(new point(bl)), upperright(new point(ur)) {
		isEmpty = false;
		if (bl.read_x() == ur.read_x() || bl.read_y() == ur.read_y()) {
			isEmpty = true;
		}
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

	rectangle operator++(int) { // postfix
		rectangle result(*this);

		int blx = bottomleft->read_x();
		int bly = bottomleft->read_y();
		int urx = upperright->read_x();
		int ury = upperright->read_y();

		if (result.isEmpty == true) result.isEmpty = false;

		(result.bottomleft)->set(blx - 1, bly - 1);
		(result.upperright)->set(urx + 1, ury + 1);

		if (result.blxcor() < 0 || result.blycor() < 0) {
			(result.bottomleft)->set(0, 0);
		}
		return result;
	}

	rectangle& operator++() {// prefix
		int revblx = blxcor() - 1;
		int revbly = blycor() - 1;
		int revurx = upxcor() + 1;
		int revury = upycor() + 1;
		if (revblx < 0 || revbly < 0) {
			revblx = 0;
			revbly = 0;
		}

		(bottomleft)->set(revblx, revbly);
		(upperright)->set(revurx, revury);
		return *this;
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

		if (urx <= r_urx) {
			sblx = blx;
			sbly = bly;
			surx = r_urx;
			sury = ury <= r_ury ? r_ury : ury;
		}

		else if (urx >= r_urx) {
			sblx = r_blx;
			sbly = r_bly;
			surx = ury >= r_ury ? urx : r_ury;
			sury = ury;
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

		else if (blx <= r_blx) {
			sblx = urx <= r_urx ? r_blx : blx;
			surx = urx <= r_urx ? urx : r_urx;
		}

		else {
			sblx = urx <= r_urx ? blx : r_blx;
			surx = urx <= r_urx ? r_blx : blx;
		}

		if (ury <= r_bly || r_ury <= bly) { // r1 < r2 || r1 > r2
			return result;
		}

		else if (bly <= r_bly) {
			sbly = r_bly;
			sury = ury <= r_ury ? ury : r_ury;
		}

		else {
			sbly = bly;
			sury = ury <= r_ury ? ury : r_ury;
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
	rectangle rec(2, 2, 5, 5); // practice code from class
	rectangle rec2(3, 3, 7, 7); // practice code from class
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

	rectangle newrec = rec++; // practice code from class
	rectangle result = newrec + rec2; // practice code from class

	cout << newrec;
	cout << result;

	return 0;
}