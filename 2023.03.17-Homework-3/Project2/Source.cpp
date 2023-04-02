#include<iostream>
#include<cstring>
#include"Student.h"


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	Student* a = nullptr;
	a = new Student[n];
	for (int i = 0; i < n; ++i)
	{
		std::string name = "";
		std::string surname = "";
		int math = 1;
		int phys = 1;
		int inf = 1;
		std::cin >> name;
		std::cin >> surname;
		std::cin >> math;
		std::cin >> phys;
		std::cin >> inf;
		a[i] = Student(name, surname, math, phys, inf);
	}
	for (int i = 15; i > 2; --i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[j].Sum() == i)
			{
				a[j].Print();
			}
		}
	}
	delete[] a;
	return EXIT_SUCCESS;
}