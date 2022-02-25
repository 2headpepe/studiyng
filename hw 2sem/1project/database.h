#pragma once
#include<iostream>

struct Flat
{
public:
    int id, countRooms, floor, area, price;
    char address[64], date[10];
};

struct DataBase
{
    int count;
    Flat* data;
};

std::ostream& operator<<(std::ostream& out, const Flat& num);
std::istream& operator>>(std::istream& in, const Flat& num);

int addFlat(DataBase& db);
void printDB(const DataBase& db);
//void saveDB(const DataBase& db);
