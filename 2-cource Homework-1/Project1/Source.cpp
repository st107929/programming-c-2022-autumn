#include <iostream>


class B
{
public:
	char e[42]{}; // 42 bytes  
	// 0 -> 41
	bool h, g;// 1 * 2 bytes 
	// 42 -> 43
	int a; // 4 bytes 
	// 44 -> 47
	double c, d;  // 8 * 2 bytes
	// 48 -> 63
	int f[2]{ 0 };// 2 * 4 bytes
	// 64 -> 71
	int b; // 4 bytes
	// 72 -> 76
};

class Bmax
{
public:
	bool h; // 1 byte
	// 0 -> 1
	double c;
	 //8 - > 15
	bool g; // 1 byte
	 //16 -> 17
	double d;  // 8 bytes
	// 24 -> 31
	int a; // 4 bytes 
	// 32 -> 35
	char e[42]{}; // 42 bytes 
	// 36 -> 77
	int f[2]{ 0 }; // 2 * 4 bytes
	// 80 -> 87
	int b; // 4 bytes
	// 88 -> 92
};
//The number of memory cells should be a multiple of the most voluminous data type. 
//In these classes it is double (8 byte), so the sum will be 76 + 4 = 80 bytes in class B, and 92 + 4 = 96 bytes in class Bmax 

int main(int argc, char* argv[])
{
	std::cout << sizeof(B) << std::endl;
	std::cout << sizeof(Bmax) << std::endl;
	return EXIT_SUCCESS;
}