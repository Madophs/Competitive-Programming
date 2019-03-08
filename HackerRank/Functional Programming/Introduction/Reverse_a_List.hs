mdsReverse :: [Int] -> [Int]
mdsReverse [] = []
mdsReverse (x:xs) = (mdsReverse xs) ++ (x:[])

main =
    do
        inputData <- getContents
        let arr = map read $ lines inputData :: [Int]
        putStrLn . unlines $map show $mdsReverse arr
