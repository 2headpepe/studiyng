#include <iostream>
#include "Matrix.h"
#include <ctime>

int main()
{
    srand(time(nullptr));

    size_t const Rows = 2;
    size_t const Cols = 3;
    double** matrix = createMatrix(Rows, Cols);

    std::cout << "rand matrix 1:\n";
    randMatrix(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "rand matrix 2:\n";
    randMatrix(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    inputMatrix(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);
    double& minmax = minmaxMatrix(matrix, Rows, Cols);
    std::cout << "minmax: " << minmax << "\n";
    minmax = 42;
    std::cout << "changed minmax to " << minmax << ":\n";
    printMatrix(matrix, Rows, Cols);

    std::cout << "mix rows and cols with indices 0 and 2:\n";
    mixMatrix(matrix, Rows, Cols, 0, 2);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with zeros:\n";
    zeros(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with ones:\n";
    ones(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with -1.5:\n";
    fill(matrix, Rows, Cols, -1.5);
    printMatrix(matrix, Rows, Cols);

    std::cout << "fill matrix from 0 to " << Rows * Cols - 1 << ":\n";
    for (size_t r = 0; r < Rows; ++r)
        for (size_t c = 0; c < Cols; ++c)
            matrix[r][c] = r * Cols + c;
    printMatrix(matrix, Rows, Cols);

    std::cout << "rotate 180:\n";
    rotate180(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    double& minimum = findMinimum(matrix, Rows, Cols);
    std::cout << "minimum is " << minimum << "\n";
    minimum = 42;
    std::cout << "changed minimum to 42:\n";
    //findMinimum(matrix, Rows, Cols) = 42;
    printMatrix(matrix, Rows, Cols);

    std::cout << "row vector:\n";
    double** vec = linspace(Cols);
    printMatrix(vec, 1, Cols);

    std::cout << "transposed matrix:\n";
    double** transposed = transpose(matrix, Rows, Cols);
    printMatrix(transposed, Cols, Rows);

    std::cout << "multyMatrix:\n";
    multMatrix(2, matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "plusMatrix: \n";
    size_t const Rows_2 = 3;
    size_t const Cols_2= 3;
    double** M2 = createMatrix(Rows_2, Cols_2);
    inputMatrix(M2, Rows_2, Cols_2);
    printMatrix(M2, Rows_2, Cols_2);
    plusMatrix(matrix, M2, Rows, Cols_2);
    printMatrix(matrix, Rows, Cols);

    std::cout << "minusMatrix: \n";
    inputMatrix(M2, Rows_2, Cols_2);
    printMatrix(M2, Rows_2, Cols_2);
    minusMatrix(matrix, M2, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "multMatrix: \n";
    printMatrix(matrix, Rows, Cols);
    printMatrix(M2, Rows_2, Cols_2);
    double** M3 = createMatrix(Rows, Cols_2);
    multMatrix(matrix, M2, M3, Rows, Cols);
    printMatrix(M3, Rows, Cols_2);
    std::cout << "Finding Max: \n";
    double maximum  = maximumMatrix(matrix, Rows, Cols);
    std::cout << "Maximum is: " << maximum << "\n";



    deleteMatrix(matrix, Rows, Cols);
    deleteMatrix(M2, Rows_2, Cols_2);
    deleteMatrix(M3, Rows, Cols_2);
    deleteMatrix(vec, 1, Cols);
    deleteMatrix(transposed, Rows, Cols);
    return 0;
}
