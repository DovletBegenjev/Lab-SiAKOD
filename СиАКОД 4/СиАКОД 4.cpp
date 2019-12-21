// СиАКОД 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

template<typename T>
class Queue_on_SLL
{
public:
	Queue_on_SLL();
	~Queue_on_SLL();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node * pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
Queue_on_SLL<T>::Queue_on_SLL()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Queue_on_SLL<T>::~Queue_on_SLL()
{
	clear();
}

template<typename T>
void Queue_on_SLL<T>::pop_front()
{
	Node<T> *temp = this->tail;

	tail = tail->pNext;

	delete temp;

	Size--;
}

template<typename T>
void Queue_on_SLL<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = tail = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		current->pNext = new Node<T>(data);
		head = current->pNext;
	}

	Size++;
}

template<typename T>
void Queue_on_SLL<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T & Queue_on_SLL<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->tail;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}

		current = current->pNext;
		counter++;
	}
}

int main()
{
	Queue_on_SLL<int> q;

	cout << "Pushing" << endl;
	q.push_back(5);
	q.push_back(10);
	q.push_back(20);

	for (int i = 0; i < q.GetSize(); i++)
	{
		cout << q[i] << endl;
	}

	cout << "Poping" << endl;
	q.pop_front();

	for (int i = 0; i < q.GetSize(); i++)
	{
		cout << q[i] << endl;
	}
}