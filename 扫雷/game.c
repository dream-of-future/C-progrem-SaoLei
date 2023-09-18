#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void showboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)//��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;//�к�
	int y = 0;//�к�
	int count = EASY_COUNT;
	//for(y=1;y<=row;)
	while (count)
	{
		x = rand() % col + 1;
		y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

void yourboard(char showboard[ROWS][COLS], char mineboard[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)//�ϲ���������������
	{
		for (j = 1; j <= col; j++)
		{
			if (mineboard[i][j] == '1')
			{
				showboard[i][j] = 'B';
			}
		}
	}

	for (i = 0; i <= col; i++)//��ӡ������
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)//��ӡ�ϲ��������
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",showboard[i][j]);
		}
		printf("\n");
	}
}


int play2(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int x, int y)
{
	if (showboard[y][x]==' ')
	{
		return 0;
	}
		if (x < 1 || y < 1)
		{
			return 0;
		}
		if (x > ROW || y > COL)
		{
			return 0;
		}
		int i = 0;
		int j = 0;
		int n = 0;
		int m = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (mineboard[j][i] == '1')
				{
					n++;
				}
				m++;

				if (m == 9 && n != 0)
				{
					showboard[y][x] = n + '0';
				}

				if (m == 9 && n == 0)
				{
					showboard[y][x] = ' ';
					for (i = x - 1; i <= x + 1; i++)
					{
						for (j = y - 1; j <= y + 1; j++)
						{
							if (i != x || j != y)
							{
								play2(mineboard, showboard, i, j);
							}
						}
					}
				}

			}
		}
	
	
	return 1;
}

int play(char mineboard[ROWS][COLS], char showboard[ROWS][COLS])
{
	printf("������������������:");
	int x = 0;//���±�
	int y = 0;//���±�
	scanf("%d", &x);
	scanf("%d", &y);
	if (mineboard[y][x] == '1')
	{
		showboard[y][x] = 'B';
		return 0;
	}

	if (mineboard[y][x] == '0')
	{
		int n = 0;
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (mineboard[j][i] == '1')
				{
					n++;
				}
			}
		}

		showboard[y][x] = n + '0';

		if (n == 0)
		{
			//showboard[y][x] = ' ';
			play2(mineboard, showboard, x, y);
		}


	}
	return 1;
}

int win(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] != '*')
			{
				n++;
			}
		}
	}
	if (n == COL * ROW - EASY_COUNT)
	{
		printf("��ϲ������ʤ��\n");
		return 0;
	}
	return 1;
}