#include "../inc/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called!" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor called!" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
