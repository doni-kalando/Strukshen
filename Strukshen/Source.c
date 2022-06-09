#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <corecrt_math_defines.h>
#include "Source.h"

int main() {
	setlocale(LC_ALL, "Russian");

	int rs = puts("Hello, MVStudio!");
	if (rs == EOF)
		perror("puts()"); // POSIX требует, чтобы значение errno было установлено
		
	float resus;
	BOOL run = FALSE;	// Флажок, FALSHE по умолчанию
	initRacket();		// Инициализируем Ракетку
	initBall();			// Инициализируем Шарик

	do
	{
		setcur(0,0);

		if (run) avtoMoveBall();								// Если run = TRUE, то шарик в движении
		else  moveBall(racket.x + racket.w / 2, racket.y - 1);	// Иначе шарик возвращается к Ракетке
		if (ball.iy > height) {									// Если шарик ушел за ракетку (покинул поле), то вовзращается к ракетке
			run = FALSE;
			if (hitCnt > maxHitCnt) maxHitCnt = hitCnt;				// Максимальное колличество отражаенных Шариков от Ракетки
			hitCnt = 0;												// Обнуляем счетчик
		}

		init();			// Инициализировали поле
		putRacket();	// Вставляем Ракетку
		putBall();		// Вставляем Шарик 
		show();			// Отабражение поля

		if (GetKeyState('A') < 0) moveRacket(racket.x - 3);		// Двигать ракету в лево, если достигла стены не двигать дальше
		if (GetKeyState('D') < 0) moveRacket(racket.x + 3);		// Двигать ракету в право, если достигла стены не двигать дальше
		if (GetKeyState('W') < 0) run = TRUE;					// Перевод Флажок в TRUE 

		printf("\nХ: %f:", resus = ball.x + cos(ball.alfa) * ball.speed);	// Отображение координаты Шарика по Х
		printf("\nУ: %f:", resus = ball.y + sin(ball.alfa) * ball.speed);	// Отображение координаты Шарика по У
	} while (GetKeyState(VK_ESCAPE) >= 0);					//Цыкл не закончится пока не будет нажат ESCAPE
	
	return 0;
}