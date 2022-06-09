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
		perror("puts()"); // POSIX �������, ����� �������� errno ���� �����������
		
	float resus;
	BOOL run = FALSE;	// ������, FALSHE �� ���������
	initRacket();		// �������������� �������
	initBall();			// �������������� �����

	do
	{
		setcur(0,0);

		if (run) avtoMoveBall();								// ���� run = TRUE, �� ����� � ��������
		else  moveBall(racket.x + racket.w / 2, racket.y - 1);	// ����� ����� ������������ � �������
		if (ball.iy > height) {									// ���� ����� ���� �� ������� (������� ����), �� ������������ � �������
			run = FALSE;
			if (hitCnt > maxHitCnt) maxHitCnt = hitCnt;				// ������������ ����������� ����������� ������� �� �������
			hitCnt = 0;												// �������� �������
		}

		init();			// ���������������� ����
		putRacket();	// ��������� �������
		putBall();		// ��������� ����� 
		show();			// ����������� ����

		if (GetKeyState('A') < 0) moveRacket(racket.x - 3);		// ������� ������ � ����, ���� �������� ����� �� ������� ������
		if (GetKeyState('D') < 0) moveRacket(racket.x + 3);		// ������� ������ � �����, ���� �������� ����� �� ������� ������
		if (GetKeyState('W') < 0) run = TRUE;					// ������� ������ � TRUE 

		printf("\n�: %f:", resus = ball.x + cos(ball.alfa) * ball.speed);	// ����������� ���������� ������ �� �
		printf("\n�: %f:", resus = ball.y + sin(ball.alfa) * ball.speed);	// ����������� ���������� ������ �� �
	} while (GetKeyState(VK_ESCAPE) >= 0);					//���� �� ���������� ���� �� ����� ����� ESCAPE
	
	return 0;
}