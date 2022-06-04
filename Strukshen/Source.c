#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "Source.h"

int main() {
	setlocale(LC_ALL, "Russian");

	int rs = puts("Hello, MVStudio!");
	if (rs == EOF)
		perror("puts()"); // POSIX требует, чтобы значение errno было установлено

	struct Car bmw;	//Создали объект, на основе шаблона Car. Имеет доступ ко всем его параменным.

	bmw.speed = 250;
	strcpy(bmw.name, "BMW M5");	// для массивовов strcpy - позволяет копировать масив (в, из);
	bmw.weight = 3111.00f;

	struct Car audi = { 300, "Audu A8", 2723.00f };

	struct Abstract square = {5, 7};

	calc(&square);

	printf("Има машины: %s, её скорость: %d, её вес: %f\n", audi.name, audi.speed, audi.weight);
	printf("Има машины: %s, её скорость: %d, её вес: %f\n\n", bmw.name, bmw.speed, bmw.weight);

	/* Calculator(); */ 
	
	return 0;
}