#include<iostream>
#include<cstring>

struct Animal {
	std::string type;
	std::string name;
	int age;

	Animal()
	{
		type = "cat";
		name = "Matroskin";
		age = 3;
	}

	Animal(std::string type, std::string name, int age)
	{
		this->type = type;
		this->name = name;
		this->age = age;
	}

	Animal(const Animal& an)
	{
		this->type = an.type;
		this->name = an.name;
		this->age = an.age;
	}

	~Animal()
	{}
};
void printAnimal(Animal an);
void elderAnimal(Animal& an);
int main(int argc, char* argv[])
{
	
	return EXIT_SUCCESS;
}
void printAnimal(Animal an)
{
	std::cout << an.type << " " << an.name << " " << an.age << std::endl;
}
void elderAnimal(Animal& an)
{
	an.age = an.age + 1;
}