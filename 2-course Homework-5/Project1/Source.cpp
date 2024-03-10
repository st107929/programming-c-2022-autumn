#include<iostream>
#include<string>
#include "Queue.h"

enum House
{
	None = 0,
	Gryffindor = 1,
	Slytherin = 2,
	Hufflepuff = 3,
	Ravenclaw = 4
};
std::string house(House h)
{
	if (h == 1)
		return "Gryffindor";
	else if (h == 2)
		return "Slytherin";
	else if (h == 3)
		return "Hufflepuff";
	else
		return "Ravenclaw";
}
class Unit
{
public:
	std::string name;
	int health;
	int dodge;// %
	Unit(std::string name = " ", int health = 0, int dodge = None) : name(name), health(health), dodge(dodge) {};
	~Unit() {};
};
class Beast
{
public:
	int health;
	int damage;
	Beast(int health = 0, int damage = 0) : health(health), damage(damage) {};
	void atack(Unit& u)
	{
		u.health = u.health - damage * (100 - u.dodge) / 100;
	}
	void atack(Beast& u)
	{
		u.health = u.health - damage;
	}
	~Beast() {};
};
class Dementor : public Beast
{
public:
	Dementor(int health = 0, int damage = 0)
	{
		this->health = health;
		this->damage = damage;
	}
};
class Boggart : public Beast
{
public:
	Boggart(int health = 0)
	{
		this->health = health;
		this->damage = 0;
	}
};
class Charm
{
public:
	std::string name;
	int pow;
	Charm(std::string name = " ", int pow = 0) : name(name), pow(pow) {};
	void atack(Unit& u)
	{
		if ((this->name != "expecto patronum") && (this->name != "ridiculus"))
		{
			u.health = u.health - pow * u.dodge / 100;
		}
		return;
	}
	void atack(Beast& u)
	{
		if ((this->name != "expecto patronum") && (this->name != "ridiculus"))
		{
			u.health = u.health - pow;
		}
		return;
	}
	void atack(Dementor& d)
	{
		if (this->name == "expecto patronum")
		{
			d.health = 0;
		}
	}
	void atack(Boggart& b)
	{
		if (this->name == "ridiculus")
		{
			b.health = 0;
		}
	}
	~Charm() {};
};
class Student : public Unit
{
public:
	House house;
	Queue<class Charm> charms;
	Student(std::string name = " ", int health = 0, int dodge = 0, House house = None, Charm charms1[5] = { 0 })
	{
		this->name = name;
		this->health = health;
		this->dodge = dodge;
		this->house = house;
		for (int i = 0; i < 5; ++i)
		{
			this->charms.push(charms1[i]);
		}
	};
	~Student()
	{
	}
};
class Proff : public Unit
{
public:
	House house;
	Queue<class Charm> charms;
	Proff(std::string name = " ", int health = 0, int dodge = 0, House house = None, Charm charms1[7] = { 0 })
	{
		this->name = name;
		this->health = health;
		this->dodge = dodge;
		this->house = house;
		for (int i = 0; i < 7; ++i)
		{
			this->charms.push(charms1[i]);
		}
	};
	~Proff() {};
};
void battle(Student& st1, Student& st2)
{
	while ((st1.health > 0) && (st2.health > 0) && (!(st1.charms.IsEmpty())) && (!(st2.charms.IsEmpty())))
	{
		st1.charms.front().atack(st2);
		st1.charms.pop();
		st2.charms.front().atack(st1);
		st2.charms.pop();
	}
	if (((st1.health <= 0) && (st2.health <= 0)) || (st1.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (st1.health <= 0)
	{
		std::cout << "The winner is " << st2.name << std::endl;
		return;
	}
	if (st2.health <= 0)
	{
		std::cout << "The winner is " << st1.name << std::endl;
		return;
	}
}
void battle(Student& st, Proff& pr)
{
	if (st.house != pr.house)
	{
		while ((st.health > 0) && (pr.health > 0) && (!(st.charms.IsEmpty())) && (!(pr.charms.IsEmpty())))
		{
			st.charms.front().atack(pr);
			st.charms.pop();
			pr.charms.front().atack(st);
			pr.charms.pop();
		}
		if (((st.health <= 0) && (pr.health <= 0)) || ((st.charms.IsEmpty()) && (pr.charms.IsEmpty())))
		{
			std::cout << "Nobody has won" << std::endl;
			return;
		}
		if ((st.health <= 0) || (st.charms.IsEmpty()))
		{
			std::cout << "The winner is " << pr.name << std::endl;
			return;
		}
		if (pr.health <= 0)
		{
			std::cout << "The winner is " << st.name << std::endl;
			return;
		}
	}
	else
	{
		std::cout << "You must not battle your house's proffessor" << std::endl;
	}
}
void battle(Proff& pr, Student& st)
{
	battle(st, pr);
}
void battle(Proff& pr1, Proff& pr2)
{
	while ((pr1.health > 0) && (pr2.health > 0) && (!(pr1.charms.IsEmpty())) && (!(pr2.charms.IsEmpty())))
	{
		pr1.charms.front().atack(pr2);
		pr1.charms.pop();
		pr2.charms.front().atack(pr1);
		pr2.charms.pop();
	}
	if (((pr1.health <= 0) && (pr2.health <= 0)) || (pr1.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (pr1.health <= 0)
	{
		std::cout << "The winner is " << pr2.name << std::endl;
		return;
	}
	if (pr2.health <= 0)
	{
		std::cout << "The winner is " << pr1.name << std::endl;
		return;
	}
}
void battle(Student& st, Beast& b)
{
	while ((st.health > 0) && (b.health > 0) && (!(st.charms.IsEmpty())))
	{
		st.charms.front().atack(b);
		st.charms.pop();
		b.atack(st);
	}
	if (((st.health <= 0) && (b.health <= 0)) || (st.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (st.health <= 0)
	{
		std::cout << "The winner is beast" << std::endl;
		return;
	}
	if (b.health <= 0)
	{
		std::cout << "The winner is " << st.name << std::endl;
		return;
	}
}
void battle(Beast& b, Student& st)
{
	battle(st, b);
}
void battle(Proff& pr, Beast& b)
{
	while ((pr.health > 0) && (b.health > 0) && (!(pr.charms.IsEmpty())))
	{
		pr.charms.front().atack(b);
		pr.charms.pop();
		b.atack(pr);
	}
	if (((pr.health <= 0) && (b.health <= 0)) || (pr.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (pr.health <= 0)
	{
		std::cout << "The winner is beast" << std::endl;
		return;
	}
	if (b.health <= 0)
	{
		std::cout << "The winner is " << pr.name << std::endl;
		return;
	}
}
void battle(Beast& b, Proff& pr)
{
	battle(pr, b);
}
void battle(Beast& b, Dementor& d)
{
	std::cout << "Beast can not battle dementor" << std::endl;
}
void battle(Dementor& d, Beast& b)
{
	battle(b, d);
}
void battle(Student& st, Dementor& d)
{
	while ((st.health > 0) && (d.health > 0) && (!(st.charms.IsEmpty())))
	{
		st.charms.front().atack(d);
		st.charms.pop();
		d.atack(st);
	}
	if (((st.health <= 0) && (d.health <= 0)) || (st.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (st.health <= 0)
	{
		std::cout << "The winner is dementor" << std::endl;
		return;
	}
	if (d.health <= 0)
	{
		std::cout << "The winner is " << st.name << std::endl;
		return;
	}
}
void battle(Dementor& d, Student& st)
{
	battle(st, d);
}
void battle(Proff& pr, Dementor& d)
{
	while ((pr.health > 0) && (d.health > 0) && (!(pr.charms.IsEmpty())))
	{
		pr.charms.front().atack(d);
		pr.charms.pop();
		d.atack(pr);
	}
	if (((pr.health <= 0) && (d.health <= 0)) || (pr.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (pr.health <= 0)
	{
		std::cout << "The winner is dementor" << std::endl;
		return;
	}
	if (d.health <= 0)
	{
		std::cout << "The winner is " << pr.name << std::endl;
		return;
	}
}
void battle(Dementor& d, Proff& pr)
{
	battle(pr, d);
}
void battle(Beast& b1, Beast& b2)
{
	while ((b1.health > 0) && (b2.health > 0))
	{
		b1.atack(b2);
		b2.atack(b1);
	}
	if ((b1.health <= 0) && (b2.health <= 0))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (b1.health <= 0)
	{
		std::cout << "The winner is b2" << std::endl;
		return;
	}
	if (b2.health <= 0)
	{
		std::cout << "The winner is b1" << std::endl;
		return;
	}
}
void battle(Student& st, Boggart& b)
{
	while ((st.health > 0) && (b.health > 0) && (!(st.charms.IsEmpty())))
	{
		st.charms.front().atack(b);
		st.charms.pop();
		b.atack(st);
	}
	if (((st.health <= 0) && (b.health <= 0)) || (st.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (st.health <= 0)
	{
		std::cout << "The winner is boggart" << std::endl;
		return;
	}
	if (b.health <= 0)
	{
		std::cout << "The winner is " << st.name << std::endl;
		return;
	}
}
void battle(Boggart& b, Student& st)
{
	battle(st, b);
}
void battle(Proff& pr, Boggart& b)
{
	while ((pr.health > 0) && (b.health > 0) && (!(pr.charms.IsEmpty())))
	{
		pr.charms.front().atack(b);
		pr.charms.pop();
		b.atack(pr);
	}
	if (((pr.health <= 0) && (b.health <= 0)) || (pr.charms.IsEmpty()))
	{
		std::cout << "Nobody has won" << std::endl;
		return;
	}
	if (pr.health <= 0)
	{
		std::cout << "The winner is boggart" << std::endl;
		return;
	}
	if (b.health <= 0)
	{
		std::cout << "The winner is " << pr.name << std::endl;
		return;
	}
}
void battle(Boggart& b, Proff& pr)
{
	battle(pr, b);
}
void battle(Beast& beast, Boggart& b)
{
	std::cout << "Beast can not battle Boggart" << std::endl;
}
void battle(Boggart& b, Beast& beast)
{
	battle(beast, b);
}
void battle(Boggart& boggart, Dementor& d)
{
	std::cout << "Dementor can not battle Boggart" << std::endl;
}
void battle(Dementor& d, Boggart& boggart)
{
	battle(boggart, d);
}
void battle(Boggart& b1, Boggart& b2)
{
	std::cout << "Boggart can not battle Boggart" << std::endl;
}
int main(int argc, char* argv[])
{
	Charm expelliarmus("expelliarmus", 40);
	Charm crucio("crucio", 50);
	Charm expulso("expulso", 10);
	Charm rictusempra("riktusempra", 30);
	Charm ostolbenei("ostolbenei", 40);
	Charm levikorpus("levikorpus", 10);
	Charm expecto_patronum("expecto patronum", 40);
	Charm* charms1 = new Charm[5]{ expelliarmus, ostolbenei, levikorpus, rictusempra, expecto_patronum };
	Charm* charms2 = new Charm[7]{ expelliarmus, expulso, crucio, expecto_patronum, ostolbenei, levikorpus, rictusempra };
	Student st1("Harry", 30, 30, Gryffindor, charms1);
	Proff pr("Mccgonagall", 20, 20, Slytherin, charms2);
	Dementor d(10, 20);
	Beast b(20, 30);
	Boggart boggart(10);
	battle(d, boggart);
	delete[] charms1;
	delete[] charms2;
	return EXIT_SUCCESS;
}