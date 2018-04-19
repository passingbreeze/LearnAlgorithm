#include <iostream>
#include <string>

using namespace std;

class tts {
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int dday;
	int gday;
	int mon;
public:
	tts() {
		mon = 0;
		gday = 0;
	}
	void getday(int m, int d) {
		mon = m;
		gday = d;
		for (int i = 0; i < mon - 1; ++i)
			gday += month[i];
		dday = gday % 7;
		cout << day[dday] << endl;
	}
}; // two thousand seven

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int m, n;
	tts a;
	cin >> m >> n;
	a.getday(m, n);
	return 0;
}