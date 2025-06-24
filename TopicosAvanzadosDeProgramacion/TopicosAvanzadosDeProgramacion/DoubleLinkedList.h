#pragma once

#include <iostream>
using namespace std;


template <typename T>
class DoubleLinkedList
{
private:
	template <typename T>
	class Node
	{
	public:
		Node()
		{
			// Se podr�a lograr implementar sin tenerlo aqu�, y (en teor�a) podr�as ganar 
			// una cantidad peque�a peque��sima de performance, pero como esto es did�ctico, 
			// les va a ayudar a evitar unos cuantos problemillas.
			prev = nullptr;
			next = nullptr;
		}

		Node(T value)
		{
			data = value;
			// Se podr�a lograr implementar sin tenerlo aqu�, y (en teor�a) podr�as ganar 
			// una cantidad peque�a peque��sima de performance, pero como esto es did�ctico, 
			// les va a ayudar a evitar unos cuantos problemillas.
			prev = nullptr;
			next = nullptr;
		}

		T data;
		Node<T>* next;
		Node<T>* prev;
	};


private:
	Node<T>* first; // un puntero al primer nodo de nuestra lista ligada.
	Node<T>* last; // aqu� nos quedamos para el jueves 19.
	int count; // n�mero de elementos en esta lista ligada.

public:
	DoubleLinkedList()
	{
		count = 0;
		first = nullptr;
		last = nullptr;
	}

	int GetCount() { return count; };

	DoubleLinkedList::Node<T>& Find(T value);

	DoubleLinkedList::Node<T>& FindV2(T value);

	DoubleLinkedList::Node<T>& Successor(DoubleLinkedList::Node<T>* node)
	{
		return node->next;
	}

	DoubleLinkedList::Node<T>& Predecessor(DoubleLinkedList::Node<T>* node)
	{
		return node->prev;
	}


	// A�ade un nuevo nodo al final de la lista.
	void PushBack(T value);

	// Quita el nodo del final de la lista y devuelve su valor.
	T PopBack();

	// Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.
	void Insert(T valueToInsert, Node<T>* previousNode);

	int operationCounter;
};



template<typename T>
DoubleLinkedList<T>::Node<T>& DoubleLinkedList<T>::Find(T value)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (value)
		if (currentNode->data == value)
		{
			// NOTA: Estas dos l�neas son equivalentes, pero la flecha -> es m�s c�moda y pr�ctica y est�ndar.
			// currentNode->data
			// (*currentNode).data

			// si s� lo tiene, regresamos dicho nodo y nos salimos de la funci�n.
			return currentNode;
		}
		else
		{
			// si no lo tiene, continuamos al nodo que le sigue a currentNode.
			currentNode = currentNode->next;
		}
	}

	// si llegamos a esta parte del c�digo, es porque no encontramos ning�n nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}


template<typename T>
DoubleLinkedList<T>::Node<T>& DoubleLinkedList<T>::FindV2(T value)
{
	// empieza en el primer de la lista
	Node<T>* currentNode = first; // usamos una variable auxiliar para no tocar la referencia al first.

	// hacemos un ciclo para checar todos los nodos, hasta que ya no haya nodo siguiente.
	while (currentNode != nullptr)
	{
		// checa si la data del nodo actual es igual al valor a encontrarse (value)
		if (currentNode->data == value)
			return currentNode;

		// si no lo tiene, continuamos al nodo que le sigue a currentNode.
		currentNode = currentNode->next;
	}

	// si llegamos a esta parte del c�digo, es porque no encontramos ning�n nodo con el valor value.
	// entonces regresamos nullptr porque no existe dicho nodo.
	return nullptr;
}

template<typename T>
void DoubleLinkedList<T>::Insert(T valueToInsert, DoubleLinkedList<T>::Node<T>* previousNode)
{
	// Un nodo con el valor valueToInsert se insertar� como el Next de previousNode.

	// Nuevo nodo que ser� el nuevo Next de previousNode 
	Node<T>* newNode = new Node<T>(valueToInsert); // usamos una variable auxiliar para no tocar la referencia al first.

	// NOTA, es importante primero hacer la que va de newNode a previousNode->next y despu�s la de previousNode->next a newNode, 
	// porque si no newNode termina teni�ndose como su propio next, lo cual es un grave error.

	// Hacemos la conexi�n desde newNode hacia el next de previousNode
	newNode->next = previousNode->next;

	// Hacemos la conexi�n desde previousNode hacia newNode como su next
	previousNode->next = newNode;

	// aumentar el tama�o de la lista.
	count++;
}

// A�ade un nuevo nodo al final de la lista.
template<typename T>
void DoubleLinkedList<T>::PushBack(T value)
{
	// Creamos un nuevo nodo con el valor value como su data.
	Node<T>* newNode = new Node<T>(value);
	newNode->next = nullptr;


	// tenemos que checar que no est� vac�a la lista
	if (last == nullptr)
	{
		newNode->prev = nullptr;
		// si se cumple esto, entonces la lista est� vac�a y newNode se vuelve el �nico elemento
		// por tanto, �l es first y tambi�n es last
		first = newNode;
		last = newNode;
		count++;
		return; // nos salimos porque ya hicimos todo lo necesario.
	}

	// como ya tenemos el puntero last, que apunta al �ltimo elemento de la lista, pues simplemente
	// le decimos a last que su next es igual a newNode
	last->next = newNode;
	newNode->prev = last;
	// IMPORTANTE: Actualizar que ahora el puntero last apunta a newNode porque ahora �l es el verdadero �ltimo de la lista.
	last = newNode; 

	count++; // como metimos un nuevo elemento, aumentamos el contador de elementos.
}

template<typename T>
T DoubleLinkedList<T>::PopBack()
{
	// si no hay ning�n elemento.
	if (last == nullptr || count == 0 ) // lo dejo con todas las condiciones que significan lo mismo
	{
		cout << "Cuidado, est�s haciendo pop back cuando ya no hay elementos en esta lista ligada";
		return {}; // {} es un elemento de tipo T con su valor por defecto, sin importar de qu� tipo sea T.
	}

	// si solo queda un elemento, entonces lo manejamos de esta manera porque vamos a dejar la lista vac�a
	if (count == 1)
	{
		// obtenemos su data para retornarla.
		T data = first->data;
		// lo borramos y ponemos first como nullptr
		delete first;
		first = nullptr;
		last = nullptr; // este no le hacemos delete porque debe apuntar a la misma memoria que first
		count--;
		// regresamos la data
		return data;
	}

	// ya sabemos que el �ltimo nodo es last
	// y sabemos que el pen�ltimo nodo va a ser el last->prev
	Node<T>* penultimateNode = last->prev;

	// guardamos la data del �ltimo nodo
	T data = penultimateNode->next->data;

	// ya que tenemos la data borramos al �ltimo nodo
	delete last;
	penultimateNode->next = nullptr;
	last = penultimateNode;
	count--;

	return data;
}

