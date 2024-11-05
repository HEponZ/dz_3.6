#include "Reservoir.h"

void Reservoir::volume(Reservoir* obj_mas)
{
	int num;

	cout << "������� ����� �������: ";
	cin >> num;

	cout << "�����: " << obj_mas[num - 1].width * obj_mas[num - 1].legth * obj_mas[num - 1].max_depth << "km^3\n";
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

	cout << "������� ����� ������� ������� ��� ���������: ";
	cin >> num1;
	cout << "������� ����� ������� �������: ";
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