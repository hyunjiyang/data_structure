#include<stdio.h>
#include<stdlib.h>
#include<time.h> //랜덤함수

#define STACK_SIZE 200
#define MAX 20
#define FALSE 0
#define TRUE 1


typedef struct {

	short int row;

	short int col;

	short int dir;

}element;

//스택 형성
element stack[STACK_SIZE], position;



//탐색 경로

typedef struct {

	short int vert;

	short int horiz;

}offsets;


//탐색 방향 (북동서남) 전역변수로 지정
offsets move[4] = { {-1,0},{0,1},{1,0},{0,-1} };



//함수 정의

void Go(int(*maze)[MAX], int row, int col); //미로 탐색

element pop(int* top); //스택 pop

void push(int* top, element item); //스택 추가



main()

{
	int i, j, row, col, maze[MAX][MAX]; //변수 선언


		srand((unsigned)time(NULL)); //랜덤값 변화

		//랜덤으로 미로를 무작위로 생성

		printf("\n");

		printf("미로 크기 입력 : (row,col) : ");

		scanf_s("%d %d", &row, &col);

		printf("\n");



		for (i = 0; i < row; i++)

		{
			for (j = 0; j < col; j++)

			{
				maze[i][j] = rand() % 2; //2로 나눈 나머지 값으로 0과 1만 넣는다
				maze[i][i] = 0; //큰 크기를 만듬으로 대각선에 0을 넣어주기
			}
		}

		for (i = 0; i < col; i++) //테두리를 모두 1로 넣는다.

		{
			maze[0][i] = 1;
			maze[row - 1][i] = 1;
			maze[i][col - 1] = 1;
			maze[i][0] = 1;
		}
		

		maze[1][1] = 0; //입구와 출구를 0으로 설정

		maze[row - 2][col - 2] = 0;


		//미로 출력

		printf("선택한 크기의 미로 생성.\n");

		for (i = 0; i < row; i++)

		{
			printf("\n");

			for (j = 0; j < col; j++)

			{
				printf("%3d", maze[i][j]);
			}

		}

		printf("\n\n");



	//탐색함수 호출

	Go(maze, row, col);

	return 0;

}

//탐색 함수
void Go(int(*maze)[MAX], int r, int c)

{

	int i, j, top, row, col, n_row, n_col, dir, mark[MAX][MAX], found = FALSE;


	//mark값 초기화

	for (i = 0; i < MAX; i++)

	{

		for (j = 0; j < MAX; j++)

		{

			mark[i][j] = 0;

		}

	}



	mark[1][1] = 1; //시작점 1,1로 설정


	top = 0; 

	//출발점으로 두고 탐색 방향은 북쪽부터 시작하도록 한다.

	stack[0].row = 1;

	stack[0].col = 1;

	stack[0].dir = 1;



	while (top > -1 && !found)

	{

		position = pop(&top); //잘못 간 구역은 스택에서 제거

		row = position.row;

		col = position.col;

		dir = position.dir;


		while (dir < 4 && !found) //찾을때까지 북동서남으로 탐색

		{

			n_row = row + move[dir - 1].vert;

			n_col = col + move[dir - 1].horiz;



			//출구 도착 시 found =1

			if (n_row == r - 2 && n_col == c - 2)

				found = TRUE;
			//mark에 이미 입력된 같던 곳이라면 dir 증가시켜서 다시탐색
			else if (!maze[n_row][n_col] && !mark[n_row][n_col])

			{

				mark[n_row][n_col] = 1; //mark하기

				position.row = row;

				position.col = col;

				position.dir = ++dir;



				push(&top, position); //position에 top주소값 push

				row = n_row;

				col = n_col;

				dir = 0;

			}

			else ++dir;

			//dir 을 증가시켜 북쪽부터 시계방향으로 출구 검색

		}

	}



	//출력 부분

	if (found) //found가 1(TRUE)일때

	{

		printf("[탈출한 미로 경로]\n");

		printf("\n");

		printf("  -- 시작 --  ");

		for (i = 0; i <= top; i++)

			printf("[ %d , %d ] -> ", stack[i].row, stack[i].col);

		printf("[ %d , %d ] -> ", row, col);

		printf("[ %d , %d ]", r - 2, c - 2);

		printf("  -- 탈출 성공 --  ");

		printf("\n");

	}

	else

		printf("미로를 탈출할 길이 없습니다.\n");

}



// 스택 추가



void push(int* top, element item)

{

	if (*top >= STACK_SIZE - 1)

	{

		printf("스택이 가득참.\n");

		return;

	}

	stack[++ * top] = item;

}



//스택 삭제

element pop(int* top)

{

	if (*top == -1)

	{

		printf("스택이 비어있음.\n");

		return stack[STACK_SIZE];

	}

	return stack[(*top)--];

}
