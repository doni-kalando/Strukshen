#pragma once
void hello() {
	printf("Hello, MVStudio!\n");
}

float operac(float num_first, float num_second, char znak) {
	float res = 0;

	switch (znak)
	{
	case '+':
		res = num_first + num_second;
		break;
	case '-':
		res = num_first - num_second;
		break;
	case '*':
		res = num_first * num_second;
		break;
	case '/':
		res = num_first / num_second;
		break;
	default:
		printf("Символ не соответствует!\n");
		break;
	}

	return res;
};

struct Car	// Структура Car со своими типами данных, как шаблон.
{
	int speed;
	char name[50];
	float weight;
};

void Calculator() {
	float a = 0, b = 0;
	char z = '0';

	printf("Формат ввода: (число, знак операции, число)\n");
	printf("знаки операции: ( + ), ( - ), ( / ), ( * )\n");

	scanf("%f %s %f", &a, &z, &b);

	while (b == 0) {
		printf("На 0 делить нельзя!\n Ввите другое число: ");
		scanf("%f", &b);
	}

	printf("Результат: %f\n", operac(a, b, z));

};
