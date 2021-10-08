#include<stdio.h>
#include<stdlib.h>
#include<time.h> //�����Լ�

#define STACK_SIZE 200
#define MAX 20
#define FALSE 0
#define TRUE 1


typedef struct {

	short int row;

	short int col;

	short int dir;

}element;

//���� ����
element stack[STACK_SIZE], position;



//Ž�� ���

typedef struct {

	short int vert;

	short int horiz;

}offsets;


//Ž�� ���� (�ϵ�����) ���������� ����
offsets move[4] = { {-1,0},{0,1},{1,0},{0,-1} };



//�Լ� ����

void Go(int(*maze)[MAX], int row, int col); //�̷� Ž��

element pop(int* top); //���� pop

void push(int* top, element item); //���� �߰�



main()

{
	int i, j, row, col, maze[MAX][MAX]; //���� ����


		srand((unsigned)time(NULL)); //������ ��ȭ

		//�������� �̷θ� �������� ����

		printf("\n");

		printf("�̷� ũ�� �Է� : (row,col) : ");

		scanf_s("%d %d", &row, &col);

		printf("\n");



		for (i = 0; i < row; i++)

		{
			for (j = 0; j < col; j++)

			{
				maze[i][j] = rand() % 2; //2�� ���� ������ ������ 0�� 1�� �ִ´�
				maze[i][i] = 0; //ū ũ�⸦ �������� �밢���� 0�� �־��ֱ�
			}
		}

		for (i = 0; i < col; i++) //�׵θ��� ��� 1�� �ִ´�.

		{
			maze[0][i] = 1;
			maze[row - 1][i] = 1;
			maze[i][col - 1] = 1;
			maze[i][0] = 1;
		}
		

		maze[1][1] = 0; //�Ա��� �ⱸ�� 0���� ����

		maze[row - 2][col - 2] = 0;


		//�̷� ���

		printf("������ ũ���� �̷� ����.\n");

		for (i = 0; i < row; i++)

		{
			printf("\n");

			for (j = 0; j < col; j++)

			{
				printf("%3d", maze[i][j]);
			}

		}

		printf("\n\n");



	//Ž���Լ� ȣ��

	Go(maze, row, col);

	return 0;

}

//Ž�� �Լ�
void Go(int(*maze)[MAX], int r, int c)

{

	int i, j, top, row, col, n_row, n_col, dir, mark[MAX][MAX], found = FALSE;


	//mark�� �ʱ�ȭ

	for (i = 0; i < MAX; i++)

	{

		for (j = 0; j < MAX; j++)

		{

			mark[i][j] = 0;

		}

	}



	mark[1][1] = 1; //������ 1,1�� ����


	top = 0; 

	//��������� �ΰ� Ž�� ������ ���ʺ��� �����ϵ��� �Ѵ�.

	stack[0].row = 1;

	stack[0].col = 1;

	stack[0].dir = 1;



	while (top > -1 && !found)

	{

		position = pop(&top); //�߸� �� ������ ���ÿ��� ����

		row = position.row;

		col = position.col;

		dir = position.dir;


		while (dir < 4 && !found) //ã�������� �ϵ��������� Ž��

		{

			n_row = row + move[dir - 1].vert;

			n_col = col + move[dir - 1].horiz;



			//�ⱸ ���� �� found =1

			if (n_row == r - 2 && n_col == c - 2)

				found = TRUE;
			//mark�� �̹� �Էµ� ���� ���̶�� dir �������Ѽ� �ٽ�Ž��
			else if (!maze[n_row][n_col] && !mark[n_row][n_col])

			{

				mark[n_row][n_col] = 1; //mark�ϱ�

				position.row = row;

				position.col = col;

				position.dir = ++dir;



				push(&top, position); //position�� top�ּҰ� push

				row = n_row;

				col = n_col;

				dir = 0;

			}

			else ++dir;

			//dir �� �������� ���ʺ��� �ð�������� �ⱸ �˻�

		}

	}



	//��� �κ�

	if (found) //found�� 1(TRUE)�϶�

	{

		printf("[Ż���� �̷� ���]\n");

		printf("\n");

		printf("  -- ���� --  ");

		for (i = 0; i <= top; i++)

			printf("[ %d , %d ] -> ", stack[i].row, stack[i].col);

		printf("[ %d , %d ] -> ", row, col);

		printf("[ %d , %d ]", r - 2, c - 2);

		printf("  -- Ż�� ���� --  ");

		printf("\n");

	}

	else

		printf("�̷θ� Ż���� ���� �����ϴ�.\n");

}



// ���� �߰�



void push(int* top, element item)

{

	if (*top >= STACK_SIZE - 1)

	{

		printf("������ ������.\n");

		return;

	}

	stack[++ * top] = item;

}



//���� ����

element pop(int* top)

{

	if (*top == -1)

	{

		printf("������ �������.\n");

		return stack[STACK_SIZE];

	}

	return stack[(*top)--];

}
