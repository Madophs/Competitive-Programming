createArray :: Int -> [Int]
createArray n = take n (cycle [2,5,3,2])

main = do
    n <- readLn :: IO Int
    print $ createArray n