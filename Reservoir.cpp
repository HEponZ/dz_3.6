#include "Reservoir.h"

void Reservoir::volume(Reservoir* obj_mas)
{
	int num;

	cout << "Âגוהטעו םמלונ גמהמולא: ";
	cin >> num;

	cout << "Îבתול: " << obj_mas[num - 1].width * obj_mas[num - 1].legth * obj_mas[num - 1].max_depth << "km^3\n";
}

void Reservoir::square(Reservoir* obj_mas)
{
	int num;

	cout << "Âגוהטעו םמלונ גמהמולא: ";
	cin >> num;

	cout << "Ïכמשאהü: " << obj_mas[num - 1].width * obj_mas[num - 1].legth << "km^2\n";
}