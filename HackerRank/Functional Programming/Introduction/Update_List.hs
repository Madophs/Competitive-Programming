updateList :: [Int] -> [Int]
updateList l = [ abs x | x<-l]

main = 
    do
        inputData <- getContents
        let input = map read $ lines inputData :: [Int]
        putStrLn . unlines $ map show $updateList input