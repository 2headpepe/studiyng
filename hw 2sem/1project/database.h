#pragma once
#include<iostream>

struct Flat
{
public:
    int id, countRooms, floor, area, price, day,month,year;
    char address[64];
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
void exportDB(const DataBase& db,const char* filename);
void saveDB(const DataBase& db, const char* filename);
void openDB(DataBase& db, const char* filename);
//void delDB(DataBase& db);
