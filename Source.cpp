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

	cout << "1 - ДОБАВИТЬ водоем\n2 - УДАЛИТЬ водоем\n3 - найти ОБЪЕМ водоема\n4 - найти ПЛОЩАДЬ водоема\n5 - сравнить ТИПЫ водоемов\n6 - сравнить ПЛОЩАДЬ водоемов ОДНОГО ТИПА\n7 - копировать\n8 - СОХРАНИТЬ в файл\n9 - ВЫВОД\n0 - ВЫХОД\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			obj_mas = add(obj_mas, size);
			cout << "Добавлено\n";
			break;
		case DELETE:
			obj_mas = delete_res(obj_mas, size);
			cout << "Удалено\n";
			break;
		case PRINT:
			print(obj_mas, size);
			break;
		case VOLUME:
			obj_mas->volume(obj_mas);
			break;
		case SQUARE:
			cout << "Введите номер водоема: ";
			cin >> num;
			cout << "Площадь: " << obj_mas->square(obj_mas, num) << "km^2\n";
			break;
		case COMPARE_TYPE:
			cout << "Введите номер первого водоема для сравнения: ";
			cin >> num;
			cout << "Введите номер второго водоема: ";
			cin >> num2;

			if (obj_mas->compare_type(obj_mas, num, num2) == 1)
			{
				cout << "Типы водоемов равны\n";
			}
			else
			{
				cout << "Типы водоемов не равны\n";
			}
			break;
		case COMPARE_SQUARE_ONE_TYPE:
			num = obj_mas->compare_squre_one_type(obj_mas);
			if (num == 2)
			{
				cout << "Площади водоемов с одинаковыми типами равны\n";
			}
			else if (num == 1)
			{
				cout << "Площажи водоемов с одинаковыми типами не равны\n";
			}
			else
			{
				cout << "Типы сравниваемых водоемов не равны\n";
			}
			break;
		case COPY:
			obj_mas->copy(obj_mas);
			break;
		case SAVE:
			save(obj_mas, size);
			cout << "Сохранено\n";
			break;
		}
	} while (choise != 0);

	return 0;
}