#ifndef M2OEP_MKELLE20_ROULETTE_H
#define M2OEP_MKELLE20_ROULETTE_H

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

#endif //M2OEP_MKELLE20_ROULETTE_H
