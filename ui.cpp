#include "game.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

void initializeGame(Game& game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game.board[i][j] = ' ';
        }
    }
    game.currentPlayer = 'X';
    game.gameOver = false;
}

void printBoard(const Game& game) {
    cout << "\n   | 0 | 1 | 2 |" << endl;
    cout << "---+---+---+---+" << endl;

    for (int i = 0; i < 3; i++) {
        cout << " " << i << " | ";
        for (int j = 0; j < 3; j++) {
            cout << game.board[i][j] << " | ";
        }
        cout << endl;
        cout << "---+---+---+---+" << endl;
    }
    cout << "Tekushiy igrok: " << game.currentPlayer << endl;
}

bool makeMove(Game& game) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Igrok " << game.currentPlayer << ", Vvedite stroku i stolbec (0-2) cherez probel ili 'q' dlya vihoda: ";

        string input;
        getline(cin, input);

        // Проверка на команду выхода
        if (input == "q" || input == "Q" || input == "quit" || input == "exit") {
            cout << "Vihod iz igri..." << endl;
            return false; // Сигнализируем о выходе
        }

        // Используем stringstream для разбора ввода
        stringstream ss(input);

        // Проверяем, что ввод содержит два числа
        if (ss >> row >> col) {
            // Проверяем, что после чисел нет лишних символов
            string remaining;
            if (ss >> remaining) {
                cout << "Oshibka: Vvedeni lishniy simboly, vvedite simboly ot 0 do 2" << endl;
                continue;
            }

            // Проверяем корректность хода
            if (isValidMove(game, row, col)) {
                game.board[row][col] = game.currentPlayer;
                validMove = true;
            }
            else {
                cout << "Neverniy hod! Kletka zanyta ili vne diapozona 0-2." << endl;
            }
        }
        else {
            cout << "Oshibka: Vvedite dva chisla ot 0 do 2 ili 'q' dlya vihoda." << endl;
        }
    }
    return true; // Ход успешно сделан
}

void printResult(const Game& game) {
    printBoard(game);

    bool win = checkWin(game);
    bool draw = checkDraw(game);

    if (win) {
        cout << "\n Pozdravlyaem! Igrok " << game.currentPlayer << " Pobedil!" << endl;
    }
    else if (draw) {
        cout << "\n Nichya! Game is over." << endl;
    }
}

