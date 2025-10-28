#include <iostream>
#include <cstdlib>
#include <limits>
#include "Game.h"
#include "Ranking.h"

using namespace std;

int showMenu() {
    cout << "=============================\n";
    cout << "      GRA MATEMATYCZNA      \n";
    cout << "=============================\n";
    cout << "1. Rozpocznij gre\n";
    cout << "2. Zobacz ranking\n";
    cout << "3. Wyjscie\n";
    cout << "=============================\n";
    cout << "Wybierz opcje: ";

    int choice;
    cin >> choice;
    return choice;
}

int main() {
    int choice = 0;
    bool running = true;

    while (running) {
        system("cls");

        choice = showMenu();

        switch (choice) {
            case 1: {
                system("cls");
                cout << "Rozpoczynam nowa gre...\n\n";

                Game game;
                game.start();
                break;
            }

            case 2: {
                system("cls");
                cout << "===== RANKING =====\n\n";

                Ranking ranking;
                ranking.showTop10();

                cout << "\nWcisnij Enter, aby wrocic do menu...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                break;
            }

            case 3:
                cout << "\nDziekujemy za gre! 👋\n";
            running = false;
            break;

            default:
                cout << "\nNiepoprawny wybor. Sprobuj ponownie.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return 0;
}
