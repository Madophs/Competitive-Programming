len :: [Int] -> Int
len [] = 0
len (x:lst) = 1+(len lst)
