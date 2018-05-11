#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class student {
	char name[20];
	unsigned age;
	char dept[20];
	float score;
public:
	student(){}

	int str_to_int(string s){
		istringstream iss(s);
		int n = 0;

		iss >> n;
		return n;
	}

	double str_to_double(string s){
		istringstream iss(s);
		double f = 0.0;

		iss >> f;
		return f;
	}

	int readFromText(char* filename, student** students) {
		int n = 0;
		char std_age[3], std_score[5];
		
		ifstream ifs(filename);

		if(!(ifs.is_open())){
			cerr << "No Input File." << endl;
			return -1;
		}
		ifs >> n; // the number of records

		for (int i = 0; i < n; ++i){
			ifs.readsome((*students)[i].name, 20);			
			ifs.readsome(std_age, 3);
			(*students)[i].age = (unsigned)str_to_int(std_age);
			
			ifs.readsome((*students)[i].dept, 20);			
			ifs.readsome(std_score, 5); // include newline character
			(*students)[i].score = (float)str_to_double(std_score);
		}
		ifs.close();
		return n;
	}

	void writeToBinary(char* filename, int n, student* students){
		ofstream ofs(filename, ofs.binary);

		if(!(ofs.is_open())){
			cerr << "No Output File." << endl;
			return;
		}

		ofs << n;

	}
	int readFromBinary(char* filename, student** students);
	void writeToText(char* filename, int n, student* students);

};

int main()
{
	student* std = new student[100]; // get heap address
	int stdnum = 0;
	char file[512] = "\0";
	
	cout << "Enter Input Text File name : ";
	cin >> file;
	stdnum = std->readFromText(file, &std);

	cout << "Enter Output Binary File name : ";
	cin >> file;
	std->writeToBinary(file, stdnum, std);

	delete[] std;
	return 0;
}
