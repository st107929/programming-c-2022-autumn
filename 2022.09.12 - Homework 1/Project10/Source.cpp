# include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int q1 = 0;
	int q2 = 0;

	std::cin >> a >> b;

	q1 = a / b;
	q2 = b / a;

	std::cout << (q1 * a + q2 * b) / (q1 + q2) << std::endl;

	return EXIT_SUCCESS;

}