#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal & other);
		Animal &operator=(const Animal &other);
		virtual std::string getType() const;
		virtual void makeSound() const;
		virtual ~Animal();
};

#endif
