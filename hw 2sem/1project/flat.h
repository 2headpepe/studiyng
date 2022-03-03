#pragma once
#include<iostream>

struct Flat
{
public:
    int id, countRooms, floor, area, price, day, month, year;
    char address[64];
};

std::ostream& operator<<(std::ostream& out, const Flat& num);
std::istream& operator>>(std::istream& in,  Flat& num);

bool sortByPrice(const Flat& first, const Flat& second);
