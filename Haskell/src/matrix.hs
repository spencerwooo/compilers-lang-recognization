import Data.List
import Text.Printf
import System.CPUTime

matrixMultiply :: Num a => [[a]] -> [[a]] -> [[a]]
matrixMultiply a b = [ [ sum $ zipWith (*) ar bc | bc <- (transpose b) ] | ar <- a ]

matrixGenerator n =
  let rowIndex n k = [x | x <- [1,2..n]]
  in [rowIndex n k | k <- [1,2..n]]

vectorGenerator n =
  let rowIndex n k = [x | x <- [1,2..n]]
  in [rowIndex n k | let k = 1]

main = do
  let matrix = matrixGenerator 1000
  let vector = vectorGenerator 1000

  startTime <- getCPUTime
  let product = matrixMultiply vector matrix
  print product
  endTime <- getCPUTime

  let totalTime = (fromIntegral(endTime - startTime)) / (10 ^ 9)
  printf "Total time: %f ms\n" (totalTime :: Double)
