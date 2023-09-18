#ifndef _GAME_H_
#define _GAME_H_
#define COL 9
#define ROW 9

#define COLS COL+2
#define ROWS ROW+2

#define EASY_COUNT 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void initboard(char board[ROWS][COLS], int rows, int cols, char set);
void showboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
int play2(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int x, int y);
int play(char mineboard[ROWS][COLS], char showboard[ROWS][COLS]);
void yourboard(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int row, int col);
int win(char showboard[ROWS][COLS], int row, int col);
#endif