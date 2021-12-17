#ifndef Matrix_h
#define Matrix_h
#include <cstddef>
// Function that allocates memory for matrix
// Params:
//   rows -- number of matrix rows
//   cols -- number of matrix cols
// Return value:
//   pointer to matrix
// WARNING! Don't forget to delete memory
double** createMatrix(size_t rows, size_t cols);

void deleteMatrix(double** matrix, size_t rows, size_t cols);
void inputMatrix(double** matrix, size_t rows, size_t cols);
double** inputFileMatrix(char const* filename, size_t& rows, size_t& cols);
void printMatrix(double** matrix, size_t rows, size_t cols);
void zeros(double** matrix, size_t rows, size_t cols);
void ones(double** matrix, size_t rows, size_t cols);
void fill(double** matrix, size_t rows, size_t cols, double val = 0);
double** linspace(size_t length);

double** transpose(double** matrix, size_t rows, size_t cols);

//1 2 3 4   -> 12 11 10 9
//5 6 7 8   -> 8 7 6 5
//9 10 11 12-> 4 3 2 1
void rotate180(double** matrix, size_t rows, size_t cols);

double& findMinimum(double** matrix, size_t rows, size_t cols);

// find max element of the min elements in the rows
double& minmaxMatrix(double** matrix, size_t rows, size_t cols);

// swap rows with indices k1 and k2
// and swap cols with indices k1 and k2
void mixMatrix( double** matrix,
                size_t rows,
                size_t cols,
                size_t k1,
                size_t k2);

void randMatrix(double** matrix,
                size_t rows,
                size_t cols,
                double minval = 0,
                double maxval = 1);
double** multMatrix(double lambda, double** M, size_t rows, size_t cols);

double** plusMatrix(double** A, double** B, size_t rows, size_t cols);

double** minusMatrix(double** A, double** B, size_t rows, size_t cols);

double** multMatrix(double** A, double** B, double** C, size_t rowsA, size_t colsA);

double& maximumMatrix(double** matrix, size_t rows, size_t columns);

double det(double** M, size_t size);

double** inv(double** M, size_t size);
#endif /* Matrix_h */
