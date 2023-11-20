#ifndef RouletteGame_ROULETTE_H
#define RouletteGame_ROULETTE_H

class Roulette {
public:
    Roulette();
    Roulette(const int &startingMoney);
    void menu(); // shows the menu options labeled 1 - 5
    long int wage();
    void addWinnings(const long int &win);
    bool loseGame();

private:
    long int money;
};

#endif //RouletteGame_ROULETTE_H
