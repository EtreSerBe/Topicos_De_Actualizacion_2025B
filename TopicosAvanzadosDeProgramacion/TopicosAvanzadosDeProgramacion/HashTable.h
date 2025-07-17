#pragma once



template <typename T>
class HashTable
{
	// un lugar donde almacenar los datos
	T* data;
	unsigned int arraySize;

public:

	// necesitan una funci�n hash, que es la que mapea desde una llave hacia un �ndice
	// es una funci�n que toma un valor del tipo T y lo convierte en un entero
	int HashFunction(T key)
	{
		return key % arraySize;
	}

	// m�todos de insertar, quitar, buscar e iterar.
	void Add(T element)
	{
		int index = HashFunction(element);
		data[index] = element;

		// arraySize = 10
		// element = 39
		// int index = HashFunction(element); nos da 9
		// data[index] = element; nos dar�a que data[9] = 39
	}

	void Remove(T element)
	{
		int index = HashFunction(element);
		data[index] = {};
	}

	// contains es la funci�n de b�squeda.
	bool Contains(T element) 
	{
		int index = HashFunction(element);
		return data[index] == element; // devuelve true si s� son iguales; false sino.
	}

	//void Print()
	//{

	//}
};

