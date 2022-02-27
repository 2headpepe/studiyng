#include "database.h"
#include<fstream>
#include<iomanip>

int addFlat(DataBase& db)
{
	Flat* tmp = new Flat[db.count + 1];
	for (int i = 0; i < db.count; ++i)
	{
		tmp[i] = db.data[i];
	}
	if(db.data)
		delete[] db.data;
	db.data = tmp;

	std::cin >> db.data[db.count];

	db.data[db.count].id = db.count;

	
	/*tm Tm;
	time_t t = std::time(nullptr);
	errno_t err = localtime_s(&Tm, &t);*/
	
	++db.count;

	return db.count;
}
void printDB(const DataBase& db)
{
	std::cout << "ID" << '\t' << "Date"<< '\t' << '\t' << "Price" << '\t' << "CountRooms" << '\t' << "Floor" << '\t' << "Area" << '\t' << "Address"
																										<< std::endl;
	for (int i = 0; i < db.count; ++i)
	{
		std::cout << db.data[i] << std::endl;
	}
}
void exportDB(const DataBase& db, const char* filename)
{
	std::ofstream outFile(filename,std::ios_base::binary);
	if (!outFile.is_open())
	{
		std::cout << "Can't open :(";
		return;
	}

	outFile << "ID" << '\t' << "Date" << '\t' << '\t' << "Price" << '\t' << "CountRooms" << '\t' << "Floor" << '\t' << "Area" << '\t' << "Address"
		<< std::endl;
	for (int i = 0; i < db.count; ++i)
	{
		outFile << db.data[i];
		outFile << std::endl;
	}

	outFile.close();

}
void saveDB(const DataBase& db, const char* filename)
{
	std::ofstream outFile(filename, std::ios_base::binary);
	if (!outFile.is_open())
	{
		std::cout << "Can't open :(";
		return;
	}
	outFile.write((const char*)&db.count, sizeof(int));
	outFile.write((const char*)db.data, db.count * sizeof(Flat));

	outFile.close();
}
void openDB(DataBase& db, const char* filename)
{
	std::ifstream in(filename,std::ios_base::binary);
	if (!in.is_open())
	{
		std::cout << "Can't open :(";
		return;
	}

	int count;
	in.read((char*)&count, sizeof(int));
	
	if (db.data) delete[] db.data;
	db.data = new Flat[count];
	db.count = count;
	in.read((char*)db.data, sizeof(Flat) * db.count);
	in.close();
	
}
void delDB(DataBase& db)
{
	int tmp;
	std::cout << "ID to delete: ";
	std::cin >> tmp;
	if (tmp < 0) return;

	for (int i = tmp + 1; i < db.count; ++i)
		db.data[i - 1] = db.data[i];
	--db.count;
}
void sortDB(DataBase& db)
{
	std::cout << "Count rooms: ";
	int count;
	std::cin >> count;
	
	mySort(db.data,db.count, sortByCountRooms,count);
	printDB(db);
}





