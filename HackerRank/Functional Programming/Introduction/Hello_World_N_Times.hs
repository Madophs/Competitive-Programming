import System.IO
import System.IO.Unsafe

fun :: Int -> String
fun n =
    if n>0
        then
            "Hello World\n" ++ fun (n-1)
        else
            ""
main = do
         n <- readLn :: IO Int
         --let array = take n (repeat "Hello World")
         putStr (fun n)