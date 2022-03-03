#include<iostream>
#include<iomanip>
#include "flat.h"


std::ostream& operator<<(std::ostream& out, const Flat& num)
{
	out << num.id << '\t' << std::setfill('0') << std::setw(2) << num.day << '.' << std::setfill('0') << std::setw(2)
		<< num.month << '.' << std::setfill('0') << std::setw(2) << num.year << '\t' << num.price << '\t' << num.countRooms
		<< '\t' << '\t' << num.floor << '\t' << num.area << '\t';
	int i = 0;
	while (num.address[i] != '\a')
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
	in.getline(num.address, 64);

	//num.id = db.count;
	return in;
}
bool sortByPrice(const Flat& first, const Flat& second)
{
	return first.price > second.price;
}
