mdsFilter :: Int -> [Int] -> [Int]
mdsFilter n arr = [val | val<-arr, val<n]

main = do
    n <- readLn :: IO Int
    inputData <- getContents
    let
        numbers = map read (lines inputData) :: [Int]
    putStrLn . unlines $ map show $ mdsFilter n numbers