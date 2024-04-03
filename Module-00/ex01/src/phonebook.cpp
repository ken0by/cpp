#include "../inc/phonebook.hpp"

using namespace std;

Phonebook::Phonebook(){
	nb_contact = 0;
}

int	isNumber(string phone){
	for (size_t i = 0; i < phone.length(); ++i){
		if  (!isdigit(phone[i])){
			return false;
		}
	}
	return true;
}

void Phonebook::add(){
	string name, last_name, nickname, phone, dark;

	cout << "Add contact information" << endl;
	cout << "First name: ";
	cin >> name;
	cout << "Last name: ";
	cin >> last_name;
	cout << "Nickname: ";
	cin >> nickname;
	while (true){
		cout << "Phone number: ";
		cin >> phone;
		if (!isNumber(phone))
			cout << "Invalid format for the phone number. Try again" << endl;
		else
			break ;
	}
	cout << "Darkest secret: ";
	cin >> dark;
	Contact new_contact;
	if (nb_contact < MAX_CONTACTS){
		new_contact.contact(nb_contact, name, last_name, nickname, phone, dark);
		contacts[nb_contact] = new_contact;
		nb_contact++;
	} else {
		new_contact.contact(7, name, last_name, nickname, phone, dark);
		contacts[7] = new_contact;
	}
	cout << "New contact added!" << endl;
}

void Phonebook::print_Phonebook(){
	if (contacts[0].get_first() == ""){
		cout << "There are no contacts." << endl;
		return ;
	}
	cout << "---------------------------------------------" << endl;
	cout << "|" << setw(10) << right << "Index" << "|" << setw(10) << right << "Name" << "|"
		<< setw(10) << right << "Lastname" << "|" << setw(10) << right << "Nickname" << "|" << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 0; i < nb_contact; ++i){
		string fname = contacts[i].get_first();
		string lname = contacts[i].get_last();
		string nname = contacts[i].get_nick();

		if (fname.length() > 10)
			fname = fname.substr(0, 9) + ".";
		if (lname.length() > 10)
			lname =lname.substr(0, 9) + ".";
		if (nname.length() > 10)
			nname = nname.substr(0, 9) + ".";
		cout << "|" << setw(10) << right << i << "|" << setw(10) << right << fname << "|"
		<< setw(10) << right << lname << "|" << setw(10) << right << nname << "|" << endl;
		cout << "---------------------------------------------" << endl;
	}
	string index_nbr;
	int nb;
	while (true){
		cout << "Enter index number: ";
		cin >> index_nbr;
		if (!isNumber(index_nbr))
			cout << "Invalid entry! Please enter a valid number." << endl;
		else {
			nb = atoi(index_nbr.c_str());
			if (nb > MAX_CONTACTS || contacts[nb].get_first() == ""){
				cout << "Invalid input! Please enter a valid number." << endl;
			}
			else
				break ;
		}
	}
	contacts[nb].print_info();
}
