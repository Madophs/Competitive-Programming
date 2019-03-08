justOdds :: [Int] -> Int -> [Int]
justOdds arr pos =
    if pos <= length arr
        then (arr!!(pos-1)):(justOdds arr (pos+2))
        else []
main =
    do
        inputData <- getContents
        let
            input = map read $ lines inputData :: [Int]
        putStrLn . unlines $ map show $justOdds input 2