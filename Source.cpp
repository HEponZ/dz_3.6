#include "Header.h"
#include "Reservoir.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };
	int choise;

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
	};

	cout << "1 - �������� ������\n2 - ������� ������\n3 - ����� ����� ���� ��������\n4 -  ����� ������� ���� ��������\n5 - �������� ���� ��������\n6 - �������� ������� �������� ������ ����\n7 - ����������\n8 - ��������� � ����\n0 - �����\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			break;
		}
	} while (choise != 0);

	return 0;
}