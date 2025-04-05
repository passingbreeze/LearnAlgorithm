#include <iostream>
#include <cmath>

using namespace std;

class player {
	int* score;
	int round;
public:
	player(int r) {
		round = r;
		score = new int[round];
		for (int i = 0; i < round; ++i)
			score[i] = 0;
	}

	player(const player& c) {
		round = c.round;
		score = new int[round];
		for (int i = 0; i < round; ++i)
			score[i] = c.score[i];
	}

	~player() {
		delete[] score;
	}

	int at(int i) const {
		return score[i];
	}

	void setscore(player& p) {
		for (int i = 0; i < round; ++i) {
			cin >> this->score[i] >> p.score[i];
			if (this->score[i] < 1 || this->score[i] > 1000) return;
			else if (p.score[i] < 1 || p.score[i] > 1000) return;
		}
	}

	int findwinner(const player& p) {
		int *diff = new int[round];
		int max = 0, i;

		for (int i = 0; i < round; ++i)
			diff[i] = score[i] - p.score[i];

		max = abs(diff[0]);
		for (i = 0; i < round; ++i) {
			if (max < abs(diff[i])) {
				max = abs(diff[i]);
				continue;
			}

			else if (max == abs(diff[i])) {
				if (diff[i] > 0)
					cout << 1;
				else if (diff[i] < 0)
					cout << 2;
				break;
			}

		}
		cout << ' ';
		delete[] diff;
		return max;
	}

	friend ostream& operator<<(ostream& os, const player& p) {
		for (int i = 0; i < p.round; ++i)
			os << p.at(i) << ' ';
		return os;
	}

};

int main()
{
	int r = 1;
	if (r < 1 || r > 10000)
		return -1;
	cin >> r;
	player si(r), ti(r);
	si.setscore(ti);
	cout << si.findwinner(ti) << endl;
	return 0;
}