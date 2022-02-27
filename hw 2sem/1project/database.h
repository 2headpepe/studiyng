#pragma once
#include "flat.h"

struct DataBase
{
    int count;
    Flat* data;
};

int addFlat(DataBase& db);
void printDB(const DataBase& db);
void exportDB(const DataBase& db,const char* filename); 
void saveDB(const DataBase& db, const char* filename);
void openDB(DataBase& db, const char* filename);
void delDB(DataBase& db);
void sortDB(const DataBase& db);



template <typename T>
void mySort(T* M, int n, bool (*comparator)(const T&, const T&),int count)
{
    for (int i = 0; i < n-1; ++i)
    {
        if (M[i].countRooms == count)
        {
            int tmp = i;
            for (int j = tmp + 1; j < n; ++j)
            {
                if (comparator(M[j], M[i])&&(M[j].countRooms==count)) tmp = j;
            }
            if (i < tmp) std::swap(M[tmp], M[i]);
        }
    }
}
