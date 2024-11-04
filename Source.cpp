#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };
	int choise, size = 0;

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

	cout << "1 - �������� ������\n2 - ������� ������\n3 - ����� ����� ���� ��������\n4 -  ����� ������� ���� ��������\n5 - �������� ���� ��������\n6 - �������� ������� �������� ������ ����\n7 - ����������\n8 - ��������� � ����\n9 - �����\n0 - �����\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			obj_mas = add(obj_mas, size);
			break;
		case PRINT:
			print(obj_mas, size);
			break;
		}
	} while (choise != 0);

	return 0;
}