#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };
	int choise, size = 0, num, num2;

	enum MENU {
		EXIT = 0,
		ADD,
		DELETE,
		VOLUME,
		SQUARE,
		COMPARE_TYPE,
		COMPARE_SQUARE_ONE_TYPE,
		COPY,
		SAVE,
		PRINT
	};

	cout << "1 - �������� ������\n2 - ������� ������\n3 - ����� ����� �������\n4 - ����� ������� �������\n5 - �������� ���� ��������\n6 - �������� ������� �������� ������ ����\n7 - ����������\n8 - ��������� � ����\n9 - �����\n0 - �����\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			obj_mas = add(obj_mas, size);
			break;
		case DELETE:
			obj_mas = delete_res(obj_mas, size);
			break;
		case PRINT:
			print(obj_mas, size);
			break;
		case VOLUME:
			obj_mas->volume(obj_mas);
			break;
		case SQUARE:
			cout << "������� ����� �������: ";
			cin >> num;

			cout << "�������: " << obj_mas->square(obj_mas, num) << "km^2\n";
			break;
		case COMPARE_TYPE:
			cout << "������� ����� ������� ������� ��� ���������: ";
			cin >> num;
			cout << "������� ����� ������� �������: ";
			cin >> num2;

			if (obj_mas->compare_type(obj_mas, num, num2) == 1)
			{
				cout << "���� �������� �����\n";
			}
			else
			{
				cout << "���� �������� �� �����\n";
			}
			break;
		case COMPARE_SQUARE_ONE_TYPE:
			num = obj_mas->compare_squre_one_type(obj_mas);
			if (num == 2)
			{
				cout << "������� �������� � ����������� ������ �����\n";
			}
			else if (num == 1)
			{
				cout << "������� �������� � ����������� ������ �� �����\n";
			}
			else
			{
				cout << "���� ������������ �������� �� �����\n";
			}

		}
	} while (choise != 0);

	return 0;
}