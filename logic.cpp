#include "game.h"
#include <iostream>
#include <windows.h>
#include <locale>
#include <codecvt>

using namespace std;

bool checkWin(const Game& game) {
    char player = game.currentPlayer;

    // Проверка строк
    for (int i = 0; i < 3; i++) {
        if (game.board[i][0] == player && game.board[i][1] == player && game.board[i][2] == player) {
            return true;
        }
    }

    // Проверка столбцов
    for (int j = 0; j < 3; j++) {
        if (game.board[0][j] == player && game.board[1][j] == player && game.board[2][j] == player) {
            return true;
        }
    }

    // Проверка диагоналей
    if (game.board[0][0] == player && game.board[1][1] == player && game.board[2][2] == player) {
        return true;
    }

    if (game.board[0][2] == player && game.board[1][1] == player && game.board[2][0] == player) {
        return true;
    }

    return false;
}

bool checkDraw(const Game& game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.board[i][j] == ' ') {
                return false;
            }
        }
    }
    return !checkWin(game);
}

void switchPlayer(Game& game) {
    game.currentPlayer = (game.currentPlayer == 'X') ? 'O' : 'X';
}

bool isValidMove(const Game& game, int row, int col) {
    return (row >= 0 && row < 3 &&
            col >= 0 && col < 3 &&
            game.board[row][col] == ' ');
}




