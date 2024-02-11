
apellidos :: [(String, String, Int)] -> [String]
apellidos [] = []
apellidos ((a,b,c):xs) = b:apellidos xs

mayoresQue10 :: [Int] -> [Int]
mayoresQue10 [] = []
mayoresQue10 (x:xs) | x> 10 = x:mayoresQue10 xs
                    | x<=10 = mayoresQue10 xs

suma1 :: [Int] -> Int
suma1 [] = 0
suma1 (x:xs) = x+suma1 xs

repartir :: [String] -> [String] -> [(String,String)]
repartir [] []         = []
repartir (x:xs) []     = []
repartir [] (y:ys)     = []
repartir (x:xs) (y:ys) = (x,y):repartir xs ys

length1 :: [a] -> Int
length1 [] = 0
length1 (x:xs) = 1+length1 xs

indice1 :: [a] -> Int -> a
--indice1 [] n = _
indice1 (x:xs) n | n> 0 = indice1 xs (n-1)
                 | n==0 = x

take1 :: Int -> [a] -> [a]
take1 n [] = []
take1 n (x:xs) | n> 0 = x:take1 (n-1) xs
               | n==0 = []

drop1 :: Int -> [a] -> [a]
drop1 n [] = []
drop1 n (x:xs) | n> 0 = drop1 (n-1) xs
               | n==0 = x:drop1 n xs

--concatenar1 :: [a] -> [a] -> [a]
--concatenar1 [] (ys) = ys
--concatenar1 (x:xs) (ys) = x:(xs  /= [] = x:concatenar1 xs ys

concatenar1 :: [a] -> [a] -> [a] 
concatenar1 [] ys = ys
concatenar1 (x: xs) ys = x: (concatenar1 xs ys)

sumaPares :: [(Int,Int)] -> Int
sumaPares [] = 0
sumaPares ((x,y):xs) = (x+y) + sumaPares xs

concat1 :: [[a]] -> [a]
concat1 [] = []
concat1 (x:xs) = x++concat1 xs

rev1 :: [a] -> [a]
rev1 [] = []
rev1 (x:xs) = rev1 xs ++[x]

pegaren3 :: [(String,String)] -> [(String,String,String)]
pegaren3 [] = []
pegaren3 ((a,b):xs) = (a,b,(a++b)):pegaren3 xs

listasIguales :: Eq a => [a] -> [a] -> Bool
listasIguales [] [] = True
listasIguales [] _ = False
listasIguales _ [] = False
listasIguales (x:xs) (y:ys) = x==y && listasIguales xs ys

mejorNota :: [(String,Int,Int,Int)] -> [(String,Int)]
mejorNota [] = []
mejorNota ((a,b,c,d):xs) = (a,(max b (max c d))):mejorNota xs

incPrim :: [(Int, Int)] -> [(Int,Int)]
incPrim [] = []
incPrim ((x,y):xs) = ((x+1),y):incPrim xs

expandir :: String-> String
expandir [] = []
expandir (x:[]) = [x]++expandir []
expandir (x:xs) = ([x]++" ")++expandir xs

esCumple :: (Int,Int,Int) -> (Int,Int,Int) -> Bool
esCumple (dia1,mes1,anno1) (dia2,mes2,anno2) = dia1==dia2 && mes1==mes2 && anno1<anno2

igualQue :: Eq a => [a] -> a -> Int
igualQue [] n = 0
igualQue (x:xs) n | n==x = 1+igualQue xs n
                  | n/=x = igualQue xs n

sinCeros :: [Int] -> Bool
sinCeros xs = (igualQue xs 0) == 0

hacerA :: String -> String
hacerA [] = []
hacerA (x:xs) | (x=='e' || x=='i' || x=='o' || x=='u') = 'a':hacerA xs
              | otherwise = x:hacerA xs

topes :: [[a]] -> [a]
topes [] = []
topes ([]:xss) = topes xss
topes ((x:xs):xss) = x:topes xss

