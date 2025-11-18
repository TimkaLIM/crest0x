//main.cpp

#include <iostream>
#include "game.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Game game;
    initializeGame(game);

    cout << "========== CRESTIKI-NOLIKI ==========" << endl;
    cout << "Dlya vihoda v lyboy moment nazhmite 'q'" << endl;
    cout << "======================================" << endl;

    while (!game.gameOver) {
        printBoard(game);

        // Если игрок хочет выйти (makeMove возвращает false)
        if (!makeMove(game)) {
            break;
        }

        // Проверяем условия окончания игры
        if (checkWin(game) || checkDraw(game)) {
            printResult(game);
            game.gameOver = true;
        }
        else {
            switchPlayer(game);
        }
    }

    cout << "Spasibo za igru do svidanya!" << endl;
    return 0;
}
