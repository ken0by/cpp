#include "../inc/Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
	this->ideas = new std::string[20];
	for (int i = 0;  i < 20; i++){
		this->ideas[i] = "Pedro Pedro Pedro Pedro Pe ";
	}
}

Brain::Brain(Brain &other){
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[20];
	for (int i = 0;  i < 20; i++){
		this->ideas[i] = other.ideas[i] + "copy";
	}
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain assignment operator called" << std::endl;
	std::string *other_ideas = other.getIdeas();
	for (int i = 0; i < 20; i++){
		this->ideas[i] = other_ideas[i];
	}
	return *this;
}

std::string *Brain::getIdeas(void) const{
	return this->ideas;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
	delete [] this->ideas;
}
