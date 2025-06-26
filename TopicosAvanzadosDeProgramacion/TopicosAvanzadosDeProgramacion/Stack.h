#pragma once

#include <iostream>
using namespace std;

#define STACK_DEFAULT_SIZE 10

template <typename T>
class Stack
{
public:
	Stack()
	{
		head = 0;
	}

	void Push(T value);

	T Pop();

	// tambi�n se le conoce a veces como Top. Es lo mismo que Pop pero sin sacar el elemento.
	T Peak();

	int Count() { return head; };

private:
	T data[STACK_DEFAULT_SIZE]; // cu�ntos elementos caben en esta stack
	int head; // en qu� �ndice del array est� el tope de la pila actualmente. Tambi�n nos dice cu�ntos elementos tiene dentro actualmente
};

template <typename T>
void Stack<T>::Push(T value)
{
	// hay que checar que no se pase de la capacidad del array
	if (head == STACK_DEFAULT_SIZE)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no a�adimos e imprimimos una advertencia
		cout << "Advertencia, intent� meter m�s elementos de los que caben en este Stack." << endl;
		return;
	}
	// pone el value en la posici�n que head diga
	data[head] = value;
	head++;
}

template <typename T>
T Stack<T>::Pop()
{
	// tenemos que checar que no se haga Pop cuando ya est� vac�a la stack.
	if (head == 0)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no a�adimos e imprimimos una advertencia
		cout << "Advertencia, intent� sacar m�s elementos esta Stack ya est� vac�a." << endl;
		return {};
	}

	T value = data[head-1];

	head--; // esto hace que se "quite" el elemento de la pila.
	return value;
}

template <typename T>
T Stack<T>::Peak()
{
	// tenemos que checar que no se haga Pop cuando ya est� vac�a la stack.
	if (head == 0)
	{
		// quiere decir que nos pasamos de la capacidad, por tanto no a�adimos e imprimimos una advertencia
		cout << "Advertencia, esta Stack ya est� vac�a. No hay elemento para hacer Peak" << endl;
		return {};
	}

	return data[head-1];
}
