#include <iostream>

class B
{
public:
	char e[42]{}; 
	bool h, g; 
	int a;
	double c, d;
	int f[2]{ 0 };
	int b; 
};

class Bmax
{
public:
	bool h;
	double c;
	bool g;
	double d;
	int a;
	char e[42]{};
	int f[2]{ 0 };
	int b;
};
//The number of memory cells should be a multiple of the most voluminous data type. 
//In these classes it is double (8 byte), so the sum will be 76 + 4 = 80 bytes in class B, and 92 + 4 = 96 bytes in class Bmax 

int main(int argc, char* argv[])
{
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(Bmax) << std::endl;
	return EXIT_SUCCESS;
}