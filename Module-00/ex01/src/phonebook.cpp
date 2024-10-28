#include "../inc/phonebook.hpp"

Phonebook::Phonebook(){
	nb_contact = 0;
	last_contact = 0;
}

int	isNumber(std::string phone){
	for (size_t i = 0; i < phone.length(); ++i){
		if  (!isdigit(phone[i])){
			return false;
		}
	}
	return true;
}

void Phonebook::add(){
	std::string name, last_name, nickname, phone, dark;
	Contact new_contact;

	std::cout << "Add contact information" << std::endl;
	std::cout << "First name: ";
	std::cin >> name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	while (true){
		std::cout << "Phone number: ";
		std::cin >> phone;
		if (!isNumber(phone))
			std::cout << "Invalid format for the phone number. Try again" << std::endl;
		else
			break ;
	}
	std::cout << "Darkest secret: ";
	std::getline(std::cin >> std::ws, dark);
	if (nb_contact < MAX_CONTACTS){
		new_contact.contact(nb_contact, name, last_name, nickname, phone, dark);
		contacts[nb_contact] = new_contact;
		nb_contact++;
	} else {
		if (last_contact == MAX_CONTACTS)
			last_contact = 0;
		new_contact.contact(last_contact, name, last_name, nickname, phone, dark);
		contacts[last_contact] = new_contact;
		if (last_contact < MAX_CONTACTS)
			last_contact += 1;
	}
	std::cout << "New contact added!" << std::endl;
}

void Phonebook::print_Phonebook(){
	std::string index_nbr;
	int nb;

	if (contacts[0].get_first() == ""){
		std::cout << "There are no contacts." << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index" << "|" << std::setw(10) << std::right << "Name" << "|"
		<< std::setw(10) << std::right << "Lastname" << "|" << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < nb_contact; ++i){
		std::string fname = contacts[i].get_first();
		std::string lname = contacts[i].get_last();
		std::string nname = contacts[i].get_nick();

		if (fname.length() > 10)
			fname = fname.substr(0, 9) + ".";
		if (lname.length() > 10)
			lname =lname.substr(0, 9) + ".";
		if (nname.length() > 10)
			nname = nname.substr(0, 9) + ".";
		std::cout << "|" << std::setw(10) << std::right << i << "|" << std::setw(10) << std::right << fname << "|"
		<< std::setw(10) << std::right << lname << "|" << std::setw(10) << std::right << nname << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	while (true){
		std::cout << "Enter index number: ";
		std::cin >> index_nbr;
		if (!isNumber(index_nbr))
			std::cout << "Invalid entry! Please enter a valid number." << std::endl;
		else {
			nb = std::atoi(index_nbr.c_str());
			if (nb > MAX_CONTACTS || contacts[nb].get_first() == ""){
				std::cout << "Invalid input! Please enter a valid number." << std::endl;
			}
			else
				break ;
		}
	}
	contacts[nb].print_info();
}
