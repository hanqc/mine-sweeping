#define _CRT_SECURE_NO_WARNINGS 1 
#include "game.h"
void init_board(char L_board[ROWS + 2][COLS + 2], char board[ROWS + 2][COLS + 2], int row, int col)
{
	memset(board, 003, row*col);
	memset(L_board, '0', row*col);
}
void display_board(char board[ROWS + 2][COLS + 2], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (i = 1; i < col - 1; i++)
	{
		printf(" %2d", i);
	}
	printf("\n");

	for (i = 1; i < row - 1; i++)
	{
		printf(" %2d", i);
		for (j = 1; j < col - 1; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}

}
void set_mine(char L_board[ROWS + 2][COLS + 2])
{
	int mine = MINE;
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	while (mine)
	{
		x = rand() % (ROWS - 1) + 1;
		y = rand() % (COLS - 1) + 1;
		if (L_board[x][y] == '0')
		{
			L_board[x][y] = '1';
			mine--;
		}
	}

}
int swp(char L_board[ROWS + 2][COLS + 2], char board[ROWS + 2][COLS + 2])
{
	int count = 0;
	int x = 0;
	int y = 0;
	int i = 1;
	int x1 = 0;
	int y1 = 0;
	while (count != ROWS*COLS - MINE)
	{
		int input = 0;

		printf("****************************\n");
		printf("****  1.扫雷    2.标记  ****\n");
		printf("****************************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入坐标:\n");
			scanf("%d%d", &x, &y);
			while (i == 1)
			{
				i++;
				if (L_board[x][y] == '1')
				{
					L_board[x][y] = '0';
					while (1)
					{
						x1 = rand() % 9 + 1;
						y1 = rand() % 9 + 1;
						if (L_board[x1][y1] == '0')
						{
							L_board[x1][y1] = '1';
							break;
						}
					}
				}
				else
					break;
			}
			if (i > 1 && L_board[x][y] == '1')
			{
				printf("你踩到雷了!\n");
				return 0;
			}
			else
			{
				int ret = get_num(L_board, x, y);
				board[x][y] = ret + '0';
				display_board(board, ROWS + 2, COLS + 2);
				//display_board(L_board,ROWS+2,COLS+2);
				count++;
			}
			break;
		case 2:
			mark(board);
			break;
		default:
			break;


		}
	}

	printf("恭喜你赢了！\n");
	display_board(L_board, ROWS + 2, COLS + 2);
	return 0;


}
int get_num(char L_board[ROWS + 2][COLS + 2], int x, int y)
{
	int count = 0;
	if (L_board[x - 1][y - 1] == '1')
	{
		count++;
	}
	if (L_board[x - 1][y] == '1')
	{
		count++;
	}
	if (L_board[x - 1][y + 1] == '1')
	{
		count++;
	}
	if (L_board[x][y - 1] == '1')
	{
		count++;
	}
	if (L_board[x][y + 1] == '1')
	{
		count++;
	}
	if (L_board[x + 1][y - 1] == '1')
	{
		count++;
	}
	if (L_board[x + 1][y] == '1')
	{
		count++;
	}
	if (L_board[x + 1][y + 1] == '1')
	{
		count++;
	}
	return  count;
}
void mark(char board[ROWS + 2][COLS + 2])
{
	int x = 0;
	int y = 0;
	printf("输入需要标记的坐标：\n");
	scanf("%d%d", &x, &y);
	if (board[x][y] == 003)
	{
		board[x][y] = '*';
	}
	display_board(board, ROWS + 2, COLS + 2);

}