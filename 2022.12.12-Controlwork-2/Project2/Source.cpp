#include<iostream>

void reverse(int n, int* a);
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int* a = nullptr;
	a = new int [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}
	reverse(n, a);
	delete[]a;
	return EXIT_SUCCESS;
}
void reverse(int n, int* a)
{
	if (n == 1)
	{
		std::cout << a[0] << " ";
	}
	else
	{
		int* d = nullptr;
		d = new int [n - 1] { 0 };
		for (int i = 0; i < n - 1; ++i)
		{
			d[i] = a[i + 1];
		}
		reverse(n - 1, d);
		std::cout << a[0] << " ";
		delete[]d;
	}
}