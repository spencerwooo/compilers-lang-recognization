#! python3

import numpy

def main():
  matrix = numpy.array([[1,2,3],[4,5,6],[7,8,9]])
  vector = numpy.array([1,2,3])
  product = numpy.dot(vector, matrix)
  print(product)

if __name__ == "__main__":
  main()
