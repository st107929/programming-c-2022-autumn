#pragma once
#pragma once
#include<ostream>

struct Node
{
	int data;
	Node* next;
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	~Node() { data = 0; }
};

class List
{
private:

	Node* head;

	bool Index_Valid(int index);

	Node* Extract_Node(int index);

	void Insert_Node(Node* node, int index);

	int nan;

	int Partition(int start, int end);

	void QuickSort(int start, int end);

public:

	List();

	~List();

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

	void Endbeg();

	void Mirrow(int mirr);

	friend std::ostream& operator<<(std::ostream& stream, const List& list);

};
