#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include "Roulette.h"
using namespace std;

Roulette::Roulette() : money(1000) {
    std::cout << "You have $" << money << " USD to start with." << std::endl;
}

Roulette::Roulette(const int& startingMoney) : money(startingMoney) {
    std::cout << "You have $" << money << " USD to start with." << std::endl;
}

void Roulette::menu() {
    std::cout << "You have $" << money << " USD currently." << std::endl;
}

/**
 * Will call a command line to call game_stats.py and create a graph of the high and low numbers based on the numbers generated in Roulette.cpp (randomNumber) in the text file roulette_numbers.txt.
 * Game will resume after the user exits out of the python graphs.
 * @return
 */
long int Roulette::wage() {
    long int wage = 0;
    std::cout << "How much money would you like to bet? ";
    while (!(std::cin >> wage) || wage > money) {
        if (wage > money) {
            std::cout << "That is not valid." << std::endl;
        }
        else {
            std::cout << "Please enter a valid wage." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }

    // Prompting the user to bet on a table number
    std::cout << "Enter a number from 1-36 to bet on: ";

    int tableNumber = 0;
    //  Validates that the number is not greater than 36 or less than 1, else statement
    //  reprompts user to reselect a valid table number
    while(!(std::cin >> tableNumber) || tableNumber > 36 || tableNumber < 1) {
        if (tableNumber > 36 || tableNumber < 1) {
            std::cout << "That is not a valid number on the roulette wheel!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        else {
            std::cout << "Please enter a valid number on the roulette wheel." << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
    // opening up a file 'roulette_numbers.txt.' to write to as an outfile
    std::ofstream outFile;
    outFile.open("roulette_numbers.txt", std::ios::app);

    // Generating a random number using the Mersene Twist Algorithm
    std::vector<int> rdnumber;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1,36);
    int randomNumber = distr(gen);
    int win = 0;

    outFile << randomNumber << std::endl;

    // print statement that displays the number pulled from the table
    std::cout << std::endl << "The next number pulled is " << randomNumber << std::endl;

    if (tableNumber == randomNumber) {
        win = wage * 2;
        std::cout << "You have won $" << win << " USD!" << std::endl;
    }
    else if (tableNumber != randomNumber) {
        win = -wage;
        std::cout << "You have lost $" << wage << " USD!" << std::endl;
    }
    outFile.close();

    // calls the game_stats.py file to generate python graphs
    system("python3 ../game_stats.py");

    // calls the colors_stats.R file to generate R ggplot graph, can be accessed by opening the images
    system("rScript ../colors_stats.R");
    return win;
}


void Roulette::addWinnings(const long int& win) {
    money += win;
}

bool Roulette::loseGame() {
    return money == 0;
}


