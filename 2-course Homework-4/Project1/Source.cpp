#include<iostream>

template <typename T>
class RingList
{
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	RingList() :head(nullptr), tail(nullptr) {};
	~RingList()
	{
		if (this->len() != 0)
		{
			while (this->len() != 1)
			{
				Node* temp = new Node;
				temp = head;
				head = head->next;
				tail->next = head;
				delete temp;
			}
			delete head;
		}
	}
	int len()
	{
		if (head == nullptr)
			return 0;
		else
		{
			int res = 1;
			Node* temp = new Node;
			temp = head;
			while (temp->next != head)
			{
				temp = temp->next;
				++res;
			}
			return res;
		}
	}
	void Insert(T dat)
	{
		if (this->len() != 0)
		{
			Node* n = new Node;
			n->data = dat;
			n->next = head;
			head = n;
			tail->next = n;
		}
		else
		{
			Node* n = new Node;
			n->data = dat;
			n->next = n;
			head = n;
			tail = n;
		}
	}
	T& operator[](int ind)
	{
		ind %= (this->len());
		Node* temp = new Node;
		temp = this->head;
		for (int i = 0; i < ind; ++i)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	void Remove(int ind)
	{
		ind %= this->len();
		if (head == nullptr)
		{
			return;
		}
		if ((ind == 0) && (head->next == head))
		{
			Node* temp = new Node;
			temp = head;
			head = nullptr;
			delete temp;
			tail = nullptr;
			return;
		}
		if (ind == 0)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			tail->next = head;
			return;
		}
		if (ind == this->len() - 1)
		{
			Node* temp1 = new Node;
			Node* temp2 = new Node;
			temp1 = tail;
			temp2 = tail;
			for (int i = 0; i < this->len() - 1; ++i)
			{
				temp2 = temp2->next;
			}
			tail = temp2;
			delete temp1;
			tail->next = head;
			return;
		}
		else
		{
			Node* temp1 = new Node;
			Node* temp2 = new Node;
			temp1 = head;
			for (int i = 0; i < ind - 1; ++i)
			{
				temp1 = temp1->next;
			}
			temp2 = temp1->next;
			temp1->next = temp2->next;
			delete temp2;
		}
	}
};
int main(int argc, char* argv[])
{
	RingList<int> b;

	b.Insert(100);
	b.Insert(200);
	b.Insert(300);
	std::cout << b[2] << std::endl;
	b.Remove(1);
	std::cout << b.len() << std::endl;
	std::cout << b[1] << std::endl;

	return EXIT_SUCCESS;
}