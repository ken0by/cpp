#include "../inc/Serializer.hpp"

void simple_test()
{
	Data data;
	data.id = 42;
	data.name = "Test Data";

	// Serializar el puntero a Data
	uintptr_t raw = Serializer::serialize(&data);

	// Deserializar el uintptr_t de vuelta a un puntero a Data
	Data *deserializedData = Serializer::deserialize(raw);

	// Verificar si el puntero deserializado es igual al original
	if (deserializedData == &data)
	{
		std::cout << "Success! The pointers are equal." << std::endl;
		std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
	}
	else
	{
		std::cout << "Error: The pointers are not equal." << std::endl;
	}
}

void big_test()
{
	// Primer caso de prueba: Comprobando serialización y deserialización básica
	Data data1;
	data1.id = 42;
	data1.name = "Data1";

	std::cout << "=== TEST 1: Serialización y Deserialización de Data1 ===" << std::endl;
	std::cout << "Antes de serializar: ID = " << data1.id << ", Nombre = " << data1.name << std::endl;

	uintptr_t raw1 = Serializer::serialize(&data1);
	// std::cout << raw1 << std::endl;
	Data *deserializedData1 = Serializer::deserialize(raw1);
	// std::cout << deserializedData1->id << std::endl;

	if (deserializedData1 == &data1)
	{
		std::cout << "Deserialización correcta. Los datos coinciden." << std::endl;
		std::cout << "Después de deserializar: ID = " << deserializedData1->id << ", Nombre = " << deserializedData1->name << std::endl;
	}
	else
	{
		std::cout << "Error en la deserialización: Los punteros no coinciden." << std::endl;
	}

	// Segundo caso de prueba: Serialización y deserialización con diferentes datos
	Data data2;
	data2.id = 123;
	data2.name = "Data2";

	std::cout << "\n=== TEST 2: Serialización y Deserialización de Data2 ===" << std::endl;
	std::cout << "Antes de serializar: ID = " << data2.id << ", Nombre = " << data2.name << std::endl;

	uintptr_t raw2 = Serializer::serialize(&data2);
	Data *deserializedData2 = Serializer::deserialize(raw2);

	if (deserializedData2 == &data2)
	{
		std::cout << "Deserialización correcta. Los datos coinciden." << std::endl;
		std::cout << "Después de deserializar: ID = " << deserializedData2->id << ", Nombre = " << deserializedData2->name << std::endl;
	}
	else
	{
		std::cout << "Error en la deserialización: Los punteros no coinciden." << std::endl;
	}

	// Tercer caso de prueba: Comprobando datos vacíos
	Data data3;
	data3.id = 0;
	data3.name = "Empty";

	std::cout << "\n=== TEST 3: Serialización y Deserialización de Data vacía ===" << std::endl;
	std::cout << "Antes de serializar: ID = " << data3.id << ", Nombre = " << data3.name << std::endl;

	uintptr_t raw3 = Serializer::serialize(&data3);
	Data *deserializedData3 = Serializer::deserialize(raw3);

	if (deserializedData3 == &data3)
	{
		std::cout << "Deserialización correcta. Los datos coinciden." << std::endl;
		std::cout << "Después de deserializar: ID = " << deserializedData3->id << ", Nombre = " << deserializedData3->name << std::endl;
	}
	else
	{
		std::cout << "Error en la deserialización: Los punteros no coinciden." << std::endl;
	}

	// Cuarto caso de prueba: Puntero nulo
	std::cout << "\n=== TEST 4: Serialización y Deserialización de NULL ===" << std::endl;
	Data *nullPtr = NULL; // Usar NULL en lugar de nullptr en C++98
	uintptr_t raw4 = Serializer::serialize(nullPtr);
	Data *deserializedNull = Serializer::deserialize(raw4);

	if (deserializedNull == NULL)
	{
		std::cout << "Deserialización correcta. El puntero es nulo." << std::endl;
	}
	else
	{
		std::cout << "Error en la deserialización: El puntero no es nulo." << std::endl;
	}
}

int main()
{
	std::cout << "-----SIMPLE TEST-----\n"
			  << std::endl;
	simple_test();
	std::cout << "\n"
			  << std::endl;
	std::cout << "-----BIG TEST-----\n"
			  << std::endl;
	big_test();
	std::cout << "\n"
			  << std::endl;
	return 0;
}
