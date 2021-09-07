#include <iostream>
#include <ctime>
#include <cstdlib>

void clearcin();

int main() {

	int randNumb;
	bool repeat{true};
	int guessedNumb;

	std::srand(std::time(nullptr));
	randNumb = rand() % 100 + 1;

	while (repeat == true) {
		repeat = false;
		
		std::cout << "Guesse my number: ";
		std::cin >> guessedNumb;
		clearcin();

		if (guessedNumb < randNumb) {
			std::cout << "The number is too low, try again." << std::endl;
			repeat = true;
		}
		else if (guessedNumb > randNumb) {
			std::cout << "The number is too high, try again." << std::endl;
			repeat = true;
		}
		else if (guessedNumb == randNumb) {
			std::cout << "You guessed the correct number! Gongrats! Bye..." << std::endl;
			return 0;
		}
		else {
			std::cout << "I said a number!" << std::endl;
			repeat = true;
			break;
		}
	}

	return 0;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}