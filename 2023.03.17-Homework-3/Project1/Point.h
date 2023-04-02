#pragma once
#include<iostream>

struct Point
{
	int x;
	int y;

	Point(int x = 0, int y = 0):
		x(x), y(y) {}
	Point(const Point& ppoint) :
		x(ppoint.x), y(ppoint.y) {}
	~Point() {};
	int Norma(); // Вычисляет квадрат расстояния
	void Print();
};