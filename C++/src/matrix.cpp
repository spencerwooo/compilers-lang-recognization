#include <iostream>
#include <vector>
#include <ctime>

void printMatrix(std::vector<std::vector<int>> matrix)
{
  int matrixRow = int(matrix.size());
  int matrixCol = int(matrix[0].size());

  for (int i = 0; i < matrixRow; i++)
  {
    for (int j = 0; j < matrixCol; j++)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<int>> multiplyMatrix(std::vector<std::vector<int>> matrix1, std::vector<std::vector<int>> matrix2)
{
  for (int i = 0; i < int(matrix1.size()); i++)
  {
    if (int(matrix1[i].size()) != int(matrix2.size()))
    {
      throw std::invalid_argument("[ERR] Cannot multiply!");
    }
  }

  std::vector<std::vector<int>> resultMatrix(int(matrix1.size()), std::vector<int>(int(matrix2[0].size()), 0));

  for (int i = 0; i < int(resultMatrix.size()); i++)
  {
    for (int j = 0; j < int(resultMatrix[i].size()); j++)
    {
      for (int k = 0; k < int(matrix1[0].size()); k++)
      {
        resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return resultMatrix;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  std::vector<std::vector<int>> matrix1;
  std::vector<std::vector<int>> matrix2;

  for (int i = 0; i < 10000; i++) {
    matrix1.push_back(std::vector<int>());
    for (int j = 0; j < 10000; j++) {
      matrix1[i].push_back(rand() % 10);
    }
  }

  for (int i = 0; i < 1; i++) {
    matrix2.push_back(std::vector<int>());
    for (int j = 0; j < 10000; j++) {
      matrix2[i].push_back(rand() % 10);
    }
  }

  double startTime = clock();

  try
  {
    std::vector<std::vector<int>> result = multiplyMatrix(matrix2, matrix1);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  double endTime = clock();
  double totalTime = endTime - startTime;
  std::cout << "Total time: " << totalTime << std::endl;

  return 0;
}
