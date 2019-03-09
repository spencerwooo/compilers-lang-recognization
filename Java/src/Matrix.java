import java.util.concurrent.ThreadLocalRandom;

public class Matrix {

  public static void printMatrix(int matrix[][]) {
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        System.out.print(" " + matrix[i][j]);
      }
      System.out.print("\n");
    }
  }

  public static int[][] multiplyMatrix(int matrix1[][], int matrix2[][]) {
    for (int i = 0; i < matrix1.length; i++) {
      if (matrix1[i].length != matrix2.length) {
        System.out.println("[ERR] Cannot multiply!");
        return null;
      }
    }

    int[][] resultMatrix = new int[matrix1.length][matrix2[0].length];

    for (int i = 0; i < resultMatrix.length; i++) {
      for (int j = 0; j < resultMatrix[i].length; j++) {
        for (int k = 0; k < matrix1[0].length; k++) {
          resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
      }
    }

    return resultMatrix;
  }

  public static void main(String[] args) {
    int matrixSize = 10000;
    int[][] matrix = new int[matrixSize][matrixSize];
    int[][] vector = new int[1][matrixSize];

    for (int i = 0; i < matrixSize; i++) {
      for (int j = 0; j < matrixSize; j++) {
        matrix[i][j] = ThreadLocalRandom.current().nextInt(1, 10);
      }
    }

    for (int i = 0; i < matrixSize; i++) {
      vector[0][i] = ThreadLocalRandom.current().nextInt(1, 10);
    }

    long startTime = System.currentTimeMillis();

    try {
      int result[][] = multiplyMatrix(vector, matrix);
      // printMatrix(result);
      System.out.println(result[0][0]);
    } catch (Exception e) {
      System.out.println(e);
    }

    long endTime = System.currentTimeMillis();
    long totalTime = endTime - startTime;
    System.out.println("Total Time: " + totalTime + "ms");
  }
}
