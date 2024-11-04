#include "Header.h"

Reservoir* add(Reservoir* obj_mas, int& size)
{
	Reservoir* new_mas = new Reservoir[++size];
	char buffer[100]{ "\0" };
	int num_buf = 0;

	cin.ignore();
	cout << "¬ведите название водоема: ";
	gets_s(buffer);
	new_mas[size - 1].set_name(buffer);

	cout << "¬ведите ширину: ";
	cin >> num_buf;
	new_mas[size - 1].set_width(num_buf);
	cout << "¬ведите длину: ";
	cin >> num_buf;
	new_mas[size - 1].set_legth(num_buf);
	cout << "¬ведите максимальную глибину: ";
	cin >> num_buf;
	new_mas[size - 1].set_max_depth(num_buf);

	cin.ignore();
	cout << "¬ведите тип водоема: ";
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
		printf("%s\n%d\n%d\n%d\n%s\n", obj_mas[i].get_name(), obj_mas[i].get_width(), obj_mas[i].get_legth(), obj_mas[i].get_max_depth(), obj_mas[i].get_type());
	}
}