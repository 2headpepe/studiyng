#include "database.h"

std::ostream& operator<<(std::ostream& out, const Flat& num)
{
	out << num.id << ", " << num.price << ", " << num.countRooms << ", " << num.floor << ", " << num.area << ", ";
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
	in>>num.address;
	
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

	++db.count;

	return db.count;
}
void printDB(const DataBase& db)
{
	for (int i = 0; i < db.count; ++i)
	{
		std::cout << db.data[i] << std::endl;
	}
}
