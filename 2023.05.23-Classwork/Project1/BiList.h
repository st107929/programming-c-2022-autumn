#pragma once
#include<ostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int data = 0, Node* next = nullptr, Node* prev = nullptr) : data(data), next(next), prev(prev) {}
	~Node() { data = 0; }
};

class BiList
{
private:

	Node* head;

	Node* tail;

	bool Index_Valid(int index);

	Node* Extract_Node(int index);

	void Insert_Node(Node* node, int index);

	int nan;

public:

	BiList();

	~BiList();

	void Push_Head(int data);

	int Extract_Head();

	void Pop_Head();

	int Length();

	void Push_Tail(int data);

	int Extract_Tail();

	void Pop_Tail();

	void Insert(int data, int index);

	int Extract(int index);

	void Remove(int index);

	int& operator[](int index);

	void Swap(int index1, int index2);

	void Mix();

	void Sort();

	friend std::ostream& operator<<(std::ostream& stream, const BiList& list);
	


};