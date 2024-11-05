#include "Header.h"

Reservoir* add(Reservoir* obj_mas, int& size)
{
	Reservoir* new_mas = new Reservoir[++size];
	char buffer[100]{ "\0" };
	int num_buf = 0;

	cin.ignore();
	cout << "Введите название водоема: ";
	gets_s(buffer);
	new_mas[size - 1].set_name(buffer);

	cout << "Введите ширину: ";
	cin >> num_buf;
	new_mas[size - 1].set_width(num_buf);
	cout << "Введите длину: ";
	cin >> num_buf;
	new_mas[size - 1].set_legth(num_buf);
	cout << "Введите максимальную глибину: ";
	cin >> num_buf;
	new_mas[size - 1].set_max_depth(num_buf);

	cin.ignore();
	cout << "Введите тип водоема: ";
	gets_s(buffer);
	new_mas[size - 1].set_type(buffer);

	for (int i = 0; i < size - 1; i++)
	{
		new_mas[i].set_name(obj_mas[i].get_name());
		new_mas[i].set_width(obj_mas[i].get_width());
		new_mas[i].set_legth(obj_mas[i].get_legth());
		new_mas[i].set_max_depth(obj_mas[i].get_max_depth());
		new_mas[i].set_type(obj_mas[i].get_type());
	}


	delete[] obj_mas;

	return new_mas;
}

void print(Reservoir* obj_mas, int size)
{
	for (int i{ 0 }; i < size; i++)
	{
		printf("\n%s\n%d\n%d\n%d\n%s\n", obj_mas[i].get_name(), obj_mas[i].get_width(), obj_mas[i].get_legth(), obj_mas[i].get_max_depth(), obj_mas[i].get_type());
	}
}

Reservoir* delete_res(Reservoir* obj_mas, int& size)
{
	Reservoir* del_mas = new Reservoir[--size];
	int num, j = 0;

	cout << "Введите номер удаляемого водоема: ";
	cin >> num;
	--num;

	for (int i{ 0 }; i < size + 1; i++)
	{
		if (i != num)
		{
			del_mas[j].set_name(obj_mas[i].get_name());
			del_mas[j].set_width(obj_mas[i].get_width());
			del_mas[j].set_legth(obj_mas[i].get_legth());
			del_mas[j].set_max_depth(obj_mas[i].get_max_depth());
			del_mas[j].set_type(obj_mas[i].get_type());
			j++;
		}
	}

	delete[] obj_mas;

	return del_mas;
}

int save(Reservoir* obj_mas, int size)
{
	FILE* file;
	int count = 0;

	if (fopen_s(&file, "Reservoir.txt", "w") != NULL)
	{
		cout << "Не удалось открыть файл\n";
		return 404;
	}

	for (int i = 0; i < size; i++)
	{
		fprintf_s(file, "%s\n%d\n%d\n%d\n%s\n", obj_mas[i].get_name(), obj_mas[i].get_width(), obj_mas[i].get_legth(), obj_mas[i].get_max_depth(), obj_mas[i].get_type());
	}

	if (fclose(file) != NULL)
	{
		cout << "Не удалось закрыть файл\n";
		return 404;
	}
}