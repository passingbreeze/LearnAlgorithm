#include <iostream>

using namespace std;

class star {
	int n = 0;
public:
<<<<<<< HEAD
	star(int _n): n(_n) {}
	void decreasing() {
		for (int i = 0; i < n; ++i) {

=======
	star(int _n) : n(_n) {}
	void decreasing() const {
		for (int i = 0; i < n; ++i) {
			int n1 = i;
			int n2 = n - i;
			for (int j = 0; j < n1; ++j) cout << " ";
			for (int k = 0; k < n2; ++k) cout << "*";
			cout << endl;
>>>>>>> b6aa047cf949515f337abf3b232828b0f3f7a24f
		}
	}

};

<<<<<<< HEAD
int main()
{
	int n;
=======
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n = 0;
>>>>>>> b6aa047cf949515f337abf3b232828b0f3f7a24f
	cin >> n;
	star a(n);
	a.decreasing();
	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> b6aa047cf949515f337abf3b232828b0f3f7a24f
