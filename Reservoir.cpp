#include "Reservoir.h"

void Reservoir::volume(Reservoir* obj_mas)
{
	int num;

	cout << "Введите номер водоема: ";
	cin >> num;

	cout << "Объем: " << obj_mas[num - 1].width * obj_mas[num - 1].legth * obj_mas[num - 1].max_depth << "km^3\n";
}

int Reservoir::square(Reservoir* obj_mas, int num)
{
	int  S;

	S = obj_mas[num - 1].width * obj_mas[num - 1].legth;

	return S;
}

int Reservoir::compare_type(Reservoir* obj_mas, int num1, int num2)
{
	if (strcmp(obj_mas[num1 - 1].type, obj_mas[num2 - 1].type) == 0)
	{
		return 1;
	}
	return 0;
}

int Reservoir::compare_squre_one_type(Reservoir* obj_mas)
{
	int num1, num2;

	cout << "Введите номер первого водоема для сравнения: ";
	cin >> num1;
	cout << "Введите номер второго водоема: ";
	cin >> num2;

	if (compare_type(obj_mas, num1, num2) == 1)
	{
		if (square(obj_mas, num1) == square(obj_mas, num2))
		{
			return 2;
		}
		return 1;
	}
	return 0;
}

void Reservoir::copy(Reservoir* obj_mas)
{
	int num, num2;

	cout << "Введите номер копируемого водоема: ";
	cin >> num;
	cout << "Введите номер водоема куда хотите скопировать: ";
	cin >> num2;

	strcpy_s(obj_mas[num2 - 1].name, strlen(obj_mas[num - 1].name) + 1, obj_mas[num - 1].name);
	obj_mas[num2 - 1].width = obj_mas[num - 1].width;
	obj_mas[num2 - 1].legth = obj_mas[num - 1].legth;
	obj_mas[num2 - 1].max_depth = obj_mas[num - 1].max_depth;
	strcpy_s(obj_mas[num2 - 1].type, strlen(obj_mas[num - 1].type) + 1, obj_mas[num - 1].type);

	cout << "Копирование произошло успешно\n";
}