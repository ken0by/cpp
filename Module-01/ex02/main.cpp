#include <iostream>
#include <string>

using namespace std;

int main(){
	string str = "HI THIS IS BRAIN";
	string* stringPTR = &str;
	string& stringREF = str;

	cout << "Memory address str: " << &str << endl;
	cout << "Memory address stringPTR: " << stringPTR << endl;
	cout << "Memory address stringREF: " << &stringREF << endl;

	cout << "Value str: " << str << endl;
	cout << "Value stringPTR: " << *stringPTR << endl;
	cout << "Value stringREF: " << stringREF << endl;

	return 0;
}
