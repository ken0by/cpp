#include "../inc/contact.hpp"

Contact::Contact(){}

void Contact::contact(int nb, std::string name, std::string lname, std::string nick, std::string phone, std::string dark){
	this->nb = nb;
	this->first_name = name;
	this->last_name = lname;
	this->nickname = nick;
	this->phone_number = phone;
	this->darkest_secret = dark;
}

void Contact::print_info(){
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string Contact::get_first(){
	return this->first_name;
}

std::string Contact::get_last(){
	return this->last_name;
}

std::string Contact::get_nick(){
	return this->nickname;
}

std::string Contact::get_phone(){
	return this->phone_number;
}
