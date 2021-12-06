#include <iostream>

//A function that takes an integer from the user.
int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}