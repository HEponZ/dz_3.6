#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class Reservoir
{
private:
	char* name;
	int width; //ширина
	int legth; //глубина
	int max_depth; //максимальная глубина
	char* type; // тип водоема
	static int count; //создание статика
public:
	Reservoir() : Reservoir(nullptr, 0, 0, 0, nullptr) {}; // делегированный конструктор по умолчанию
	Reservoir(char* name_S, int width_S, int legth_S, int max_depth_S, char* type_S)
		: name{}, width{ width_S }, legth{ legth_S }, max_depth{ max_depth_S },
		type{}
	{
		count++;//увеличение статика
		if(name_S)
		{
			name = new char[strlen(name_S) + 1]; // выделение динам памяти
			strcpy_s(name, strlen(name_S) + 1, name_S); //копирование
		}
		if(type_S)
		{
			type = new char[strlen(type_S) + 1]; // выделение динам памяти
			strcpy_s(type, strlen(type_S) + 1, type_S);//копирование
		}
	} // конструктор с параметрами
	Reservoir(const Reservoir& res) : name{ new char[strlen(res.name) + 1] }, width{ res.width }, 
		legth{ res.legth }, max_depth{ res.max_depth }, type{ new char[strlen(res.type) + 1] }
	{
		count++;
		strcpy_s(name, strlen(res.name), res.name);
		strcpy_s(type, strlen(res.type), res.type);
	} //конструктор копирования
	Reservoir(int max_depth) : Reservoir(nullptr, 0, 0, max_depth, nullptr){};

	//аксессоры
	const char* get_name() const;
	int get_width() const;
	int get_legth() const;
	int get_max_depth() const;
	const char* get_type() const;
	static int get_count()
	{
		return count;
	}

	//модификаторы
	void set_name(const char* name_S);
	void set_width(const int width_S);
	void set_legth(const int legth_S);
	void set_max_depth(const int max_depth_S);
	void set_type(const char* type_S);

	void volume(int num);
	int square(int num);
	int compare_type(int num1, int num2); //прототипы методов
	int compare_squre_one_type();
	void copy();

	~Reservoir();
};