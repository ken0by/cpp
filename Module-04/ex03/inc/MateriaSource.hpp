#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *learnedMaterias[4];
	int learnedCount;

public:
	MateriaSource();
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
	~MateriaSource();
};

#endif
