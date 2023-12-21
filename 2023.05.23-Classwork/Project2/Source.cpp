#include "List.h"
#include<iostream>

List::List() : head(nullptr) {}

List::~List()
{
	while (head != nullptr)
	{
		this->Pop_Head();
	}
};

void List::Push_Head(int data)
{
	/*
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
	*/
	//return this->Insert_Node(new Node(data), 0);
	this->head = new Node(data, this->head);
}

int List::Extract_Head()
{
	int res = 0;
	if (this->head != nullptr)
	{
		res = this->head->data;
	}
	Pop_Head();
	return res;
}

void List::Pop_Head()
{
	this->Remove(0);
}

std::ostream& operator<<(std::ostream& stream, const List& list)
{
	Node* temp = list.head;
	while (temp != nullptr)
	{
		stream << temp->data << " ";
		temp = temp->next;
	}
	return stream;
}

int List::Length()
{
	int count = 0;
	Node* temp = this->head;
	while (temp != nullptr)
	{
		temp = temp->next;
		++count;
	}
	return count;
}

void List::Push_Tail(int data)
{
	return this->Insert_Node(new Node(data), this->Length());
	/*
	if (this->head == nullptr)
	{
		return this->Push_Head(data);
	}
	Node* temp = this->head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new Node(data);
	*/
}

int List::Extract_Tail()
{
	return Extract(this->Length() - 1);
}

void List::Pop_Tail()
{
	this->Remove(this->Length() - 1);
}

void List::Insert(int data, int index)
{
	return this->Insert_Node(new Node(data), index);
	/*
	if (index == 0)
	{
		return this->Push_Head(data);
	}
	if (index == this->Length())
	{
		return this->Push_Tail(data);
	}
	if (Index_Valid(index))
	{
		Node* temp = this->head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		temp->next = new Node(data, temp->next);
	}
	*/
}

int List::Extract(int index)
{
	Node* temp = this->Extract_Node(index);
	int res = 0;
	if (temp != nullptr)
	{
		res = temp->data;
		delete temp;
	}
	return res;
}

void List::Remove(int index)
{
	Node* temp = this->Extract_Node(index);
	if (temp != nullptr)
	{
		delete temp;
	}
}

bool List::Index_Valid(int index)
{
	return (index >= 0 && index < this->Length());
}

Node* List::Extract_Node(int index)
{
	if (!Index_Valid(index))
	{
		return nullptr;
	}
	Node* res = nullptr;
	if (index == 0)
	{
		res = this->head;
		this->head = this->head->next;
	}
	else
	{
		Node* temp = this->head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		res = temp->next;
		temp->next = temp->next->next;
	}
	return res;
}

void List::Insert_Node(Node* node, int index)
{
	if (index == 0)
	{
		node->next = this->head;
		this->head = node;
		return;
	}
	if (Index_Valid(index) || index == this->Length())
	{
		Node* temp = this->head;
		while (index > 1)
		{
			temp = temp->next;
			--index;
		}
		node->next = temp->next;
		temp->next = node;
		return;
	}
}

void List::Swap(int index1, int index2)
{
	if (index1 == index2 || !Index_Valid(index1) || !Index_Valid(index2))
	{
		return;
	}
	if (index1 > index2)
	{
		return this->Swap(index2, index1);
	}
	Node* node2 = this->Extract_Node(index2);
	Node* node1 = this->Extract_Node(index1);
	this->Insert_Node(node2, index1);
	this->Insert_Node(node1, index2);
}

int& List::operator[](int index)
{
	if (!this->Index_Valid(index))
	{
		return nan;
	}

	Node* temp = this->head;
	while (index > 0)
	{
		temp = temp->next;
		--index;
	}
	return temp->data;
}

void List::Mix()
{
	for (int i = 0; i < this->Length(); ++i)
	{
		this->Swap(i, rand() % this->Length());
	}
}

void List::Sort()
{
	this->QuickSort(0, Length() - 1);
}

int List::Partition(int start, int end)
{
	int ind = start;
	int pivot = (*this)[end];
	for (int i = start; i < end; ++i)
	{
		if ((*this)[i] < pivot)
		{
			this->Swap(ind, i);
			++ind;
		}
	}
	this->Swap(ind, end);
	return ind;
}

void List::QuickSort(int start, int end)
{
	int p = Partition(start, end);
	if (p - 1 > start)
	{
		QuickSort(start, p - 1);
	}
	if (p + 1 < end)
	{
		QuickSort(p + 1, end);
	}
}
void List::Endbeg()
{
	for (int i = 1; i < Length(); ++i)
	{
		Insert_Node(Extract_Node(i), 0);
	}
}
void List::Mirrow(int mirr)
{
	if (!Index_Valid(mirr))
	{
		return;
	}
	else if (mirr == 0)
	{
		for (int i = 1; i < Length(); ++i)
		{
			Insert_Node(Extract_Node(Length() - 1), 0);
		}
	}
	else
	{
		for (int i = Length() - 1; i > mirr - 1; --i)
		{
			Insert_Node(Extract_Node(Length() - 1), 0);
		}
		for (int i = Length() - mirr + 1; i < Length(); ++i)
		{
			Insert_Node(Extract_Node(Length() - mirr), Length() - 1);
		}
	}
}
int main(int argc, char* argv[])
{
	List list;
	list.Insert(1, 0);
	list.Insert(2, 1);
	list.Insert(3, 2);
	list.Insert(4, 3);
	list.Insert(5, 4);
	list.Insert(6, 5);
	list.Insert(7, 6);
	std::cout << list << std::endl;
	list.Mirrow(0);
	//list.Mirrow(3);
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}