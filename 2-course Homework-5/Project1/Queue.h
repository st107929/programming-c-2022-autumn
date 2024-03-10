#pragma once
#include<iostream>

template <class T>
class Queue
{
public:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	Queue()
	{
		head = nullptr;
		tail = nullptr;
	}
	~Queue()
	{
		if (!(this->IsEmpty()))
		{
			while (tail != head)
			{
				Node* temp = new Node;
				temp = head;
				head = head->next;
				delete temp;
			}
			delete head;
		}
	}
	void operator=(const Queue<T>& q)
	{
		for (Node* temp = this->head; temp != nullptr; temp = temp->next)
		{

		}
	}
	int len()
	{
		if (this->IsEmpty())
		{
			return 0;
		}
		else
		{
			int res = 1;
			Node* temp = new Node;
			temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
				++res;
			}
			return res;
		}
	}
	void push(T x)
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = nullptr;
		if (this->IsEmpty())
		{
			head = temp;
			tail = temp;
			tail->next = nullptr;
			return;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			return;
		}
	}
	T front()
	{
		if (this->IsEmpty())
		{
			std::cout << "Take from empty queue" << std::endl;
		}
		else
		{
			return head->data;
		}
	}
	void pop()
	{
		if ((this->head == this->tail) && (!(this->IsEmpty())))
		{
			Node* temp = new Node;
			temp = head;
			head = nullptr;
			tail = nullptr;
			delete temp;
			return;
		}
		if (!(this->IsEmpty()))
		{
			Node* temp = new Node;
			temp = head;
			head = head->next;
			delete temp;
			return;
		}
		else
		{
			std::cout << "Pop from empty queue" << std::endl;
			return;
		}
	}
	bool IsEmpty()
	{
		return (head == nullptr);
	}
};