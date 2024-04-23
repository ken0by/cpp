#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(){
	std::cout << "MateriaSource constructor called" << std::endl;
	this->learnedCount = 0;
	for (int i = 0; i < 4; ++i)
		this->learnedMaterias[i] = nullptr;
}

void MateriaSource::learnMateria(AMateria *m){
	if (this->learnedCount >= 4)
		return;
	this->learnedMaterias[this->learnedCount++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < this->learnedCount; ++i){
		if (this->learnedMaterias[i]->getType() == type)
			return this->learnedMaterias[i]->clone();
	}
		return nullptr; // No se encontró la Materia
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->learnedMaterias[i];
}
