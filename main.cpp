// Main Menu cases and logic

#include "Roulette.h"
#include <memory>
#include <iostream>

void clearMenu();
void pauseMenu();

int mainMenu();

Roulette* initializeGame();
Roulette* initializeGame(const int& startingMoney);
void playRoulette(std::unique_ptr<Roulette> &game);
void options();
void rules();

// declaring the starting balance $1000 USD
long int startingMoney = 1000;

int main() {
    bool quit = false;

    do {
        clearMenu();
        switch (mainMenu()) {
        case 1: {
            std::unique_ptr<Roulette> roulette(initializeGame(startingMoney));
            playRoulette(roulette);
            break;
        }
        case 2:
            rules();
            break;

        case 3:
            options();
             break;

        case 4:
            quit = true;
            break;
        }
    } while (!quit);

    return 0;
}

void clearMenu() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void pauseMenu() {
#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#else
    std::cout << "Hit enter to continue..." << std::endl;
    system("read read");
#endif
}

/**
 * mainMenu() function displays the 4 menu options available to the user, and defines choice = 0 as the
 * choice to be selected by the user. There is input validation to ensure that a choice from 1 - 4 is
 * selected (not a random number or char input). The menu options are as follows:
 *
 * 1: Play Roulette - starts the roulette game with function void playRoulette()
 * 2: Rules - displays the rules for the roulette game with function void rules()
 * 3: Game Options - gives the user the option to change their starting $ balance with the function void options()
 * 4: Quit Game - terminates the game with the exit code 0
 *
 * @return: int choice (user selected choice from menu)
 */
int mainMenu() {
    std::cout << "Roulette Game Main Menu" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "1: Play Roulette" << std::endl;
    std::cout << "2: Rules" << std::endl;
    std::cout << "3: Game Options" << std::endl;
    std::cout << "4: Quit Game" << std::endl;
    std::cout << std::endl;
    std::cout << "Please select an option from the menu: " << std::endl;

    int choice = 0;

    while (!(std::cin >> choice) || choice < 1 || choice > 4) {
        if (choice < 1 || choice > 4) {
            std::cout << "That is not a valid option!" << std::endl;
        }
        else {
            std::cin.clear();
            std::cin.ignore();
        }
    }
    return choice;
}

Roulette* initializeGame() {
    return new Roulette;
}

Roulette* initializeGame(const int& startingMoney) {
    return new Roulette(startingMoney);
}

/**
 * void playRoulette: function has a while loop if the game is not a lost game (loseGame) then the winnings will be added.
 * If the user has no more funds, then they will be returned to the main menu.
 * @param roulette
 */
void playRoulette(std::unique_ptr<Roulette> &roulette) {
    while (!roulette->loseGame()) {
        clearMenu();
        roulette->menu();
        long int win = roulette->wage();
        roulette->addWinnings(win);
        pauseMenu();
    }
    std::cout << std::endl << "There are no more funds available and you have lost!" << std::endl;
    pauseMenu(); // calls the function
}
/**
 * void Options: options is choice #3 on the menu. It shows the option for the user to change their starting balance.
 * The default balance is $1000.00 USD if not specified, but the user can change their starting balance to be
 * higher or lower than the default. Otherwise, the user can go back to the main menu.
 */
void options() {
    bool quit = false;
    while(!quit) {
        clearMenu();
        std::cout << "Roulette Game Options" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "1: Starting Money: $" << startingMoney << std::endl;
        std::cout << "2: Go Back" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Please select an option from the menu: " << std::endl;

        int choice = 0;
        // Validating that the user selects a valid choice option
        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            if (choice < 1 || choice > 3) {
                std::cout << "That is not a valid option." << std::endl;
            }
            else {
                std::cout << "Please enter a valid option." << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
        switch (choice) {
            // case 1 asks the user to specify their starting balance amount
            case 1:
                clearMenu();
                std::cout << "Enter your starting money (in USD): ";
                // validates that their specified starting balance is greater than 1
                while (!(std::cin >> startingMoney) || startingMoney < 1) {
                    if (startingMoney < 1) {
                        std::cout << "You need more money to begin playing." << std::endl;
                    }
                    else {
                        std::cout << "Enter a valid option." << std::endl;
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                break;
            // quits and ends the game if choice 2 is selected
            case 2:
                quit = true;
                break;
        }
    }
}

/**
 * void rules(): displays the rules of the game and how to play. The user can get out of the rules page when the user
 * hits enter, which is prompted by the pauseMenu() function.
 */
void rules() {
    clearMenu();
    std::cout << "Roulette Game Rules" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "You begin the game with $" << startingMoney << " USD. If you would like to change your starting amount manually,\nplease select '3: Game Options' on the main menu to do so.\n\nYou will place a bet of any dollar amount you wish, and then you will predict a number 1 through 36 to be\nchosen at random. If your number is pulled, you win double your betting amount. If your number is not pulled,\nyou lose exactly the $ amount that you bet. Keep playing until you reach $0!" << std::endl;
    std::cout << "" << std::endl;
    pauseMenu(); // calls the function
}
