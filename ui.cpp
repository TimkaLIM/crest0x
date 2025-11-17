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
    cout << "Текущий игрок: " << game.currentPlayer << endl;
}

bool makeMove(Game& game) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        cout << "Игрок " << game.currentPlayer << ", введите строку и столбец (0-2) или 'q' для выхода: ";

        string input;
        getline(cin, input);

        // Проверка на команду выхода
        if (input == "q" || input == "Q" || input == "quit" || input == "exit") {
            cout << "Выход из игры..." << endl;
            return false; // Сигнализируем о выходе
        }

        // Используем stringstream для разбора ввода
        stringstream ss(input);

        // Проверяем, что ввод содержит два числа
        if (ss >> row >> col) {
            // Проверяем, что после чисел нет лишних символов
            string remaining;
            if (ss >> remaining) {
                cout << "Ошибка: введены лишние символы. Введите два числа от 0 до 2." << endl;
                continue;
            }

            // Проверяем корректность хода
            if (isValidMove(game, row, col)) {
                game.board[row][col] = game.currentPlayer;
                validMove = true;
            }
            else {
                cout << "Неверный ход! Клетка занята или координаты вне диапазона 0-2." << endl;
            }
        }
        else {
            cout << "Ошибка: введите два числа от 0 до 2 или 'q' для выхода." << endl;
        }
    }
    return true; // Ход успешно сделан
}

void printResult(const Game& game) {
    printBoard(game);

    bool win = checkWin(game);
    bool draw = checkDraw(game);

    if (win) {
        cout << "\n Поздравляем! Игрок " << game.currentPlayer << " победил!" << endl;
    }
    else if (draw) {
        cout << "\n Ничья! Игра окончена." << endl;
    }
}

