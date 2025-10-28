#include "Ranking.h"
using namespace std;

Ranking::Ranking() {
    loadRanking();
}

void Ranking::loadRanking() {
    ranking.clear();
    ifstream file(filename);
    if (!file.is_open()) return;

    PlayerScore ps;
    while (file >> ps.name >> ps.score) {
        ranking.push_back(ps);
    }
    file.close();

    sort(ranking.begin(), ranking.end(), [](const PlayerScore& a, const PlayerScore& b) {
        return a.score > b.score;
    });
}

void Ranking::saveRanking() {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Błąd: nie można zapisać do pliku " << filename << endl;
        return;
    }

    for (size_t i = 0; i < ranking.size() && i < 10; ++i) {
        file << ranking[i].name << " " << ranking[i].score << "\n";
    }
    file.close();
}

void Ranking::showTop10() {
    if (ranking.empty()) {
        cout << "Brak zapisanych wyników.\n";
        return;
    }

    cout << "==================== RANKING ====================\n";
    cout << " Miejsce |   Gracz   |  Wynik\n";
    cout << "-----------------------------------------------\n";

    for (size_t i = 0; i < ranking.size() && i < 10; ++i) {
        cout << "   " << i + 1 << ".     "
             << ranking[i].name << "\t\t"
             << ranking[i].score << " pkt\n";
    }

    cout << "=================================================\n";
}

bool Ranking::isHighScore(int score) {
    if (ranking.size() < 10) return true;

    return score > ranking.back().score;
}

void Ranking::addScore(const string& name, int score) {
    ranking.push_back({name, score});

    sort(ranking.begin(), ranking.end(), [](const PlayerScore& a, const PlayerScore& b) {
        return a.score > b.score;
    });

    if (ranking.size() > 10)
        ranking.pop_back();

    saveRanking();
}
