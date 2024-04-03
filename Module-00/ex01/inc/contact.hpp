#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

using namespace std;

class Contact{
	private:
		int			nb;
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		Contact();
		void contact(int nb, string first_name, string last_name, string nickname, string phone_number, string darkest_secret);
		void printf_info();
		string get_first();
		string get_last();
		string get_nick();
		string get_phone();
};

#endif
