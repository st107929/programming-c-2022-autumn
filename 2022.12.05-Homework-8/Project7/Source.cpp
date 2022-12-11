#include<iostream>
#include<cstring>

void star(char* s);
int main(int argc, char* argv[])
{
	char* s = nullptr;
	s = new char [1000] {'0'};
	std::cin.getline(s, 1000);
	star(s);
	delete[] s;
	return EXIT_SUCCESS;
}
void star(char* s)
{
	int a = 0;
	a = strlen(s);
	if (a == 1)
	{
		std::cout << s[0];
	}
	else
	{
		char* d = nullptr;
		d = new char [1000] {'0'};
		for (int i = 0; i < a - 1; ++i)
		{
			d[i] = s[i];
		}
		star(d);
		std::cout << '*' << s[a - 1];
		delete[] d;
	}
}