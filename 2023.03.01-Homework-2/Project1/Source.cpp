#include <iostream>
#include <string>
#include<ctime>

enum Animaltype
{
	None = 0,
	Fish = 1,
	Cat = 2,
	Dog = 3,
	Wolf = 4,
	Bear = 5,
	Dragon = 6
};

class Animal
{
public:
	std::string name;
	Animal()
	{
		name = "";
		type = None;
		force = 1;
	}
	Animal(std::string name, Animaltype type, int force) :
		name(name), type(type), force(force) {}
	Animal(const Animal& anim) :
		name(anim.name), type(anim.type), force(anim.force) {}

	std::string getName() { return name; }
	Animaltype getType() { return Animaltype(type);}
	int getForce() { return force; }
	void setName(std::string name)
	{
		this->name = name;
	}
	void setType(Animaltype type)
	{
		this->type = type;
	}
	void setForce(int force)
	{
		if (force > 0)
		{
			this->force = force;
		}
	}
	void Printinfo()
	{
		std::cout << name << " " << getType() << " " << getForce() << std::endl;
	}
	void Mighter()
	{
		force++;
	}
	~Animal() {}
private:
	Animaltype type;
	int force;

};

Animal hunting(Animal& anim1, Animal& anim2)
{
	Animal win = Animal();
	if (anim1.getType() == anim2.getType())
	{
		if (anim1.getForce() > anim2.getForce())
		{
			anim1.Mighter();
			anim2.~Animal();
			win = anim1;
		}
		else
		{
			anim2.Mighter();
			anim1.~Animal();
			win = anim2;
		}
	}
	else
	{
		if (anim1.getType() > anim2.getType())
		{
			anim1.Mighter();
			anim2.~Animal();
			win = anim1;
		}
		else
		{
			anim2.Mighter();
			anim1.~Animal();
			win = anim2;
		}
	}
	return win;
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int lower = 10;
	int upper = 99;

	Animal* a = nullptr;
	a = new Animal[100];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = Animal("Bob", Animaltype((rand() % 6) + 1), (rand() % (upper - lower + 1) + lower));
	}
	for (int i = 0; i < 100; ++i)
	{
		a[i].Printinfo();
	}

	Animal winner = a[0];
	for (int i = 1; i < 100; ++i)
	{
		winner = hunting(winner, a[i]);
	}
	winner.Printinfo();

	delete[] a;
	return EXIT_SUCCESS;
}