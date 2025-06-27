#pragma once

#include <iostream>
using namespace std;

#define QUEUE_DEFAULT_SIZE 12


template <typename T>
class Queue
{
	Queue()
	{
		head = 0;
		tail = 0;
		count = 0;
	}

	int GetCountSimple() { return size; }

	// Esta solo es un ejemplo de que se podr�a llegar a sobrevivir sin la variable size.
	// cu�ntos elementos tiene esta Queue dentro
	int GetCount();

	// a�ade el valor value al final de la fila.
	void Enqueue(T value);

	// quitar el primer elemento de la fila y regresa su valor T
	T Dequeue();

private:
	T data[QUEUE_DEFAULT_SIZE];
	int head;
	int tail;
	int count;

};


template <typename T>
int Queue<T>::GetCount()
{
	// en el caso sencillo, es nada m�s regresar Tail - Head
	int difference = tail - head;
	// Si difference es igual o mayor que 0, entonces regresamos ese valor.
	if (difference >= 0)
		return difference;
	else
		QUEUE_DEFAULT_SIZE + difference; // es '+' difference porque difference es negativo.

	// EJEMPLOS
	// head = 7
	// tail = 12
	// diff = 5, es positivo as� que nos regresa 5, est� bien.

	// head es 7, tail es 3
	// diff es 3-7 = -4
	// es negativo, entonces regresamos QUEUE_DEFAULT_SIZE - 4
	// que ser�a 12 - 4 -> 8
}


template <typename T>
void Queue<T>::Enqueue(T value)
{
	// primero checamos si s� cabe en la fila.
	// esto lo hacemos viendo si los valores de head y tail son iguales
	if (count == QUEUE_DEFAULT_SIZE)
	{
		cout << "advertencia, est� tratando de a�adir elementos a una fila que ya est� llena" << endl;
		return; // salimos de la funci�n.
	}

	// incrementar el count.
	count++;

	// poner el valor value en el �ndice que nos diga tail
	data[tail] = value;
	// finalmente, incrementamos tail
	tail++;
	// si tail ya se sale del arreglo, entonces lo ciclamos al inicio del arreglo.
	if (tail == QUEUE_DEFAULT_SIZE)
		tail = 0;
}

template <typename T>
T Queue<T>::Dequeue()
{
	// primero checamos si la queue est� vac�a, 
	if (count == 0)
	{
		// si s� est� vac�a, imprimimos una advertencia y salimos de la funci�n.
		cout << "advertencia, est� tratando de quitar elementos a una fila que est� vac�a" << endl;
		return; // salimos de la funci�n.
	}

	// decrementamos count
	count--;
	// quitamos el elemento donde nos dice Head
	T result = data[head];
	// movemos head al siguiente
	head++;
	if (head == QUEUE_DEFAULT_SIZE) // lo ciclamos para que no se salga del arreglo.
		head = 0;

}