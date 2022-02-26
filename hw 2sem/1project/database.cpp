#include "database.h"
#include<fstream>
#include<iomanip>
std::ostream& operator<<(std::ostream& out, const Flat& num)
{
	out << num.id << '\t' << std::setfill('0') << std::setw(2) << num.day << '.' << std::setfill('0')<< std::setw(2)
		<< num.month << '.' << std::setfill('0')<< std::setw(2) << num.year << '\t' << num.price << '\t' << num.countRooms
															<< '\t' << '\t' << num.floor << '\t' << num.area << '\t';
	int i = 0;
	while(num.address[i]!='\a')
	{
		out << num.address[i];
		++i;
	}
	out << " ";
	return out;
}
std::istream& operator>>(std::istream& in, Flat& num)
{
	for (int i = 0; i < 64; ++i) num.address[i] = '\a';
	std::cout << "Date. Year: "; in >> num.year;
	std::cout << "Date. No. of month: "; in >> num.month;
	std::cout << "Date. Day: "; in >> num.day;
	std::cout << "Price: ";
	in >> num.price;
	in.ignore();
	std::cout << "Rooms: ";
	in >> num.countRooms;
	std::cout << "Floor: ";
	in >> num.floor;
	std::cout << "Area: ";
	in >> num.area;
	std::cout << "Address: ";
	in.ignore();
	in.getline(num.address,64);
	
	//num.id = db.count;
	return in;
}
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
//void delDB(DataBase& db)
//{
//	int tmp;
//	std::cout << "ID to delete: ";
//	std::cin >> tmp;
//
//
//	for (int i = 0; i < db.count; ++i)
//		if (db.data[i].id == tmp) delete	 db.data[i]
//}



