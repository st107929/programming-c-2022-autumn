#include<iostream>
#include<cstring>

void brackets(char* s);
int main(int argc, char* argv[])
{
	char* s = nullptr;
	s = new char [1000] {'0'};
	std::cin.getline(s, 1000);
	brackets(s);
	delete[]s;
	return EXIT_SUCCESS;
}
void brackets(char* s)
{
	if ((strlen(s) == 2) || (strlen(s) == 1))
	{
		std::cout << '(' << s << ')';
	}
	else
	{
		char* d = nullptr;
		d = new char [1000] {'0'};
		for (int i = 0; i < strlen(s) - 2; ++i)
		{
			d[i] = s[i + 1];
		}
		std::cout << '(' << s[0];
		brackets(d);
		std::cout << s[strlen(s) - 1] << ')';
		delete[] d;
	}
}