#include "Reservoir.h"

void Reservoir::volume(int num)
{
	//подсчет объема длина*ширина*высота
	cout << "Объем: " << this[num - 1].width * this[num - 1].legth * this[num - 1].max_depth << "km^3\n";
}

int Reservoir::square(int num)
{
	int  S;//создание переменной

	//инициализация значением площади длина*ширина
	S = this[num - 1].width * this[num - 1].legth;

	//возврат из метода
	return S;
}

int Reservoir::compare_type(int num1, int num2)
{
	if (strcmp(this[num1 - 1].type, this[num2 - 1].type) == 0) //сравнение дву строчек 
	{                                              // содержащих тип водоема и в соответствии
		return 1;                                  // результата возврата 1 - равны 
	}                                              //или 0 - не равны
	return 0;
}

int Reservoir::compare_squre_one_type()
{
	int num1, num2; //создание переменных

	cout << "Введите номер первого водоема для сравнения: ";
	cin >> num1;
	cout << "Введите номер второго водоема: "; //ввод переменных
	cin >> num2;

	if (this->compare_type(num1, num2) == 1) //проверка равны ли типы
	{
		if (square(num1) == square(num2)) // проверка раввны ли площади
		{
			return 2;//возвращает 2 если и типы и площади равны
		}
		return 1;//возвращает 1 если типы равны а площади нет
	}
	return 0;//возвращает 0 если ни типы ни площади не равны
}

void Reservoir::copy()
{
	int num, num2; //создание переменных

	cout << "Введите номер копируемого водоема: ";
	cin >> num; // ввод переменных
	cout << "Введите номер водоема куда хотите скопировать: ";
	cin >> num2;

	strcpy_s(this[num2 - 1].name, strlen(this[num - 1].name) + 1, this[num - 1].name); //копирование строки
	this[num2 - 1].width = this[num - 1].width;
	this[num2 - 1].legth = this[num - 1].legth; //копирование чисел длина ширина глубина
	this[num2 - 1].max_depth = this[num - 1].max_depth;
	strcpy_s(this[num2 - 1].type, strlen(this[num - 1].type) + 1, this[num - 1].type);//копирование строки

	cout << "Копирование произошло успешно\n";
}

int Reservoir::count{ 0 };//инициализация статика

const char* Reservoir::get_name() const
{
	return name;
}

int Reservoir::get_width() const
{
	return width;
}

int Reservoir::get_legth() const
{
	return legth;
}

int Reservoir::get_max_depth() const
{
	return max_depth;
}

const char* Reservoir::get_type() const
{
	return type;
}

void Reservoir::set_name(const char* name_S)
{
	if (name)
	{
		delete[] name;
	}
	name = new char[strlen(name_S) + 1];
	strcpy_s(name, strlen(name_S) + 1, name_S);
}

void Reservoir::set_width(const int width_S)
{
	width = width_S;
}

void Reservoir::set_legth(const int legth_S)
{
	legth = legth_S;
}

void Reservoir::set_max_depth(const int max_depth_S)
{
	max_depth = max_depth_S;
}

void Reservoir::set_type(const char* type_S)
{
	if (type)
	{
		delete[] type;
	}
	type = new char[strlen(type_S) + 1];
	strcpy_s(type, strlen(type_S) + 1, type_S);
}

Reservoir::~Reservoir()
{
	count--;
	delete[] name;
	delete[] type;
}