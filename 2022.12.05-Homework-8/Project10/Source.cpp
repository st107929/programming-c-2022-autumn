#include<iostream>

int forum(int n, int** messages, int k);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int** messages = nullptr;
	messages = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		messages[i] = new int [2] { 0 };
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cin >> messages[i][j];
		}
	}
	int k = 0;
	std::cin >> k;
	std::cout << forum(n, messages, k);
	for (int i = 0; i < n; ++i)
	{
		delete[] messages[i];
	}
	delete[] messages;
	return EXIT_SUCCESS;
}
int forum(int n, int** messages, int k)
{
	if (messages[k - 1][1] == 0)
	{
		return 1;
	}
	else
	{
		return 1 + forum(n, messages, messages[k - 1][1]);
	}
}