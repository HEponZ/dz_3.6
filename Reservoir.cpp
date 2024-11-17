#include "Reservoir.h"

void Reservoir::volume(int num)
{
	//������� ������ �����*������*������
	cout << "�����: " << this[num - 1].width * this[num - 1].legth * this[num - 1].max_depth << "km^3\n";
}

int Reservoir::square(int num)
{
	int  S;//�������� ����������

	//������������� ��������� ������� �����*������
	S = this[num - 1].width * this[num - 1].legth;

	//������� �� ������
	return S;
}

int Reservoir::compare_type(int num1, int num2)
{
	if (strcmp(this[num1 - 1].type, this[num2 - 1].type) == 0) //��������� ��� ������� 
	{                                              // ���������� ��� ������� � � ������������
		return 1;                                  // ���������� �������� 1 - ����� 
	}                                              //��� 0 - �� �����
	return 0;
}

int Reservoir::compare_squre_one_type()
{
	int num1, num2; //�������� ����������

	cout << "������� ����� ������� ������� ��� ���������: ";
	cin >> num1;
	cout << "������� ����� ������� �������: "; //���� ����������
	cin >> num2;

	if (this->compare_type(num1, num2) == 1) //�������� ����� �� ����
	{
		if (square(num1) == square(num2)) // �������� ������ �� �������
		{
			return 2;//���������� 2 ���� � ���� � ������� �����
		}
		return 1;//���������� 1 ���� ���� ����� � ������� ���
	}
	return 0;//���������� 0 ���� �� ���� �� ������� �� �����
}

void Reservoir::copy()
{
	int num, num2; //�������� ����������

	cout << "������� ����� ����������� �������: ";
	cin >> num; // ���� ����������
	cout << "������� ����� ������� ���� ������ �����������: ";
	cin >> num2;

	strcpy_s(this[num2 - 1].name, strlen(this[num - 1].name) + 1, this[num - 1].name); //����������� ������
	this[num2 - 1].width = this[num - 1].width;
	this[num2 - 1].legth = this[num - 1].legth; //����������� ����� ����� ������ �������
	this[num2 - 1].max_depth = this[num - 1].max_depth;
	strcpy_s(this[num2 - 1].type, strlen(this[num - 1].type) + 1, this[num - 1].type);//����������� ������

	cout << "����������� ��������� �������\n";
}

int Reservoir::count{ 0 };//������������� �������

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