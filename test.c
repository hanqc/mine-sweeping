#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "game.h"
void game()
{
	char board[ROWS + 2][COLS + 2] = { 0 };
	char L_board[ROWS + 2][COLS + 2] = { 0 };
	init_board(L_board, board, ROWS + 2, COLS + 2);
	display_board(board, ROWS + 2, COLS + 2);
	set_mine(L_board);
	//display_board(L_board,ROWS+2,COLS+2);
	swp(L_board, board);

}
void menu()
{
	printf("****************************\n");
	printf("****** 1.play  0.exit ******\n");
	printf("****************************\n");
}
int main()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择");
			break;
		}
	} while (input);
	return 0;
}