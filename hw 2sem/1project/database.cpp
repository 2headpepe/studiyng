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
void sortDBwroom(DataBase& db)
{
	std::cout << "Count rooms: ";
	int countRoom,count=0;
	std::cin >> countRoom;


	for (int i = 0; i < db.count; ++i)
	{
		if (db.data[i].countRooms == countRoom)
		{
			++count;
		}
	}
	Flat* tmp = new Flat[count];
	int j = 0;
	for (int i = 0; i < db.count; ++i)
	{
		if (db.data[i].countRooms == countRoom)
		{
			tmp[j]=db.data[i];
			++j;
		}
	}
	DataBase sortDB = {count,tmp};

	mySort(sortDB.data, sortDB.count, sortByPrice);
	printDB(sortDB);
	delete[] tmp;
}
void sortDB(DataBase& db)
{
	
	mySort(db.data, db.count, sortByPrice);
}
int find(const DataBase& db,int id)
{
	for (int i = 0; i < db.count; ++i)
		if (db.data[i].id == id) return i;
	return -1;
}
void findByID(const DataBase& db)
{
	int tmpId;
	std::cout << "ID: ";
	std::cin >> tmpId;

	int currentFlat = find(db, tmpId);

	std::cout << "ID" << '\t' << "Date" << '\t' << '\t' << "Price" << '\t' << "CountRooms" << '\t' << "Floor" 
		<< '\t' << "Area" << '\t' << "Address"<<std::endl;


	for (int i = 0; i < db.count; ++i)
	{
		if ((db.data[i].floor == db.data[currentFlat].floor) && (db.data[i].countRooms == db.data[currentFlat].countRooms) &&
			(db.data[i].area <= 1.2 * db.data[currentFlat].area) && (db.data[i].area >= 0.8 * db.data[currentFlat].area))
			std::cout << db.data[i] << std::endl;
	}
}
