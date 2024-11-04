#pragma once
#include <iostream>
using namespace std;

class Reservoir
{
private:
	char* name;
	int width; //ширина
	int legth; //глубина
	int max_depth; //максимальная глубина
	char* type; // тип водоема
public:
	Reservoir() : Reservoir(nullptr, 0, 0, 0, nullptr) {};
	Reservoir(char* name_S, int width_S, int legth_S, int max_depth_S, char* type_S)
		: name{}, width{ width_S }, legth{ legth_S }, max_depth{ max_depth_S },
		type{}
	{
		if(name_S)
		{
			name = new char[strlen(name_S) + 1];
			strcpy_s(name, strlen(name_S) + 1, name_S);
		}
		if(type_S)
		{
			type = new char[strlen(type_S) + 1];
			strcpy_s(type, strlen(type_S) + 1, type_S);
		}
	}

	const char* get_name() const
	{
		return name;
	}
	int get_width() const
	{
		return width;
	}
	int get_legth() const
	{
		return legth;
	}
	int get_max_depth() const
	{
		return max_depth;
	}
	const char* get_type() const
	{
		return type;
	}

	void set_name(const char* name_S)
	{
		if (name)
		{
			delete[] name;
		}
		name = new char[strlen(name_S) + 1];
		strcpy_s(name, strlen(name_S) + 1, name_S);
	}
	void set_width(const int width_S)
	{
		width = width_S;
	}
	void set_legth(const int legth_S)
	{
		legth = legth_S;
	}
	void set_max_depth(const int max_depth_S)
	{
		max_depth = max_depth_S;
	}
	void set_type(const char* type_S)
	{
		if (type)
		{
			delete[] type;
		}
		type = new char[strlen(type_S) + 1];
		strcpy_s(type, strlen(type_S) + 1, type_S);
	}

	void volume(Reservoir* obj_mas);
	void square(Reservoir* obj_mas);

	~Reservoir()
	{
		delete[] name;
		delete[] type;
	}
};