#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame(int targetNumber) {
    int guess;
    int guessCount = 0;

    std::cout << "Welcome to the Number Guessing Game!" <<std::endl;
    std::cout << "I'm thinking of a number between 1 and 100. Can you guess it?" <<std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Discard invalid input
            std::cout << "Please enter a valid integer." <<std::endl;
            continue;
        }

        guessCount++;

        if (guess > targetNumber) {
            std::cout << "Lower!"<<std::endl;
        } else if (guess < targetNumber) {
            std::cout << "Higher!"<<std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number: " << targetNumber << std::endl;
            std::cout << "It took you " << guessCount << " guesses." <<std::endl;
            break;
        }
    }
}

int main() {
    char playAgain;
    do {
        // Initialize random number generator
        std::srand(static_cast<unsigned int>(std::time(0)));
        int targetNumber = (std::rand() % 100) + 1;  // Generates a number between 1 and 100

        // Start the guessing game
        playGame(targetNumber);

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing!" <<std::endl;
    return 0;
}