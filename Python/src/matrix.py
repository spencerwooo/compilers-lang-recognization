#! python3

import numpy


def main():
    matrix = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    vector = numpy.array([1, 2, 3])
    product1 = numpy.dot(vector, matrix)
    product2 = numpy.dot(matrix, vector)
    print(product1, product2)


if __name__ == "__main__":
    main()
