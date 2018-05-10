#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student {
	char name[20];
	unsigned age;
	char dept[20];
	float score;
public:
	student(){}
	int readFromText(char* filename, student** students) {
		int n = 0;
		ifstream ifs(filename);

		if(!(ifs.is_open())){
			cerr << "No Input File." << endl;
			return -1;
		}

		ifs >> n;
		for (int i = 0; i < n; ++i){
			ifs.get((*students)[i].name, 20);
			ifs.seekg(21,ifs.beg);
			ifs>>(*students)[i].age;
			ifs.seekg(24,ifs.beg);
			ifs.get((*students)[i].dept, 20);
			ifs.seekg(44,ifs.beg);
			ifs >> (*students)[i].score;
			cout << (*students)[i].name << ' ' << (*students)[i].age << ' ' << (*students)[i].dept << ' ' << (*students)[i].score << endl;
		}
		return n;
	}
	void writeToBinary(char* filename, int n, student* students);
	int readFromBinary(char* filename, student** students);
	void writeToText(char* filename, int n, student* students);

};

int main()
{
	student* std = new student[100]; // get heap address
	int stdnum = 0;
	char file[512] = "\0";
	cout << "Enter Input File name : ";
	cin >> file;
	
	stdnum = std->readFromText(file, &std);

	delete[] std;
	return 0;
}
