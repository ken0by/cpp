#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

#define MAX_CONTACTS 8

class Phonebook{
	private:
		Contact contacts[MAX_CONTACTS];
		int nb_contact;
		int last_contact;
	public:
		Phonebook();
		void add();
		void print_Phonebook();
};
#endif
