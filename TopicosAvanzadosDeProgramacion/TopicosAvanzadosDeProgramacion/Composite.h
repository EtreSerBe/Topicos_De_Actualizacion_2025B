#pragma once

#include <iostream>
using namespace std;

class Composite
{
public:
	Composite(string name)
	{
		this->name = name;
	}

	virtual void Render() = 0;

	virtual void AddElement(Composite* element)
	{
		cout << "se está llamando AddElement desde alguien que no debería añadir elementos." << endl;
	}

	string name;
};

