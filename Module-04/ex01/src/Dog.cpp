#include "../inc/Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(){
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = Brain(*(other.brain));
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void Dog::makeSound(void) const{
	std::cout << "Bark!" << std::endl;
}

Brain *Dog::getBrain(void) const{
	return this->brain;
}

void Dog::compare(const Dog &other){
	std::cout << std::endl;
	std::cout << "COMPARE ADDRESS:" << std::endl;
	std::cout << "this  : " << reinterpret_cast<void*>(this->brain) << std::endl;
	std::cout << "other : " << reinterpret_cast<void*>(other.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "COMPARE IDEAS:" << std::endl;
	std::cout << "This ideas \t\t\t\t\t | \t\t\t Other ideas\n";
	for (int i = 0; i < 20; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << ((this->brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
	//delete this->brain;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}
