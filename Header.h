#pragma once
#include "Reservoir.h"

Reservoir* add(Reservoir* obj_mas, int& size);
void print(Reservoir* obj_mas, int size);  //создание прототипов функций
Reservoir* delete_res(Reservoir* obj_mas, int& size);
int save(Reservoir* obj_mas, int size);