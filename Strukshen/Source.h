#pragma once

struct Car	// ��������� Car �� ������ ������ ������, ��� ������.
{
	int speed;
	char name[50];
	float weight;
};

struct Abstract
{
	float width, height;
};

void calc(struct Abstract *obj) {
	float res = obj->height * obj->width;
	printf("Result: %.2f\n", res);
};

/*float operac(float num_first, float num_second, char znak) {
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
		printf("������ �� �������������!\n");
		break;
	}

	return res;
};

void Calculator() {
	float a = 0, b = 0;
	char z = '0';

	printf("������ �����: (�����, ���� ��������, �����)\n");
	printf("����� ��������: ( + ), ( - ), ( / ), ( * )\n");

	scanf("%f %s %f", &a, &z, &b);

	while (b == 0) {
		printf("�� 0 ������ ������!\n ����� ������ �����: ");
		scanf("%f", &b);
	}

	printf("���������: %f\n", operac(a, b, z));

}; */

