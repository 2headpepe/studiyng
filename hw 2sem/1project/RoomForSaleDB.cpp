#include <iostream>
#include "database.h"
int menu()
{
	for (int i = 0; i < 40; ++i)
		std::cout << "*";
	std::cout << std::endl;
	std::cout << "1. Open database" << std::endl;
	std::cout << "2. Print database" << std::endl;
	std::cout << "3. Save database" << std::endl;
	std::cout << "4. Export database" << std::endl;
	std::cout << "5. Add flat" << std::endl;
	std::cout << "6. Delete flat" << std::endl;
	std::cout << "0. Exit" << std::endl;

	int tmp;
	std::cin >> tmp;
	return tmp;

}
int main()
{
	DataBase db = { 0, nullptr };

	int action;
	do {
		action = menu();
		switch (action) {
		case 1: break;
		case 2: printDB(db); break;
		case 3: //saveDB(db);
			break;
		case 4: break;
		case 5: addFlat(db); break;
		case 6: break;
		}
	} while (action != 0);

	if (db.data)
		delete[] db.data;
}
