#include "Header.h"

Reservoir* add(Reservoir* obj_mas, int& size)
{
	Reservoir* new_mas = new Reservoir[++size]; //создание нового массива обьектов и переменных
	char buffer[100]{ "\0" }; //буферов
	int num_buf = 0;

	cin.ignore();
	cout << "Введите название водоема: ";
	gets_s(buffer); //ввод названия для нового водоема
	new_mas[size - 1].set_name(buffer);

	cout << "Введите ширину: ";
	cin >> num_buf;//ввод ширины для нового водоема
	new_mas[size - 1].set_width(num_buf);
	cout << "Введите длину: ";
	cin >> num_buf;//ввод длины для нового водоема
	new_mas[size - 1].set_legth(num_buf);
	cout << "Введите максимальную глибину: ";
	cin >> num_buf;//ввод макс глубины для нового водоема
	new_mas[size - 1].set_max_depth(num_buf);

	cin.ignore();
	cout << "Введите тип водоема: ";
	gets_s(buffer);//ввод типа для нового водоема
	new_mas[size - 1].set_type(buffer);

	for (int i = 0; i < size - 1; i++)
	{
		new_mas[i].set_name(obj_mas[i].get_name());
		new_mas[i].set_width(obj_mas[i].get_width());
		new_mas[i].set_legth(obj_mas[i].get_legth()); //перенос данных из старого массива 
		new_mas[i].set_max_depth(obj_mas[i].get_max_depth());//обьектов в новый
		new_mas[i].set_type(obj_mas[i].get_type());
	}


	delete[] obj_mas; //удаление старого массива обьектов

	return new_mas; //возврат указателя на новый массив
}

void print(Reservoir* obj_mas, int size)
{
	for (int i{ 0 }; i < size; i++) //вывод всех водоемов
	{
		printf("\n%s\n%d\n%d\n%d\n%s\n", obj_mas[i].get_name(), obj_mas[i].get_width(), obj_mas[i].get_legth(), obj_mas[i].get_max_depth(), obj_mas[i].get_type());
	}
}

Reservoir* delete_res(Reservoir* obj_mas, int& size)
{
	Reservoir* del_mas = new Reservoir[--size]; //создание нового массива обьектов
	int num, j = 0;//создание переменных

	cout << "Введите номер удаляемого водоема: ";
	cin >> num;//ввод номера для удаления
	--num;

	for (int i{ 0 }; i < size + 1; i++)
	{
		if (i != num)//проверка на номер данного обьекта не равен номеру выбранного
		{
			del_mas[j].set_name(obj_mas[i].get_name());
			del_mas[j].set_width(obj_mas[i].get_width());
			del_mas[j].set_legth(obj_mas[i].get_legth()); //перенос данных из старого массива
			del_mas[j].set_max_depth(obj_mas[i].get_max_depth());//в новый
			del_mas[j].set_type(obj_mas[i].get_type());
			j++;
		}
	}

	delete[] obj_mas;//удаление старого массива

	return del_mas;//возврат указателя на новый массив
}

int save(Reservoir* obj_mas, int size)
{
	FILE* file; //создание файла
	int count = 0;

	if (fopen_s(&file, "Reservoir.txt", "w") != NULL)//открытие и проверка на то
	{                                                 //что файл открылся
		cout << "Не удалось открыть файл\n";
		return 404;
	}

	for (int i = 0; i < size; i++) //запись в файл данных через цикл
	{
		fprintf_s(file, "%s\n%d\n%d\n%d\n%s\n", obj_mas[i].get_name(), obj_mas[i].get_width(), obj_mas[i].get_legth(), obj_mas[i].get_max_depth(), obj_mas[i].get_type());
	}

	if (fclose(file) != NULL)//закрытие файла и проверка что он закрылся
	{
		cout << "Не удалось закрыть файл\n";
		return 404;
	}
}