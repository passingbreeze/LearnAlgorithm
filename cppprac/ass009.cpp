#include <iostream>

using namespace std;

class point {
	int x = 0, y = 0;
public:
	point() {}
	point(int _x, int _y): x(_x), y(_y) {}
	void setx(int _x) {
		x = _x;
	}
	void sety(int _y) {
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
	bool isEmpty = true;
public:
	rectangle() {
		point bl;
		point ur;
	}
	rectangle(int x1, int x2, int y1, int y2) {
		point bl(x1, y1);
		point ur(x2, y2);
	}
	rectangle(point bl, point ur) {
		bottomleft = &bl;
		upperright = &ur;
	}

	int length() const {
		int x1 = bottomleft->read_x();
		int x2 = upperright->read_x();

		return x2 >= x1 ? x2 - x1 : x1 - x2;
	}

	int height() const {
		int y1 = bottomleft->read_y();
		int y2 = upperright->read_y();

		return y2 >= y1 ? y2 - y1 : y1 - y2;
	}

	rectangle operator+(const rectangle& r) {

		int sblx = 0, surx = 0, sbly = 0, sury = 0;

		int blx = bottomleft->read_x();
		int bly = bottomleft->read_y();
		int urx = upperright->read_x();
		int ury = upperright->read_y();

		int r_blx = ((r.bottomleft)->read_x());
		int r_bly = ((r.bottomleft)->read_y());
		int r_urx = ((r.upperright)->read_x());
		int r_ury = ((r.upperright)->read_y());

		if (r_urx >= urx && r_ury >= ury) {
			surx = r_urx;
			sury = r_ury;
		} else if (r_urx < urx && r_ury < ury) {
			surx = urx;
			sury = ury;
		}

		if (r_blx >= blx && r_bly >= bly) {
			sblx = blx;
			sbly = bly;
		} else if (r_blx < blx && r_bly < bly) {
			sblx = r_blx;
			sbly = r_bly;
		}

		rectangle result(sblx, surx, sbly, sury);
		return result;

	}

	rectangle operator-(const rectangle& r) {

		int sblx = 0, surx = 0, sbly = 0, sury = 0;

		int blx = bottomleft->read_x();
		int bly = bottomleft->read_y();
		int urx = upperright->read_x();
		int ury = upperright->read_y();

		int r_blx = ((r.bottomleft)->read_x());
		int r_bly = ((r.bottomleft)->read_y());
		int r_urx = ((r.upperright)->read_x());
		int r_ury = ((r.upperright)->read_y());

		if ((blx >= r_blx && urx >= r_urx) && (bly >= r_bly && ury >= r_ury)) {
			sblx = r_blx;
			surx = r_urx;
			sbly = r_bly;
			sury = r_ury;
		}

		else if ((blx < r_blx && urx < r_urx) && (bly < r_bly && ury < r_ury)) {
			sblx = blx;
			surx = urx;
			sbly = bly;
			sury = ury;
		}

		rectangle result;
		return result;
	}


	friend istream& operator>>(istream& is, rectangle& r) {
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		cin >> x1 >> x2 >> y1 >> y2;
		if (x1 > x2 || y1 > y2) {
			cerr << "not available values\n";
			return is;
		}
		(r.bottomleft)->setx(x1);
		(r.bottomleft)->sety(y1);
		(r.upperright)->setx(x2);
		(r.upperright)->sety(y2);
		return is;
	}
};


int main()
{
	/* code */
	return 0;
}