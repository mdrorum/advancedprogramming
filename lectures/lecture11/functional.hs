
list = [1, 2, 3, 4, 5]

main :: IO()
main = putStrLn $ show $ map (+10) list
