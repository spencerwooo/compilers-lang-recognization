#! python3

import numpy
import time


def main():
    matrix = numpy.random.randint(10, size=(10000, 10000))
    vector = numpy.random.randint(10, size=(1, 10000))

    startTime = time.time()
    product = numpy.dot(vector, matrix)
    print(product)
    endTime = time.time()

    totalTime = format(endTime - startTime, '.5f')
    print('Total time: ', totalTime)


if __name__ == "__main__":
    main()
