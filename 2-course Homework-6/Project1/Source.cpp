#include<iostream>
#include<mutex>
#include<thread>

template <typename T>

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
	std::mutex mut;
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
				mut.lock();
				Node* temp = new Node;
				temp = head;
				head = head->next;
				delete temp;
				mut.unlock();
			}
			mut.lock();
			delete head;
			mut.unlock();
		}
	}
	int len()
	{
		mut.lock();
		if (this->IsEmpty())
		{
			mut.unlock();
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
			mut.unlock();
			return res;
		}
	}
	void push(T x)
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = nullptr;
		mut.lock();
		if (this->IsEmpty())
		{
			head = temp;
			tail = temp;
			tail->next = nullptr;
			mut.unlock();
			return;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
			mut.unlock();
			return;
		}
	}
	T front()
	{
		if (this->IsEmpty())
		{
			mut.lock();
			std::cout << "Take from empty queue" << std::endl;
			mut.unlock();
		}
		else
		{
			return head->data;
		}
	}
	void pop()
	{
		if ((!(this->IsEmpty())) && (this->head == this->tail))
		{
			mut.lock();
			Node* temp = new Node;
			temp = head;
			head = nullptr;
			tail = nullptr;
			delete temp;
			mut.unlock();
			return;
		}
		if (!(this->IsEmpty()))
		{
			Node* temp = new Node;
			mut.lock();
			temp = head;
			head = head->next;
			mut.unlock();
			delete temp;
		}
		else
		{
			mut.lock();
			std::cout << "Pop from empty queue" << std::endl;
			mut.unlock();
		}
	}
	bool IsEmpty()
	{
		return (head == nullptr);
	}
};
void test1()
{
	Queue<int> q1;
	std::cout << q1.len() << std::endl;
	q1.front();
	q1.push(10);
	q1.push(20);
	std::cout << q1.len() << std::endl;
	std::cout << q1.front() << std::endl;
}
void test2()
{
	Queue<char> q2;
	q2.push('a');
	q2.push('b');
	q2.push('c');
	std::cout << q2.len() << std::endl;
	std::cout << q2.front() << std::endl;
	q2.pop();
	std::cout << q2.len() << std::endl;
}
int main(int argc, char* argv[])
{
	std::thread thr1(test1);
	std::thread thr2(test2);

	thr1.join();
	thr2.join();
	return EXIT_SUCCESS;
}