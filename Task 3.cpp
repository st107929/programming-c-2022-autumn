#include<iostream>
int main(int argc, char* argv[])
{
	int N = 0;
	int K = 0;

	std::cin >> N;
	std::cin >> K;

	std::cout << K % N;

	return EXIT_SUCCESS;
}