#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };  //создание всех переменных и массива обьектов
	int choise, size = 0, num, num2;

	enum MENU { //енам для меню
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
			obj_mas = add(obj_mas, size); //вызов функции добваления и приравнивание указателя на 
			cout << "Добавлено\n"; //старый массив к новому
			break;
		case DELETE:
			obj_mas = delete_res(obj_mas, size); // вызов функции удаленияи приравнивание указателя на 
			cout << "Удалено\n";//старый массив к новому
			break;
		case PRINT:
			print(obj_mas, size);// вызов функции вывода
			cout << "Всего " << obj_mas->get_count() << " водоемов создано\n";
			break;
		case VOLUME:
			cout << "Введите номер водоема: ";
			cin >> num;
			obj_mas->volume(num); // вызов функции подсчета обьема
			break;
		case SQUARE:
			cout << "Введите номер водоема: ";
			cin >> num;
			cout << "Площадь: " << obj_mas->square(num) << "km^2\n"; // вызов функции подсчета площади
			break;
		case COMPARE_TYPE:
			cout << "Введите номер первого водоема для сравнения: ";
			cin >> num;
			cout << "Введите номер второго водоема: ";
			cin >> num2;

			if (obj_mas->compare_type(num, num2) == 1) // вызов функции сравнения типов
			{
				cout << "Типы водоемов равны\n";
			}
			else
			{
				cout << "Типы водоемов не равны\n";
			}
			break;
		case COMPARE_SQUARE_ONE_TYPE:
			num = obj_mas->compare_squre_one_type(); // вызов функции сравнения площади если
			if (num == 2)                                  // одинаковый тип
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
			obj_mas->copy(); // вызов функции копирования
			break;
		case SAVE:
			save(obj_mas, size);   // вызов функции сохранения в файл
			cout << "Сохранено\n";
			break;
		}
	} while (choise != 0);

	return 0;
}