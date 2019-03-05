#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
  int matrixRow = int(matrix.size());
  int matrixCol = int(matrix[0].size());

  for (int i = 0; i < matrixRow; i++)
  {
    for (int j = 0; j < matrixCol; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> multiplyMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
  for (int i = 0; i < int(matrix1.size()); i++)
  {
    if (int(matrix1[i].size()) != int(matrix2.size()))
    {
      throw invalid_argument("[ERR] Cannot multiply!");
    }
  }

  vector<vector<int>> resultMatrix(int(matrix1.size()), vector<int>(int(matrix2[0].size()), 0));

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
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2 = {{1, 2, 3}};

  printMatrix(matrix1);
  printMatrix(matrix2);

  try
  {
    vector<vector<int>> result = multiplyMatrix(matrix2, matrix1);
    printMatrix(result);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
