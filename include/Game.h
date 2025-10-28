#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

class Game {
private:
    int maxRange;
    bool add, sub, mul, div;
    int lives;
    int score;

    char getUserAnswer();
    void generateQuestion();
    int calculateResult(int a, int b, char op);
    std::vector<char> getSelectedOperations();

    bool askOperation(const std::string& text);

public:
    Game();
    void start();
};
