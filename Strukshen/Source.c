#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Func.h"

struct Car	// ��������� Car �� ������ ������ ������, ��� ������.
{
	int speed;
	char name[50];
	float weight;
};

int main() {
	struct Car bmw;	//������� ������, �� ������ ������� Car. ����� ������ �� ���� ��� ����������.

	bmw.speed = 250;
	strcpy(bmw.name, "BMW M5");	// ��� ���������� strcpy - ��������� ���������� ����� (�, ��);
	bmw.weight = 2500.00f;

	struct Car audi = {300, "Audu A8", 2700.00f};
	printf("%s his speed: %d and weight %f\n", audi.name, audi.speed, audi.weight);
	printf("%s his speed: %d and weight %f\n", bmw.name, bmw.speed, bmw.weight);

	return 0;
}