#include<iostream>

const double pi = 3.1415;
struct Shape
{
	int a = 0;
	int b = 0; 

	Shape(int a = 0, int b = 0):
		a(a), b(b) {}
	Shape(const Shape& sh) :
		a(sh.a), b(sh.b) {}
	~Shape() {};
};

struct Rectangle : public Shape
{
	Rectangle(int a = 0 , int b = 0) :
		Shape(a, b) {}
	int area()
	{
		int area = 0;
		area = a * b;
		return area;
	}
};


struct Triangle : public Shape
{
	double sin = 1; //синус угла между данными сторонами
	Triangle(int a = 0, int b = 0, double sin = 1) :
		Shape(a, b), sin(sin) {}
	Triangle(const Triangle& trian) :
		sin(trian.sin) {}
	double area()
	{
		double area = 0;
		area = 0.5 * a * b * sin;
		return area;
	}
};
struct Square : public Rectangle
{
	Square(int a = 0) :
		Rectangle(a, a) {}
	int area()
	{
		int area = 0;
		area = a * a;
		return area;
	}
};
struct Circle : Shape
{
	Circle(int a = 0) : // круг задается через диаметр 
		Shape(a, a) {}
	double area()
	{
		double area = 0;
		area = pi * a * a / 4;
		return area;
	}
};
int main(int argc, char* argv[])
{
	Rectangle rec(5, 8);
	Triangle tria(6, 10, 0.5);
	Circle omega(6);
	Square sq(10);
	std::cout << rec.area() << " " << tria.area() << " " << omega.area() << " " << sq.area() << " " << std::endl;
	return EXIT_SUCCESS;
}