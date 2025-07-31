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
		cout << "se est� llamando AddElement desde alguien que no deber�a a�adir elementos." << endl;
	}

	string name;
};

