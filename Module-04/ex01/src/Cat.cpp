#include "../inc/Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &other){
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = Brain(*(other.brain));
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meau!" << std::endl;
}

Brain *Cat::getBrain(void) const{
	return this->brain;
}

void Cat::compare(const Cat &other){
	std::cout << std::endl;
	std::cout << "COMPARE ADDRESS:" << std::endl;
	std::cout << "this  : " << reinterpret_cast<void*>(this->brain) << std::endl;
	std::cout << "other : " << reinterpret_cast<void*>(other.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "COMPARE IDEAS:" << std::endl;
	std::cout << "This ideas \t\t\t\t\t | \t\t\t Other ideas\n";
	for (int i = 0; i < 100; i++)
		std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << ((this->brain)->getIdeas())[i] << "\t\t\t | \t\t\t" << ((other.getBrain())->getIdeas())[i] << std::endl;
	std::cout << std::endl;
	//delete this->brain;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}
