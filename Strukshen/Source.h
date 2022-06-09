#pragma once

#define width 65
#define height 25

char mas[height][width + 1];		// Массив исспользуемый в виде игрового поля
int hitCnt = 0, maxHitCnt = 0;		// Счетик отражаемых Шариков и счетчик максимального колличества отраженных Шариков

typedef struct {
	int x, y, w;	// Координаты Ракетки X, У и длинна W
} TRacket;			// Тип Ракета

typedef struct {
	float x, y;		// Координаты Шарика типа float
	int ix, iy;		// Координаты Шарика типа int
	float alfa;		// 
	float speed;	// Скорость Шарика
} TBall;			// Тип Шарик

TRacket racket;	// Ракета типа Ракеты
TBall ball;		// Шарик типа Шарика
TBall ballSave;	// Копия Шарика со старыми значениями

void initRacket() {	// Инициализатор Ракеты
	racket.w = 7;
	racket.x = (width - racket.w) / 2;
	racket.y = height - 1;
}

void initBall() {	// Инициалтзатор Шарика
	ball.x = 2;
	ball.y = 2;
	ball.alfa = -1;
	ball.speed = 2,0;
}

void putRacket() {	// Всталение Ракеты на поле
	for (int i = racket.x; i < racket.x + racket.w; i++) mas[racket.y][i] = '@';
}

void putBall() {	// Вставление Шарика на поле
	mas[ball.iy][ball.ix] = '*';
}

void init() {		// Инициализация поля
	for (int i = 0; i < width; i++) mas[0][i] = '#';
	
	mas[0][width] = '\0';
	strncpy(mas[1], mas[0], width + 1);

	for (int i = 1; i < width - 1; i++) mas[1][i] = ' ';
	for (int i = 2; i < height; i++) strncpy(mas[i], mas[1], width + 1);
}

void show() {		// Отображения поля
	for (int i = 0; i < height; i++) {
		printf("%s", mas[i]);

		if (i == 3) printf(" hit %i", hitCnt);
		if (i == 4) printf(" max %i", maxHitCnt);
		if (i < height - 1) printf("\n");
	}
}

void moveRacket(int x) {	// Перемещение Ракеты
	racket.x = x;
	if (racket.x < 1) racket.x = 1;
	if (racket.x + racket.w >= width) racket.x = width - 1 - racket.w;
}

void moveBall(float x, float y) {	// Передвижение Шарика
	ball.x = x;
	ball.y = y;
	ball.ix = (int) ball.x;
	ball.iy = (int) ball.y;
	}

void avtoMoveBall() {	// Автоматическое движение Шарика
	if (ball.alfa < 0) ball.alfa += M_PI * 2;			// Ограничели движения Шарика от 0
	if (ball.alfa > M_PI * 2) ball.alfa -= M_PI * 2;	// Ограничели движения Шарика до Пи
	
	ballSave = ball;

	moveBall(ball.x + cos(ball.alfa) * ball.speed, ball.y + sin(ball.alfa) * ball.speed);	// Смена координат Шарика

	if ((mas[ball.iy][ball.ix] == '#') || (mas[ball.iy][ball.ix] == '@')) {	// Если Шарик сталкнулся со стеной поля или Ракетой
		if (mas[ball.iy][ball.ix] == '@') hitCnt++;								// + к колличеству ударов Шарика об Ракетку
		if ((ball.ix != ballSave.ix) && (ball.iy != ballSave.iy)) {				// Сравниваем старое положение Шарика с новым
			if (mas[ballSave.iy][ball.ix] == mas[ball.iy][ballSave.ix])			// Если Шарик в углу, то меняем направление в противоположную сторону
				ballSave.alfa = ballSave.alfa + M_PI;
			else																// ИНаче ...
			{
				if (mas[ballSave.iy][ball.ix] == '#')								// Если поверхность вертикальная, то ...  
					ballSave.alfa = (2 * M_PI - ballSave.alfa) + M_PI;				// Отражение по вертикали
				else																// Иначе ...
					ballSave.alfa = (2 * M_PI - ballSave.alfa);						// Отражение по гаризонтали
			}																
		}																	
		else if (ball.iy == ballSave.iy)									// Иначе, если Y не изменялся то ... 
			ballSave.alfa = (2 * M_PI - ballSave.alfa) + M_PI;					// Отражение по вертикали
		else																// Иначе ...
			ballSave.alfa = (2 * M_PI - ballSave.alfa);							// Отражение по гаризонтали

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