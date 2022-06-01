#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Car	// Структура Car со своими типами данных, как шаблон.
{
	int speed;
	char name[50];
	float weight;
};

int main() {
	struct Car bmw;	//Создали объект, на основе шаблона Car. Имеет доступ ко всем его параменным.

	bmw.speed = 250;
	strcpy(bmw.name, "BMW M5");	// для массивовов strcpy - позволяет копировать масив (в, из);
	bmw.weight = 2500.00f;

	struct Car audi = {300, "Audu A8", 2700.00f};
	printf("%s his speed: %d\n", audi.name, audi.speed);
	printf("%s his speed: %d\n", bmw.name, bmw.speed);

	return 0;
}