#include "../inc/contact.hpp"
#include "../inc/phonebook.hpp"

using namespace std;

int main(){
	Phonebook phonebook;
	string cmd;

	while (true) {
		cout << "Enter one command (ADD, SEARCH , EXIT): ";
		cin >> cmd;

		if (cin.eof()){
			cout << "Ctrl-D detected. Exiting..." << endl;
			break ;
		}

		if (cmd == "ADD"){
			phonebook.add();
			cout << endl;
		} else if (cmd == "SEARCH") {
			phonebook.print_Phonebook();
			cout << endl;
		} else if (cmd == "EXIT") {
			cout << "Exiting..." << endl;
			break ;
		} else {
			cout << "Invalid command. Try again" << endl;
		}
	}
	return (0);
}
