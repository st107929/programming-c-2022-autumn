#include<iostream>
#include<cstring>

int greatest_digit(char* s);
int main(int argc, char* argv[])
{
	char* s = nullptr;
	s = new char[1000] {'0'};
	std::cin.getline(s, 1000);
	std::cout << greatest_digit(s);
	delete[] s;
	return EXIT_SUCCESS;
}
int greatest_digit(char* s)
{
	int a = 0;
	a = strlen(s);
	if (a == 1)
	{
		return int(s[0]) - 48;
	}
	else
	{
		char* d = nullptr;
		d = new char[1000] {'0'};
		for (int i = 0; i < a - 1; ++i)
		{
			d[i] = s[i];
		}
		if (int(s[a - 1]) - 48 >= greatest_digit(d))
		{
			return int(s[a - 1]) - 48;
		}
		else
		{
			return greatest_digit(d);
		}
		delete[] d;
	}
}