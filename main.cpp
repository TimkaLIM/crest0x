//main.cpp

#include <iostream>
#include "game.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Game game;
    initializeGame(game);

    cout << "========== КРЕСТИКИ-НОЛИКИ ==========" << endl;
    cout << "Для выхода в любой момент введите 'q'" << endl;
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

    cout << "Спасибо за игру! До свидания!" << endl;
    return 0;
}
