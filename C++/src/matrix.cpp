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
      cout << "[ERR] Cannot multiply!" << endl;
      return NULL;
    }
  }


}

int main(int argc, char const *argv[])
{
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix2 = {{1, 2, 3}};

  printMatrix(matrix1);
  return 0;
}
