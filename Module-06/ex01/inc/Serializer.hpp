#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <iomanip>

class Serializer
{
	private:

	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
};

std::ostream& operator<<(std::ostream &output, const Serializer& other);

#endif
