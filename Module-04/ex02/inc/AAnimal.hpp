#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class AAnimal{
	protected:
		std::string type;
	public:
		AAnimal();
		virtual std::string getType() const;
		virtual void makeSound() const = 0;
		virtual ~AAnimal();
};

#endif
