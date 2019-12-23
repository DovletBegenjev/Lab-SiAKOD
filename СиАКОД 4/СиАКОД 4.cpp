// СиАКОД 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//----------------- Стек на массиве -----------------//

template<typename T1>
class Stack
{
private:
	T1 *steck;
	int top; // верхний элемент
	int StackSize;

public:
	Stack();
	~Stack();

	// поместить элемент в стек
	void push(T1 data);

	// извлечь элемент из стека
	void pop();

	// прочитать элемент из вершины стека
	T1 top_el();

	// проверка на пустоту
	bool IsEmpty();

	// очистить стек
	void clear_stack();

	// размер стека
	int GetStackSize()
	{
		return (top + 1);
	}
};

template<typename T1>
Stack<T1>::Stack()
{
	StackSize = 100;
	steck = new T1[StackSize];
	top = -1;
}

template<typename T1>
Stack<T1>::~Stack()
{
	delete[]steck;
}

template<typename T1>
void Stack<T1>::push(T1 data)
{
	if (top < StackSize - 1)
	{
		top++;
		steck[top] = data;
	}
}

template<typename T1>
void Stack<T1>::pop()
{
	if (top != -1)
	{
		top--;
	}
}

template<typename T1>
T1 Stack<T1>::top_el()
{
	if (top != -1)
	{
		return steck[top];
	}
	else
	{
		return -1;
	}
}

template<typename T1>
bool Stack<T1>::IsEmpty()
{
	if (top != -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template<typename T1>
void Stack<T1>::clear_stack()
{
	while (StackSize)
	{
		pop();
	}
}

//----------------- Список на ПЛС -----------------//

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

	T top()
	{
		return tail;
	}

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
	cout << endl << "desturctor" << endl;
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
	if (Size == 0)
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

//----------------- Запрос -----------------//

struct Inquiry
{
	enum Priority
	{
		F0, F1, F2
	};

	string name;
	time_t time;
	Priority priority;
};

int main()
{
	srand(time(0));

	int counter = 1;

	Queue_on_SLL<Inquiry> queue_0;
	Queue_on_SLL<Inquiry> queue_1;
	Queue_on_SLL<Inquiry> queue_2;
	Inquiry q_prior;

	size_t qs_size;

	Stack<Inquiry> stack;
	Inquiry s;

	time_t time_of_processing = 0;
	time_t clockP = clock();

	bool flag = true;

	while (flag)
	{
		cout << "Seconds left to process the problem F" << q_prior.priority << ": " << time_of_processing << endl;

		if (time_of_processing)
		{
			time_of_processing--;
			clockP++;
		}

		if (queue_0.GetSize() == 0 && queue_1.GetSize() == 0 && queue_2.GetSize() == 0 && stack.IsEmpty())
		{
			cout << endl << "Enter number of elements you want to put in queues: ";
			cin >> qs_size;
			cout << endl;

			if (!qs_size)
			{
				flag = false;
			}

			for (int i = 0; i < qs_size; i++)
			{
				switch (rand() % 3 + 0)
				{
				case 0:
					q_prior.priority = Inquiry::Priority::F0;
					q_prior.time = clockP;
					q_prior.name = "Inquiry number " + to_string(counter);
					cout << q_prior.name << ", priority F0, sent to the queue 0. Exact time: " << q_prior.time << endl;
					counter++;
					clockP++;
					queue_0.push_back(q_prior);
					break;

				case 1:
					q_prior.priority = Inquiry::Priority::F1;
					q_prior.time = clockP;
					q_prior.name = "Inquiry number " + to_string(counter);
					cout << q_prior.name << ", priority F1, sent to the queue 1. Exact time: " << q_prior.time << endl;
					counter++;
					clockP++;
					queue_1.push_back(q_prior);
					break;

				case 2:
					q_prior.priority = Inquiry::Priority::F2;
					q_prior.time = clockP;
					q_prior.name = "Inquiry number " + to_string(counter);
					cout << q_prior.name << ", priority F2, sent to the queue 2. Exact time: " << q_prior.time << endl;
					counter++;
					clockP++;
					queue_2.push_back(q_prior);
					break;

				default:
					cout << "An unexpected error occurred!";
					break;
				}

				/*counter++;
				clockP++;
				queue_0.push_back(q_prior);
				queue_1.push_back(q_prior);
				queue_2.push_back(q_prior);*/
			}
		}

		if (!time_of_processing)
		{
			if (queue_0.GetSize() != 0)
			{
				queue_0.pop_front();
				time_of_processing = rand() % 5 + 1;
				cout << endl << q_prior.name << ", priority F0, sent to the processor. Exact time: " << clockP << endl;
			}
			else if (queue_0.GetSize() != 0)
			{
				stack.push(q_prior);
				queue_0.pop_front();
				cout << endl << q_prior.name << ", priority F0. Processor is busy, sent to the stack. Exact time: " << clockP << endl;
			}

			if (!time_of_processing)
			{
				if (queue_0.GetSize() == 0 && queue_1.GetSize() != 0)
				{
					queue_1.pop_front();
					time_of_processing = rand() % 5 + 1;
					cout << endl << q_prior.name << ", priority F1, sent to the processor. Exact time: " << clockP << endl;
				}
				else if (queue_1.GetSize() != 0)
				{
					stack.push(q_prior);
					queue_1.pop_front();
					cout << endl << q_prior.name << ", priority F1. Processor is busy, sent to the stack. Exact time: " << clockP << endl;
				}
			}

			if (!time_of_processing)
			{
				if (queue_0.GetSize() == 0 && queue_1.GetSize() == 0 && queue_2.GetSize() != 0)
				{
					queue_2.pop_front();
					time_of_processing = rand() % 5 + 1;
					cout << endl << q_prior.name << ", priority F2, sent to the processor. Exact time: " << clockP << endl;
				}
				else if (queue_2.GetSize() != 0)
				{
					stack.push(q_prior);
					queue_2.pop_front();
					cout << endl << q_prior.name << ", priority F2. Processor is busy, sent to the stack. Exact time: " << clockP << endl;
				}
			}
		}
	}
}