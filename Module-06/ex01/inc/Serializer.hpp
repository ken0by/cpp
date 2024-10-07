#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data{
	int id;
	std::string name;
};

class Serializer
{
	public:
		Serializer();
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
