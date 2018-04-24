#include <iostream>

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

	void findwinner(const player& p) {
		int *diff = new int[round];
		int *vic = new int[round];
		int max = 0, q = 0;

		for (int i = 0; i < round; ++i) {
			diff[i] = score[i] - p.score[i];
			if (diff[i] > 0)
				vic[i] = 1;
			else if (diff[i] < 0) {
				diff[i] = (-diff[i]);
				vic[i] = 2;
			}
		}

		max = diff[0];
		q = vic[0];
		for (int i = 0; i < round; ++i) {
			if (max < diff[i]) {
				max = diff[i];
				q = vic[i];
			}
		}
		cout << q << ' ' << max << endl;

		delete[] diff;
		delete[] vic;
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
	si.findwinner(ti);
	return 0;
}