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
	std::cout << "7. Sort by price." << std::endl;
	std::cout << "8. Find ID." << std::endl;
	std::cout << "9. Sort by price(with room)." << std::endl;

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
		case 1: openDB(db,"out.db"); break;
		case 2: printDB(db); break;
		case 3: saveDB(db,"out.db"); break;
		case 4: exportDB(db, "out.txt"); break;
		case 5: addFlat(db); break;
		case 6: delDB(db); break;
		case 7: sortDB(db); break;
		case 8: findByID(db); break;
		case 9: sortDBwroom(db); break;
		}
	} while (action != 0);

	if (db.data)
		delete[] db.data;
}
