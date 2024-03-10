#include <iostream>

class A
{
public:
	virtual int f1() { return 0; }
	virtual void f2() { }
	virtual char f3() { return '0'; }
};
class B : public A
{
private:
	int f1() { return 1; }
	void f2() { std::cout << "f2" << std::endl; }
	char f3() { return 'a'; }
};

int main(int argc, char* argv[])
{
	B b;
	A* b2 = &b;
	b2->f1();
	b2->f2();
	b2->f3();
	return EXIT_SUCCESS;
}