#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria{
	protected:
		std::string type;
	public:
	AMateria();
	AMateria(std::string const & type);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
	virtual ~AMateria();
};

#endif
