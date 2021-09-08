#include <iostream>
#include <ctime>
#include <cstdlib>

void mainGame();
void clearcin();

int main() {
	mainGame();

	return 0;
}

void clearcin() {
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}

void mainGame() {

	bool game{ true };
	char gameRepeat{};
	bool repeat{ true };
	int counter{ 1 };
	int highScore{ 1000 };

	std::srand(std::time(nullptr));
	int randNumb;

	while (game == true) {
		game = false;
		system("cls");

		std::cout << "What difficulty would you like to play?" << std::endl
			<< "1. Easy (Number from 1 to 5)" << std::endl
			<< "2. Medium (Number from 1 to 10)" << std::endl
			<< "3. Hard (Number from 1 to 50)" << std::endl;
		int difficulty;
		std::cin >> difficulty;
		clearcin();

		switch (difficulty) {
		case 1:
			randNumb = rand() % 5 + 1;
			std::cout << "Easy difficulty? You can do better than that, but alright." << std::endl;
			break;
		case 2:
			randNumb = rand() % 10 + 1;
			std::cout << "Medium difficulty? Still a little bit too easy, but I guess it's good enough." << std::endl;
			break;
		case 3:
			randNumb = rand() % 50 + 1;
			std::cout << "Dearing today?" << std::endl;
			break;
		}

		while (repeat == true) {
			repeat = false;

			std::cout << "Guess my number: ";
			int guessedNumb;
			std::cin >> guessedNumb;
			clearcin();

			if (guessedNumb == randNumb) {
				std::cout << "You guessed the correct number! Gongrats!" << std::endl;
				std::cout << "It took you this many guesses: " << counter << std::endl << std::endl;

				if (counter < highScore) {
					highScore = counter;
					std::cout << "New highscore!: " << highScore << std::endl;
				}
				else if (counter >= highScore) {
					std::cout << "You did not beat the high score. Current high score is: " << highScore << std::endl;
				}

				counter = 1;
				break;
			}
			else if (guessedNumb > randNumb) {
				std::cout << "The number is too high, try again." << std::endl;
				repeat = true;
			}
			else if (guessedNumb < randNumb) {
				std::cout << "The number is too low, try again." << std::endl;
				repeat = true;
			}
			else {
				std::cout << "I said a number!" << std::endl;
				repeat = true;
			}
			counter += 1;
		}

		while (true) {
			std::cout << "Do you want to continue? (y/n): ";
			std::cin >> gameRepeat;
			clearcin();
			gameRepeat = tolower(gameRepeat);

			if (gameRepeat == 'y') {
				std::cout << std::endl << std::endl;
				game = true;
				repeat = true;
				break;
			}
			else if (gameRepeat == 'n') {
				exit(0);
			}
		}

	}

}