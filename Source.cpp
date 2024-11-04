#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };
	int choise, size = 0;

	enum MENU {
		EXIT = 0,
		ADD,
		DELETE,
		VOLUME,
		SQUARE,
		COMPARE_TYPE,
		COMPARE_SQUARE_ONE_TYPE,
		COPY,
		SAVE,
		PRINT
	};

	cout << "1 - ÄÎÁÀÂÈÒÜ âîäîåì\n2 - ÓÄÀËÈÒÜ âîäîåì\n3 - íàéòè ÎÁÚÅÌ ÂÑÅÕ âîäîåìîâ\n4 -  íàéòè ÏËÎÙÀÄÜ ÂÑÅÕ âîäîåìîâ\n5 - ñðàâíèòü ÒÈÏÛ âîäîåìîâ\n6 - ñðàâíèòü ÏËÎÙÀÄÜ âîäîåìîâ ÎÄÍÎÃÎ ÒÈÏÀ\n7 - êîïèðîâàòü\n8 - ÑÎÕÐÀÍÈÒÜ â ôàéë\n9 - ÂÛÂÎÄ\n0 - ÂÛÕÎÄ\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			obj_mas = add(obj_mas, size);
			break;
		case PRINT:
			print(obj_mas, size);
			break;
		}
	} while (choise != 0);

	return 0;
}