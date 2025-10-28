#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct PlayerScore {
    std::string name;
    int score;
};

class Ranking {
private:
    std::vector<PlayerScore> ranking;
    const std::string filename = "ranking.txt";

    void loadRanking();
    void saveRanking();

public:
    Ranking();
    void showTop10();
    void addScore(const std::string& name, int score);
    bool isHighScore(int score);
};
