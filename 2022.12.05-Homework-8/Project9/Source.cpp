#include<iostream>
#include<cstring>

void reduce(char* s);
int main(int argc, char* argv[])
{
	char* s = nullptr;
	s = new char [1000] {'0'};
	std::cin.getline(s, 1000);
	reduce(s);
	delete[]s;
	return EXIT_SUCCESS;
}
void reduce(char* s)
{
	if ((strlen(s) == 1) || (strlen(s) == 2))
	{
		std::cout << s;
	}
	else
	{
		char* d = nullptr;
		d = new char [1000] {'0'};
		for (int i = 0; i < strlen(s) - 2; ++i)
		{
			d[i] = s[i + 1];
		}
		if (s[0] != s[strlen(s) - 1])
		{
			std::cout << s[0];
			reduce(d);
			std::cout << s[strlen(s) - 1];
		}
		else
		{
			reduce(d);
		}
		delete[]d;
	}
}