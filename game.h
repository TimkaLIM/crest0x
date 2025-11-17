//
// Created by Тимур on 16.11.2025.
//

#ifndef UNTITLED8_GAME_H
#define UNTITLED8_GAME_H

struct Game {
    char board[3][3];
    char currentPlayer;
    bool gameOver;
};


void initializeGame(Game& game);
void printBoard(const Game& game);
bool makeMove(Game& game);
bool checkWin(const Game& game);
bool checkDraw(const Game& game);
void switchPlayer(Game& game);
bool isValidMove(const Game& game, int row, int col);
void printResult(const Game& game);


#endif //UNTITLED8_GAME_H
