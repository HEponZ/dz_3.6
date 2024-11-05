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

	cout << "1 - ƒќЅј¬»“№ водоем\n2 - ”ƒјЋ»“№ водоем\n3 - найти ќЅЏ≈ћ водоема\n4 - найти ѕЋќўјƒ№ водоема\n5 - сравнить “»ѕџ водоемов\n6 - сравнить ѕЋќўјƒ№ водоемов ќƒЌќ√ќ “»ѕј\n7 - копировать\n8 - —ќ’–јЌ»“№ в файл\n9 - ¬џ¬ќƒ\n0 - ¬џ’ќƒ\n";
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
			cout << "¬ведите номер водоема: ";
			cin >> num;

			cout << "ѕлощадь: " << obj_mas->square(obj_mas, num) << "km^2\n";
			break;
		case COMPARE_TYPE:
			cout << "¬ведите номер первого водоема дл€ сравнени€: ";
			cin >> num;
			cout << "¬ведите номер второго водоема: ";
			cin >> num2;

			if (obj_mas->compare_type(obj_mas, num, num2) == 1)
			{
				cout << "“ипы водоемов равны\n";
			}
			else
			{
				cout << "“ипы водоемов не равны\n";
			}
			break;
		case COMPARE_SQUARE_ONE_TYPE:
			num = obj_mas->compare_squre_one_type(obj_mas);
			if (num == 2)
			{
				cout << "ѕлощади водоемов с одинаковыми типами равны\n";
			}
			else if (num == 1)
			{
				cout << "ѕлощажи водоемов с одинаковыми типами не равны\n";
			}
			else
			{
				cout << "“ипы сравниваемых водоемов не равны\n";
			}

		}
	} while (choise != 0);

	return 0;
}