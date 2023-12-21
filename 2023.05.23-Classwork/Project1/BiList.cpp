#include "BiList.h"

BiList::BiList() : head(nullptr), tail(nullptr), nan(0)
{
}

BiList::~BiList()
{
	while (head != nullptr)
	{
		this->Pop_Head();
	}
}

void BiList::Remove(int index)
{
	Node* temp = this->Extract_Node(index);
	if (temp != nullptr)
	{
		delete temp;
	}
}

int& BiList::operator[](int index)
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

void BiList::Swap(int index1, int index2)
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

void BiList::Mix()
{
	for (int i = 0; i < this->Length(); ++i)
	{
		this->Swap(i, rand() % this->Length());
	}
}

void BiList::Sort()
{
	for (int i = 0; i < Length(); ++i)
	{
		for (int j = 0; j < Length(); ++j)
		{
			if ((*this)[i] > (*this)[j])
			{
				Swap(i, j);
			}
		}
	}
}

bool BiList::Index_Valid(int index)
{
	return (index >= 0 && index < this->Length());
}

Node* BiList::Extract_Node(int index)
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
		temp->next->next->prev = temp;
	}
	return res;
}

int BiList::Extract(int index)
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

void BiList::Insert(int data, int index)
{
	return this->Insert_Node(new Node(data), index);
}

void BiList::Pop_Tail()
{
	this->Remove(this->Length() - 1);
}

int BiList::Extract_Tail()
{
	return Extract(this->Length() - 1);
}

void BiList::Push_Tail(int data)
{
	return this->Insert_Node(new Node(data), this->Length());
}

int BiList::Length()
{
	int count = 0;
	Node* temp = this->head;
	while (temp != nullptr)
	{
		temp = temp->next;
		++count;
	}
	return count + 1;
}

void BiList::Pop_Head()
{
	this->Remove(0);
}

int BiList::Extract_Head()
{
	int res = 0;
	if (this->head != nullptr)
	{
		res = this->head->data;
	}
	Pop_Head();
	return res;
}

void BiList::Push_Head(int data)
{
	Insert_Node(new Node(data), 0);
}

void BiList::Insert_Node(Node* node, int index)
{
	if (index == 0)
	{
		node->next = this->head;
		node->prev = this->tail;
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
		node->prev = temp;
		temp->next = node;
		return;
	}
}

std::ostream& operator<<(std::ostream& stream, const BiList& list)
{
	Node* temp = list.head;
	while (temp != nullptr)
	{
		stream << temp->data << " ";
		temp = temp->next;
	}
	return stream;
}
