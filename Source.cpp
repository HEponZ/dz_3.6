#include "Header.h"
#include "Reservoir.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Reservoir* obj_mas{ nullptr };
	int choise;

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
	};

	cout << "1 - ÄÎÁÀÂÈÒÜ âîäîåì\n2 - ÓÄÀËÈÒÜ âîäîåì\n3 - íàéòè ÎÁÚÅÌ ÂÑÅÕ âîäîåìîâ\n4 -  íàéòè ÏËÎÙÀÄÜ ÂÑÅÕ âîäîåìîâ\n5 - ñðàâíèòü ÒÈÏÛ âîäîåìîâ\n6 - ñðàâíèòü ÏËÎÙÀÄÜ âîäîåìîâ ÎÄÍÎÃÎ ÒÈÏÀ\n7 - êîïèðîâàòü\n8 - ÑÎÕÐÀÍÈÒÜ â ôàéë\n0 - ÂÛÕÎÄ\n";
	do
	{
		cin >> choise;

		switch(choise)
		{
		case ADD:
			break;
		}
	} while (choise != 0);

	return 0;
}