#include <iostream>
#include <fstream>
#include <string>

class student {
	char name[20];
	unsigned age;
	char dept[20];
	float score;
public:
	student();

	int readFromText(char* filename, student** students) {
		fstream fs;
		fs.open(filename);

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