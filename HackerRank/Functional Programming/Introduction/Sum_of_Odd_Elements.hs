sumOdds :: [Int] -> Int
sumOdds arr = sum [x | x<-arr, odd x]

main =
    do
        inputData <- getContents
        let input = map read $ lines inputData :: [Int]
        print $sumOdds input