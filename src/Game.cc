#include "Game.h"
#include "Ranking.h"
#include <random>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Game::Game() {
    srand(static_cast<unsigned int>(time(nullptr)));
    score = 0;
    lives = 3;
}

void Game::start() {
    cout << "=== NOWA GRA ===\n\n";

    cout << "Zakres dzialan (liczba): ";
    cin >> maxRange;

    while (cin.fail() || maxRange <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawna liczba. Podaj dodatni numer: ";
        cin >> maxRange;
    }

    cout << "\nWybierz dzialania, ktore maja sie pojawiac (1 = tak, 0 = nie)\n";

    add = askOperation("Dodawanie (+): ");
    sub = askOperation("Odejmowanie (-): ");
    mul = askOperation("Mnozenie (*): ");
    div = askOperation("Dzielenie (/): ");

    if (!add && !sub && !mul && !div) {
        cout << "\nMusisz wybrac przynajmniej jeden typ dzialania!\n";
        return;
    }

    lives = 3;
    score = 0;

    cout << "\nMasz " << lives << " zycia.\n";
    cout << "----------------------------------\n";

    int questionNumber = 1;

    while (lives > 0) {
        cout << "\nPytanie " << questionNumber++ << ":\n";
        generateQuestion();
    }

    cout << "\n==============================\n";
    cout << " KONIEC GRY!\n";
    cout << " Twoj wynik: " << score << " punktow\n";
    cout << "==============================\n";

    string name;
    cout << "\nPodaj swoje imie (bez spacji): ";
    cin >> name;

    Ranking ranking;
    ranking.addScore(name, score);

    cout << "\nWynik zostal zapisany w rankingu!\n";
    cout << "Wcisnij Enter, aby wrocic do menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool Game::askOperation(const string& text) {
    int choice;
    cout << text;
    cin >> choice;

    while (cin.fail() || (choice != 0 && choice != 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wpisz 1 (tak) lub 0 (nie): ";
        cin >> choice;
    }

    return choice == 1;
}

void Game::generateQuestion() {
    vector<char> ops = getSelectedOperations();
    char op = ops[rand() % ops.size()];

    int a = 0, b = 0, correctAnswer = 0;

    switch (op) {
        case '+':
            a = rand() % (maxRange / 2 + 1);
            b = rand() % (maxRange / 2 + 1);
            correctAnswer = a + b;
            break;

        case '-':
            a = rand() % maxRange;
            b = rand() % a;
            correctAnswer = a - b;
            break;

        case '*':
            a = rand() % (maxRange / 10 + 1);
            b = rand() % (maxRange / (a + 1) + 1);
            correctAnswer = a * b;
            break;

        case '/':
            b = rand() % 9 + 1;
            correctAnswer = rand() % maxRange / 2 + 1;
            a = correctAnswer * b;
            break;
    }

    vector<int> answers = { correctAnswer };
    while (answers.size() < 4) {
        int fake = correctAnswer + (rand() % 11 - 5);
        if (fake != correctAnswer && fake >= 0)
            answers.push_back(fake);
    }

    shuffle(answers.begin(), answers.end(), default_random_engine(random_device{}()));

    vector<char> labels = {'A', 'B', 'C', 'D'};
    char correctLetter = ' ';
    for (int i = 0; i < 4; ++i)
        if (answers[i] == correctAnswer)
            correctLetter = labels[i];

    cout << "Ile to jest: " << a << " " << op << " " << b << " ?\n";
    for (int i = 0; i < 4; ++i)
        cout << labels[i] << ") " << answers[i] << "\n";

    char userAnswer = getUserAnswer();

    if (toupper(userAnswer) == correctLetter) {
        cout << "Dobrze!\n";
        score += 1;
    } else {
        cout << "Zla odpowiedz! Poprawna to " << correctLetter << ".\n";
        lives--;
        cout << "Pozostalo zyc: " << lives << "\n";
    }
}

char Game::getUserAnswer() {
    char choice;
    cout << "Twoj wybor (A–D): ";
    cin >> choice;

    while (toupper(choice) < 'A' || toupper(choice) > 'D') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wybor! Wpisz litere A–D: ";
        cin >> choice;
    }

    return toupper(choice);
}

vector<char> Game::getSelectedOperations() {
    vector<char> ops;
    if (add) ops.push_back('+');
    if (sub) ops.push_back('-');
    if (mul) ops.push_back('*');
    if (div) ops.push_back('/');
    return ops;
}
