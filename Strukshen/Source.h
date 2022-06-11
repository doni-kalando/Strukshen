#pragma once

#define width 65
#define height 25
#define wall '#'

char mas[height][width + 1];		// ������ ������������� � ���� �������� ����
int hitCnt = 0, maxHitCnt = 0;		// ������ ���������� ������� � ������� ������������� ����������� ���������� �������

typedef struct {
	char shape;
	int x, y, w;	// ���������� ������� X, � � ������ W
} TRacket;			// ��� ������

typedef struct {
	char shape;
	float x, y;		// ���������� ������ ���� float
	int ix, iy;		// ���������� ������ ���� int
	float alfa;		// 
	float speed;	// �������� ������
} TBall;			// ��� �����

TRacket racket;	// ������ ���� ������
TBall ball;		// ����� ���� ������
TBall ballSave;	// ����� ������ �� ������� ����������

void initRacket() {	// ������������� ������
	racket.shape = '@';
	racket.w = 7;
	racket.x = (width - racket.w) / 2;
	racket.y = height - 1;
}

void initBall() {	// ������������� ������
	ball.shape = '*';
	ball.x = 2;
	ball.y = 2;
	ball.alfa = -1;
	ball.speed = 2,0;
}

void putRacket() {	// ��������� ������ �� ����
	for (int i = racket.x; i < racket.x + racket.w; i++) mas[racket.y][i] = racket.shape;
}

void putBall() {	// ���������� ������ �� ����
	mas[ball.iy][ball.ix] = ball.shape;
}

void init() {		// ������������� ����
	for (int i = 0; i < width; i++) mas[0][i] = wall;
	
	mas[0][width] = '\0';
	strncpy(mas[1], mas[0], width + 1);

	for (int i = 1; i < width - 1; i++) mas[1][i] = ' ';
	for (int i = 2; i < height; i++) strncpy(mas[i], mas[1], width + 1);
	// for (int j = 10; j < 50; j++) mas[10][j] = wall;
}

void show() {		// ����������� ����
	for (int i = 0; i < height; i++) {
		printf("%s", mas[i]);

		if (i == 3) printf(" hit %i", hitCnt);
		if (i == 4) printf(" max %i", maxHitCnt);
		if (i < height - 1) printf("\n");
	}
}

void moveRacket(int x) {	// ����������� ������
	racket.x = x;
	if (racket.x < 1) racket.x = 1;
	if (racket.x + racket.w >= width) racket.x = width - 1 - racket.w;
}

void moveBall(float x, float y) {	// ������������ ������
	ball.x = x;
	ball.y = y;
	ball.ix = (int) ball.x;
	ball.iy = (int) ball.y;
	}

void avtoMoveBall() {	// �������������� �������� ������
	if (ball.alfa < 0) ball.alfa += M_PI * 2;			// ���������� �������� ������ �� 0
	if (ball.alfa > M_PI * 2) ball.alfa -= M_PI * 2;	// ���������� �������� ������ �� ��
	
	ballSave = ball;

	moveBall(ball.x + cos(ball.alfa) * ball.speed, ball.y + sin(ball.alfa) * ball.speed);	// ����� ��������� ������

	if ((mas[ball.iy][ball.ix] == wall) || (mas[ball.iy][ball.ix] == racket.shape)) {	// ���� ����� ���������� �� ������ ���� ��� �������
		if (mas[ball.iy][ball.ix] == racket.shape) hitCnt++;								// + � ����������� ������ ������ �� �������
		if ((ball.ix != ballSave.ix) && (ball.iy != ballSave.iy)) {				// ���������� ������ ��������� ������ � �����
			if (mas[ballSave.iy][ball.ix] == mas[ball.iy][ballSave.ix])			// ���� ����� � ����, �� ������ ����������� � ��������������� �������
				ballSave.alfa += M_PI;
			else																// ����� ...
			{
				if (mas[ballSave.iy][ball.ix] == wall)								// ���� ����������� ������������, �� ...  
					ballSave.alfa = (2 * M_PI - ballSave.alfa) + M_PI;				// ��������� �� ���������
				else																// ����� ...
					ballSave.alfa = (2 * M_PI - ballSave.alfa);						// ��������� �� �����������
			}																
		}																	
		else if (ball.iy == ballSave.iy)									// �����, ���� Y �� ��������� �� ... 
			ballSave.alfa = (2 * M_PI - ballSave.alfa) + M_PI;					// ��������� �� ���������
		else																// ����� ...
			ballSave.alfa = (2 * M_PI - ballSave.alfa);							// ��������� �� �����������

		ball = ballSave;
		avtoMoveBall(); 
	}
}

void setcur(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}