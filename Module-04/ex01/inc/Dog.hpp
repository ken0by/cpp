#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const  Dog & other);
		void makeSound() const;
		Brain *getBrain() const;
		void compare(const Dog &toher);
		~Dog();
};

#endif
