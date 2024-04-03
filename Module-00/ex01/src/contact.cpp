#include "../inc/contact.hpp"

Contact::Contact(){}

void Contact::contact(int nb, string name, string lname, string nick, string phone, string dark){
	this->nb = nb;
	this->first_name = name;
	this->last_name = lname;
	this->nickname = nick;
	this->phone_number = phone;
	this->darkest_secret = dark;
}

void Contact::print_info(){
	cout << "First name: " << first_name << endl;
	cout << "Last name: " << last_name << endl;
	cout << "Nickname: " << nickname << endl;
	cout << "Phone number: " << phone_number << endl;
	cout << "Darkest secret: " << darkest_secret << endl;
}

string Contact::get_first(){
	return this->first_name;
}

string Contact::get_last(){
	return this->last_name;
}

string Contact::get_nick(){
	return this->nickname;
}

string Contact::get_phone(){
	return this->phone_number;
}
