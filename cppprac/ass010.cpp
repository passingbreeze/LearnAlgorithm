#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
	student** std;
	char name[20];
	unsigned age;
	char dept[20];
	float score;
public:
	student(int n) {
		std = new student*[n];
	}
	~student() {
		delete std;
	}

	int readFromText(char* filename, student** students) {
		ifstream ifs(filename);
		// if(ifs.is_open()){

		// }

	}
	void writeToBinary(char* filename, int n, student* students);
	int readFromBinary(char* filename, student** students);
	void writeToText(char* filename, int n, student* students);

};

int main()
{
	/* code */
	return 0;
}