#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*************************************\n");
	printf("****1.play *************** 0.exit****\n");
	printf("*************************************\n");
}

void game()
{
	printf("��Ϸ��ʼ\n");
	char mine[ROWS][COLS] = { 0 };//������
	char show[ROWS][COLS] = { 0 };//�Ų���
	//��ʼ��
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');

	//��ӡ����
	/*showboard(mine, ROW, COL);*/
	showboard(show, ROW, COL);

	//������
	setmine(mine,ROW,COL);
	showboard(mine, ROW, COL);

	//ɨ��
	int ret = 1;
	while (ret)
	{
		ret = play(mine, show);
		system("cls");

		if (ret == 0)
		{
			printf("bang\n");
			printf("you lose the game\n");
			yourboard(show, mine,ROW,COL);
			break;
		}
		showboard(show, ROW, COL);
		ret = win(show, ROW, COL);
	} 
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������");
			break;
		}
	} while (input);

	return 0;
}
