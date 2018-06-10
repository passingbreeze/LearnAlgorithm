#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{

	// set
	set<string> s;


	// insert(element)
	s.insert("abc");
	s.insert("def");
	s.insert("ghi");
	s.insert("jkl");


	// erase(element)
	s.erase("jkl");


	// empty(), size()
	if (!s.empty()) cout << "s size : " << s.size() << '\n';


	// find(element)
	cout << *s.find("abc") << '\n';
	cout << *s.find("def") << '\n';


	// count(element)
	cout << "abc count : " << s.count("abc") << '\n';


	// begin(), end()
	cout << "traverse" << '\n';
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << "value : " << *it << '\n';
	}

	return 0;

}