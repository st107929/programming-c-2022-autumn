#include<iostream>
#define m 239

class Module
{
public:
	int data;

	Module()
	{
		this->data = 0;
	}
	Module(int a)
	{
		this->data = a % m;
	}
	~Module() {}
	static int mod(int a)
	{
		while (a < 0)
		{
			a += m;
		}
		return a % m;
	}
	Module(const Module& B)
	{
		this->data = B.data;
	}
	static Module reverse(int data)
	{
		if (data != 0)
		{
			for (int i = 0; i < m; ++i)
			{
				if (mod(data * i) == 1)
					return Module(i);
			}
		}
	}
	Module operator+=(const Module& C)
	{
		this->data += C.data;
		return *this;
	}
	Module operator-=(const Module& C)
	{
		this->data -= C.data;
		return *this;
	}
	Module operator*=(const Module& C)
	{
		this->data *= C.data;
		return *this;
	}
	Module operator/=(const Module& C)
	{
		if (C.data != 0)
		{
			Module rev = reverse(C.data);
			*this *= rev;
			return *this;
		}
	}
	Module operator%=(const int a)
	{
		this->data = mod(this->data) % a;
		return *this;
	}
	friend Module operator+(const Module& a, const Module& b);
	friend Module operator-(const Module& a, const Module& b);
	friend Module operator*(const Module& a, const Module& b);
	friend Module operator/(const Module& a, const Module& b);
	friend Module bin_pow(Module a, const int b);

	bool operator>(const Module b)
	{
		return (mod(this->data) > mod(b.data));
	}
	bool operator<(const Module b)
	{
		return (mod(this->data) < mod(b.data));
	}
	bool operator==(const Module b)
	{
		return (mod(this->data) == mod(b.data));
	}
	bool operator!=(const Module b)
	{
		return (mod(this->data) != mod(b.data));
	}
	bool operator>=(const Module b)
	{
		return (mod(this->data) >= mod(b.data));
	}
	bool operator<=(const Module b)
	{
		return (mod(this->data) <= mod(b.data));
	}
	friend std::ostream& operator<<(std::ostream& st, Module a);
	friend std::istream& operator>>(std::istream& st, Module& a);
};
Module operator+(const Module& a, const Module& b)
{
	return Module(a.data + b.data);
}
Module operator-(const Module& a, const Module& b)
{
	return Module(a.data - b.data);
}
Module operator*(const Module& a, const Module& b)
{
	return Module(a.data * b.data);
}
Module operator/(const Module& a, const Module& b)
{
	if (b.data != 0)
	{
		Module rev = Module::reverse(b.data);
		return a * rev;
	}
}
std::ostream& operator<<(std::ostream& st, Module a)
{
	return st << a.mod(a.data);
}
std::istream& operator>>(std::istream& st, Module& a)
{
	int b;
	st >> b;
	a.data = a.mod(b);
	return st;
}
Module bin_pow(Module a, const int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b > 0)
	{
		if (b % 2)
		{
			return a * bin_pow(a, b - 1);
		}
		else
		{
			return bin_pow(a * a, b / 2);
		}
	}
	else
	{
		return bin_pow(Module::reverse(a.data), -b);
	}
}
int main(int argc, char* argv[])
{
	Module a(18);
	Module b(-65);
	Module c(5);
	std::cout << Module::reverse(a.data) << std::endl;
	std::cout << c + a / b << std::endl;
	std::cout << bin_pow(a, -3) << std::endl;
	return EXIT_SUCCESS;
}