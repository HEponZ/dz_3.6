#include "Reservoir.h"

void Reservoir::volume(Reservoir* obj_mas)
{
	int num; // создание переманной

	cout << "Введите номер водоема: ";
	cin >> num; // ввод

	//подсчет объема длина*ширина*высота
	cout << "Объем: " << obj_mas[num - 1].width * obj_mas[num - 1].legth * obj_mas[num - 1].max_depth << "km^3\n";
}

int Reservoir::square(Reservoir* obj_mas, int num)
{
	int  S;//создание переменной

	//инициализация значением площади длина*ширина
	S = obj_mas[num - 1].width * obj_mas[num - 1].legth;

	//возврат из метода
	return S;
}

int Reservoir::compare_type(Reservoir* obj_mas, int num1, int num2)
{
	if (strcmp(obj_mas[num1 - 1].type, obj_mas[num2 - 1].type) == 0) //сравнение дву строчек 
	{                                              // содержащих тип водоема и в соответствии
		return 1;                                  // результата возврата 1 - равны 
	}                                              //или 0 - не равны
	return 0;
}

int Reservoir::compare_squre_one_type(Reservoir* obj_mas)
{
	int num1, num2; //создание переменных

	cout << "Введите номер первого водоема для сравнения: ";
	cin >> num1;
	cout << "Введите номер второго водоема: "; //ввод переменных
	cin >> num2;

	if (compare_type(obj_mas, num1, num2) == 1) //проверка равны ли типы
	{
		if (square(obj_mas, num1) == square(obj_mas, num2)) // проверка раввны ли площади
		{
			return 2;//возвращает 2 если и типы и площади равны
		}
		return 1;//возвращает 1 если типы равны а площади нет
	}
	return 0;//возвращает 0 если ни типы ни площади не равны
}

void Reservoir::copy(Reservoir* obj_mas)
{
	int num, num2; //создание переменных

	cout << "Введите номер копируемого водоема: ";
	cin >> num; // ввод переменных
	cout << "Введите номер водоема куда хотите скопировать: ";
	cin >> num2;

	strcpy_s(obj_mas[num2 - 1].name, strlen(obj_mas[num - 1].name) + 1, obj_mas[num - 1].name); //копирование строки
	obj_mas[num2 - 1].width = obj_mas[num - 1].width;
	obj_mas[num2 - 1].legth = obj_mas[num - 1].legth; //копирование чисел длина ширина глубина
	obj_mas[num2 - 1].max_depth = obj_mas[num - 1].max_depth;
	strcpy_s(obj_mas[num2 - 1].type, strlen(obj_mas[num - 1].type) + 1, obj_mas[num - 1].type);//копирование строки

	cout << "Копирование произошло успешно\n";
}

int Reservoir::count{ 0 };//инициализация статика