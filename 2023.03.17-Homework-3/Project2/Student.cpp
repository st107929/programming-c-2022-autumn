#include<iostream>
#include"Student.h"


	void Student::Print()
	{
		std::cout << name << " " << surname << std::endl;
	}
	int Student::Sum()
	{
		int sum = 0;
		sum = math + phys + inf;
		return sum;
	}