#pragma once
#include<iostream>
#include<cstring>
struct Student
{
	std::string name;
	std::string surname;
	int math;
	int phys;
	int inf;

	Student(std::string name = "", std::string surname = "", int math = 1, int phys = 1, int inf = 1) :
		name(name), surname(surname), math(math), phys(phys), inf(inf) {}
	Student(const Student& stud) :
		name(stud.name), surname(stud.surname), math(stud.math), phys(stud.phys), inf(stud.inf) {}
	~Student() {}

	void Print();
	int Sum();
};