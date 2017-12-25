#ifndef __GAME_H__
#define __GAME_H__


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

#define ROWS 8
#define COLS 8
#define MINE 10

void init_board(char L_board[ROWS + 2][COLS + 2], char board[ROWS + 2][COLS + 2], int row, int col);
void display_board(char board[ROWS + 2][COLS + 2], int row, int col);
void set_mine(char L_board[ROWS + 2][COLS + 2]);
int swp(char L_board[ROWS + 2][COLS + 2], char board[ROWS + 2][COLS + 2]);
int get_num(char L_board[ROWS + 2][COLS + 2], int x, int y);
void mark(char board[ROWS + 2][COLS + 2]);



#endif //__GAME_H__