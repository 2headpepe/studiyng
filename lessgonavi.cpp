#include<fstream>
#include <iostream>

double** createMatrix(size_t rows, size_t cols)
{
    double** matrix = new double* [rows];
    for (size_t idx = 0; idx < rows; ++idx)
        matrix[idx] = new double[cols];
    return matrix;
}
double** inputFileMatrix(char const* filename, size_t rows, size_t cols)
{
    std::ifstream in(filename);
    if (!in.is_open())
        throw std::runtime_error("Failed to open matrix file");
    //in >> rows >> cols;
    double** matrix = createMatrix(rows, cols);
    for (size_t r = 0; r < rows; ++r)
        for (size_t c = 0; c < cols; ++c)
            in >> matrix[r][c]; 
    in.close();
    return matrix;
}
void printMatrix(double** matrix, size_t rows, size_t cols)
{
    for (size_t r = 0; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
            std::cout << matrix[r][c] << '\t';
        std::cout << '\n';
    }
    std::cout << '\n';
}
double** rotate(double** matrix, size_t rows, size_t cols)
{
  double** new_ma = createMatrix(cols,rows);
  for (size_t r = 0; r < rows; ++r)
  {
    for (size_t c = 0; c < cols; ++c)
      new_ma[cols-1-c][r]=matrix[r][c];
    std::cout << '\n';
  }
  std::cout << '\n';
  return new_ma;
}
double** snake(size_t rows, size_t cols)
{
  double** matrix = createMatrix(rows,cols);
  int c=0;
  for(int i=0;i<rows;++i)
  {
    if (i%2==0) 
      for(int j=0;j<cols;++j)
      {
        matrix[i][j]=++c;
      }
    else
      for(int j=cols-1;j>=0;--j)
      {
        matrix[i][j]=++c;
      }
  }
  return matrix;
}
void print_file(double** matrix,size_t rows,size_t cols)
{
  std::ofstream navi("navi.txt");
  for(int i =0;i<rows;++i)
  {
    for(int j=0;j<cols;++j)
    {
      navi.width(4);
      navi<<matrix[i][j]<<" ";
    }
    navi<<std::endl;
  }   
}
int main()
{
  print_file(snake(6,10),6,10);
}
