#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain{
	private:
		std::string *ideas;
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		std::string *getIdeas() const;
		~Brain();
};

#endif
