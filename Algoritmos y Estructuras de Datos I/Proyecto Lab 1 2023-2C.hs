{-1. Programa las siguientes funciones:
    a) esCero :: Int -> Bool, que verifica si un entero es igual a 0.-}
esCero :: Int -> Bool
esCero x = x==0

{- Pruebas con esCero:
    ghci> esCero 1
    False
    ghci> esCero 0
    True
    ghci> esCero (-1)
    False
-}
    --b) esPositivo :: Int -> Bool, que verifica si un entero es estrictamente mayor a 0.
esPositivo :: Int -> Bool
esPositivo x = x>0

{- Pruebas con esPositivo:
    ghci> esPositivo 1
    True
    ghci> esPositivo 0 
    False
    ghci> esPositivo (-1)
    False
-}
    --c) esVocal :: Char -> Bool, que verifica si un caracter es una vocal en minuscula.
esVocal :: Char -> Bool
esVocal x = x=='a' || x=='e' || x=='i' || x=='o' || x=='u'

{- Pruebas con esVocal:
    ghci> esVocal 'a'
    True
    ghci> esVocal 'b'
    False
-}
    --d) valorAbsoluto :: Int -> Int, que devuelve el valor absoluto de un entero ingresado.
valorAbsoluto :: Int -> Int
valorAbsoluto x | x>=0 = x
                | x< 0 = (-x)

{- Pruebas con valorAbsoluto:
    ghci> valorAbsoluto 2
    2
    ghci> valorAbsoluto 0
    0
    ghci> valorAbsoluto (-2)
    2
-}
{-2. Programa las siguientes funciones usando recursion o composicion:
    a) paratodo :: [Bool] -> Bool, que verifica que todos los elementos de una lista sean True.-}
paratodo :: [Bool] -> Bool
paratodo [] = True
paratodo (x:xs) = (x==True) && paratodo xs

{- Pruebas con paratodo:
    ghci> paratodo [True,True]
    True
    ghci> paratodo [True,False]
    False
    ghci> paratodo []          
    True
-}
    --b) sumatoria :: [Int] -> Int, que calcula la suma de todos los elementos de una lista de enteros.
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x+sumatoria xs

{- Pruebas con sumatoria:
    ghci> sumatoria [1,2,3,4,5]
    15
    ghci> sumatoria [1,1,1,1]
    4
    ghci> sumatoria [0,1,0,0]
    1
-}
    --c) productoria :: [Int] -> Int, que calcula el producto de todos los elementos de la lista de enteros.
productoria :: [Int] -> Int
productoria [] = 1
productoria (x:xs) = x*productoria xs

{- Pruebas con productoria:
    ghci> productoria [1,2,3,4,5]
    120
    ghci> productoria [1,1,1,1]  
    1
    ghci> productoria [0,1,0,0]
    0
-}
    --d) factorial :: Int -> Int, que toma un numero n y calcula n!.
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

{- Pruebas con factorial:
    ghci> factorial 0
    1
    ghci> factorial 2
    2
    ghci> factorial 3
    6
    ghci> factorial 4
    24
-}
   --e) Utiliza la funcion sumatoria para definir, promedio :: [Int] -> Int, que toma una lista de numeros no vacia y calcula el valor promedio (truncado, usando division entera).
promedio :: [Int] -> Int
promedio xs = div (sumatoria xs) (length xs)

{- Pruebas con promedio:
    ghci> promedio [0]
    0
    ghci> promedio [1,2,3,4,5]
    3
    ghci> promedio [2,4,6,8,10]
    6
-}
--3. Programa la funcion pertenece :: Int -> [Int] -> Bool, que verifica si un numero se encuentra en una lista.
pertenece :: Int -> [Int] -> Bool
pertenece x [] = False
pertenece x (y:ys) = x==y || pertenece x ys

{- Pruebas con promedio:
    ghci> pertenece 1 [0,1,2,3,4,5]
    True
    ghci> pertenece 6 [0,1,2,3,4,5]
    False
-}
{-4. Programa las siguientes funciones que implementan los cuantificadores generales. Nota que el segundo parametro de cada funcion, es otra funcion!
    a) paratodo’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado t :: a -> Bool, determina si todos los elementos de xs satisfacen el predicado t.-}
paratodo' :: [a] -> (a -> Bool) -> Bool
paratodo' [] y = True
paratodo' (x:xs) y =  y(x) && paratodo' xs y

{- Pruebas con paratodo':
    ghci> paratodo' [1,2,3] even
    False
    ghci> paratodo' [2,4] even
    True
    ghci> paratodo' "hola" esVocal
    False
    ghci> paratodo' "aeiou" esVocal
    True
-}
    --b) existe’ :: [a] -> (a -> Bool) -> Bool, dada una lista xs de tipo [a] y un predicado t :: a -> Bool, determina si algun elemento de xs satisface el predicado t.
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] y = False
existe' (x:xs) y =  y(x) || existe' xs y

{- Pruebas con existe':
    ghci> existe' [1,2,3] even
    True
    ghci> existe' [1,3] even  
    False
    ghci> existe' "hola" esVocal   
    True
    ghci> existe' "bcdfg" esVocal
    False
-}
    --c) sumatoria’ :: [a] -> (a -> Int) -> Int, dada una lista xs de tipo [a] y una funcion t :: a -> Int (toma elementos de tipo a y devuelve enteros), calcula la suma de los valores que resultan de la aplicacion de t a los elementos de xs.
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] y = 0
sumatoria' (x:xs) y =  y(x) + sumatoria' xs y

{- Pruebas con sumatoria':
    ghci> sumatoria' [1,2,3,4] factorial
    33
    ghci> sumatoria' [1,(-2),3,(-4)] valorAbsoluto
    10
    ghci> sumatoria' ["hola"] length        
    4
    ghci> sumatoria' ["hola","adios"] length
    9
    ghci> sumatoria' [] length      
    0
-}
    --d) productoria’ :: [a] -> (a -> Int) -> Int, dada una lista de xs de tipo [a] y una funcion t :: a -> Int, calcula el producto de los valores que resultan de la aplicacion de t a los elementos de xs.
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] y = 1
productoria' (x:xs) y =  y(x) * productoria' xs y

{- Pruebas con productoria':
    ghci> productoria' [1,2,3,4] factorial
    288
    ghci> productoria' [1,(-2),3,(-4)] valorAbsoluto
    24
    ghci> productoria' ["hola"] length              
    4
    ghci> productoria' ["hola","adios"] length
    20
    ghci> productoria' [] length              
    1
-}
--5. Definı nuevamente la funcion paratodo, pero esta vez usando la funcion paratodo’ (sin recursion ni analisis por casos!).
paratodo'' :: [Bool] -> Bool
paratodo'' xs = paratodo' xs (==True)

{- Pruebas con paratodo'':              --mismos ejemplos y resultados obtenidos que con la función "paratodo" del punto 2a
    ghci> paratodo'' [True,False]
    False
    ghci> paratodo'' [True,True] 
    True
    ghci> paratodo'' []         
    True
-}
{-6. Utilizando las funciones del ejercicio 4, programa las siguientes funciones por composicion, sin usar recursion ni analisis por casos.
    --a) todosPares :: [Int] -> Bool verifica que todos los numeros de una lista sean pares.-}
todosPares :: [Int] -> Bool
todosPares xs = paratodo' xs even
--todosPares xs = paratodo2 xs (\x->(mod x 2 == 0))        --usando una expresión lambda, si no se permite usar la función "even" del prelude.

{- Pruebas con todosPares:
    ghci> todosPares [1,2,3]
    False
    ghci> todosPares [2,4]  
    True
    ghci> todosPares []   
    True
-}
    --b) hayMultiplo :: Int -> [Int] -> Bool verifica si existe algun numero dentro del segundo parametro que sea multiplo del primer parametro.
hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo y xs = existe' xs (\x->(mod x y == 0))          --usando una expresión lambda para no tener que crear una función auxiliar permanente.

{- Pruebas con hayMultiplo:
    ghci> hayMultiplo 1 [2,3,6,9,12]
    True
    ghci> hayMultiplo 2 [2,3,6,9,12]
    True
    ghci> hayMultiplo 5 [2,3,6,9,12]
    False
    ghci> hayMultiplo 6 [2,3,6,9,12]
    True
    ghci> hayMultiplo 7 [2,3,6,9,12]
    False
-}
    --c) sumaCuadrados :: Int -> Int, dado un numero no negativo n, calcula la suma de los primeros n cuadrados, es decir P i : 0 ≤ i < n : i 2.
    --Ayuda: En Haskell se puede escribir la lista que contiene el rango de numeros entre n y m como [n..m].
sumaCuadrados :: Int -> Int
sumaCuadrados n = sumatoria' [0..n] (^2)

{- Pruebas con sumaCuadrados:
    ghci> sumaCuadrados 2
    5
    ghci> sumaCuadrados 3
    14
    ghci> sumaCuadrados 4
    30
    ghci> sumaCuadrados 5
    55
-}
    --d) Programar la fucion existeDivisor::Int-> [Int] -> Bool, que dado un entero n y una lista ls , devuelve True si, y solo si, existe algun elemento en ls que divida a n.
existeDivisor::Int-> [Int] -> Bool
existeDivisor n ls = existe' ls (\x->(mod n x == 0))        --usando una expresión lambda para no tener que crear una función auxiliar permanente.

{- Pruebas con existeDivisor:
    ghci> existeDivisor 2 [3,4,5]
    False
    ghci> existeDivisor 2 [2,3,4,5]
    True
    ghci> existeDivisor 10 [2,3,4,5]
    True
    ghci> existeDivisor 10 [3,4]
    False
-}
    {-e) Utilizando la funcion del apartado anterior, definı la funcion esPrimo:: Int -> Bool, que dado un entero n, devuelve True si y solo si n es primo.
    Ayuda: En Haskell se puede escribir la lista que contiene el rango de n ́umeros entre n y m como [n..m].-}
esPrimo:: Int -> Bool
--esPrimo n   | n<=1 = False                                    --Ni 1, ni 0 ni los negativos cuentan como primos.
--            | n> 1 = not(existeDivisor n [2..(n-1)])
--esPrimo n = not(existeDivisor n [2..(n-1)]) && (n>1)            --Igual que el de arriba, pero sin usar guardas
esPrimo n = not(existeDivisor n [2..(div n 2)]) && (n>1)          --reemplazo el "n-1" por un "div n 2", ahora solo busca divisores hasta su mitad entera (casi la mitad de los cálculos eran innecesarios)

{- Pruebas con esPrimo:
    ghci> esPrimo 6
    False
    ghci> esPrimo 7
    True
    ghci> esPrimo 8
    False
    ghci> esPrimo 21
    False
    ghci> esPrimo 23
    True
-}
    --f ) ¿Se te ocurre como redefinir factorial (ej. 2d) para evitar usar recursion?
factorial' :: Int -> Int
factorial' n = productoria' [1..n] id                   --La función "id" devuelve el mismo valor en cada ciclo para poder hacer la multiplicación final.
--factorial' n = productoria [1..n]                     --Es una forma más corta, pero usando la función del punto 2c (no requiere una función extra).

{- Pruebas con factorial':          --mismos resultados que con factorial del ej. 2d.
    ghci> factorial' 0   
    1
    ghci> factorial' 1
    1
    ghci> factorial' 2
    2
    ghci> factorial' 3
    6
    ghci> factorial' 4
    24
-}
    --g) Programar la funcion multiplicaPrimos :: [Int] -> Int que calcula el producto de todos los numeros primos de una lista.
multiplicaPrimos :: [Int] -> Int
multiplicaPrimos xs = productoria' (filter esPrimo xs) id   --La función "filter" del prelude de ghci crea una lista sólo con los elementos cuyo valor sea True para la condición dada.

{- Pruebas con multiplicaPrimos:
    ghci> multiplicaPrimos [0,1,2,3,4,5]        --ignora correctamente el 0, 1 y 4
    30
    ghci> multiplicaPrimos [0,1,2,3,4]          --ignora correctamente el 0, 1 y 4
    6
    ghci> multiplicaPrimos [0,2,3,5,6,7]        --ignora correctamente el 0 6
    210
-}
    {-h) Programar la funcion esFib :: Int -> Bool, que dado un entero n, devuelve True si y solo si n esta en la sucesion de Fibonacci.
    Ayuda: Realizar una funcion auxiliar fib :: Int -> Int que dado un n devuelva el n-esimo elemento de la sucesion.-}
fib :: Int -> Int
fib n   | n==0  = 0
        | n==1  = 1
        | n> 1  = (fib (n-1)) + (fib (n-2))
esFib :: Int -> Bool
esFib n = existe' (map fib [0..n+1]) (==n)

{- Pruebas con esFib:       --detecta correctamente 1,2,3,5,8 y 13 como pertenecientes a la sucesión de Fibonacci
    ghci> esFib 0
    True
    ghci> esFib 1
    True
    ghci> esFib 2
    True
    ghci> esFib 3
    True
    ghci> esFib 4
    False
    ghci> esFib 5
    True
    ghci> esFib 6
    False
    ghci> esFib 7
    False
    ghci> esFib 8
    True
    ghci> esFib 9
    False
    ghci> esFib 10
    False
    ghci> esFib 11
    False
    ghci> esFib 12
    False
    ghci> esFib 13
    True
-}
    --i) Utilizando la funcion del apartado anterior, definı la funcion todosFib :: [Int] -> Bool que dada una lista xs de enteros, devuelva si todos los elementos de la lista pertenecen (o no) a la sucesion de Fibonacci.
todosFib :: [Int] -> Bool
todosFib xs = paratodo' xs esFib

{- Pruebas con todosFib:
    ghci> todosFib []
    True
    ghci> todosFib [0,1,2,3]
    True
    ghci> todosFib [0,1,2,3,4]
    False
-}
{-7. Indaga en Hoogle sobre las funciones map y filter. Tambien podes consultar su tipo en ghci con el comando :t.
    a) ¿Que hacen estas funciones?
        Map es una función de lista incluida en "prelude" (módulo estandar de ghci).
            Su tipo es "(a -> b) -> [a] -> [b]", el 1° argumento es una función que se pueda aplicar sobre los elementos del 2° argumento, que debe ser una lista (el tipo de "a" debe ser igual al tipo de los elementos dentro de "[a]").
            La función devuelve una lista ("[b]") con los elementos resultantes ("b") de aplicar la función del 1° argumento a cada elemento de la lista del 2° argumento (es recursiva).
        Filter también es una función de lista incluida en "prelude" (módulo estandar de ghci).
            Su tipo es "(a -> Bool) -> [a] -> [a]", el 1° argumento es una función que se pueda aplicar sobre los elementos del 2° argumento, que debe ser una lista (el tipo de "a" debe ser igual al tipo de los elementos dentro de "[a]").
            A diferencia de "map", la función debe devolver siempre un booleano según el valor de cada elemento "a" de la lista del 2° argumento.
            Filter devuelve entonces una nueva lista con todos los elementos de la lista original (2° argumento) que satisfacen la función del 1° argumento (devuelvan "True").

    b) ¿A que equivale la expresion map succ [1, -4, 6, 2, -8], donde succ n = n+1?
        La expresión actúa similar a "map (+1) [1, -4, 6, 2, -8]" y su equivalente debería ser "[2,-3,7,3,-7]".
            En este caso, "map" toma como 1° argumento la función "succ", que basicamente suma 1 al número ingresado ("n"), y toma como 2° argumento la lista "[1, -4, 6, 2, -8]".
            La función aplicará "succ" a cada elemento de la lista, por lo que devolverá una lista nueva en donde a cada elemento se le sumó 1 (positivo, por lo que los negativos tendrán un valor absoluto menor al anterior).

    c) ¿Y la expresion filter esPositivo [1, -4, 6, 2, -8]?
        La expresión actúa similar a "filter (>0) [1, -4, 6, 2, -8]" y su equivalente debería ser "[1,6,2]".
            En este caso, "filter" crea una lista nueva en donde sólo se incluyen los elementos de la original cuyo valor sea "True" para la función "esPositivo".

8. Programa una funcion que dada una lista de numeros xs, devuelve la lista que resulta de duplicar cada valor de xs.-}
    --a) Definila usando recursion.
duplica :: [Int] -> [Int]
duplica [] = []
duplica (x:xs) = x*2 : duplica xs

{- Pruebas con duplica:
    ghci> duplica [1,2,3,4,5]
    [2,4,6,8,10]
    ghci> duplica [0,1,0,1]
    [0,2,0,2]
    ghci> duplica []
    []
    ghci> duplica [0]
    [0]
-}
    --b) Definila utilizando la funcion map.
duplica' :: [Int] -> [Int]
duplica' xs = map (*2) xs

{- Pruebas con duplica':        --mismos resultados que la función anterior.
    ghci> duplica' [1,2,3,4,5]
    [2,4,6,8,10]
    ghci> duplica' [0,1,0,1]
    [0,2,0,2]
    ghci> duplica' []
    []
    ghci> duplica' [0]
    [0]
-}
--9. Programa una funcion que dada una lista de numeros xs, calcula una lista que tiene como elementos aquellos numeros de xs que son primos.
    --a) Definila usando recursion.
soloPrimos :: [Int] -> [Int]
soloPrimos [] = []
soloPrimos (x:xs)   | esPrimo x = x:soloPrimos xs
                    | otherwise = soloPrimos xs

{- Pruebas con soloPrimos:
    ghci> soloPrimos [1,2,3,4,5,6,7,8,9]
    [2,3,5,7]
    ghci> soloPrimos [1,4,6,8,9]
    []
-}
    --b) Definila utilizando la funcion filter.
soloPrimos' :: [Int] -> [Int]
soloPrimos' xs = filter esPrimo xs

{- Pruebas con soloPrimos':        --mismos resultados que la función anterior.
    ghci> soloPrimos' [1,2,3,4,5,6,7,8,9]
    [2,3,5,7]
    ghci> soloPrimos' [1,4,6,8,9]
    []
-}
    --c) Revisa tu definicion del ejercicio 6g. ¿Como podes mejorarla?
multiplicaPrimos' :: [Int] -> Int
multiplicaPrimos' xs = productoria' (soloPrimos' xs) id

{- Pruebas con multiplicaPrimos':        --mismos resultados que la función multiplicaPrimos.
    ghci> multiplicaPrimos' [0,1,2,3,4,5]
    30
    ghci> multiplicaPrimos' [0,1,2,3,4]
    6
    ghci> multiplicaPrimos' [0,2,3,5,6,7]
    210
-}
--10. La funcion primIgualesA toma un valor y una lista, y calcula el tramo inicial mas largo de la lista cuyos elementos son iguales a ese valor. Por ejemplo:
    --a) Programa primIgualesA por recursion.
primIgualesA  :: Eq a => a -> [a] -> [a]    --el "Eq a =>" le informa a Haskell que "a" tiene un tipo que permite comparar valores.
primIgualesA n [] = []
primIgualesA n (x:xs)   | x/=n = []
                        | x==n = x:primIgualesA n xs

{- Pruebas con primIgualesA:        --mismos resultados que el ejemplo del proyecto.
    ghci> primIgualesA 3 [3,3,4,1]
    [3,3]
    ghci> primIgualesA 3 [4,3,3,4,1]
    []
    ghci> primIgualesA 3 []
    []
    ghci> primIgualesA 'a' "aaadaa"
    "aaa"
-}
    --b) Programa nuevamente la funcion utilizando takeWhile.
primIgualesA' :: Eq a => a -> [a] -> [a]
primIgualesA' n xs = takeWhile (==n) xs

{- Pruebas con primIgualesA':        --mismos resultados que la función anterior y el ejemplo del proyecto.
    ghci> primIgualesA'  3 [3,3,4,1]
    [3,3]
    ghci> primIgualesA' 3 [4,3,3,4,1]
    []
    ghci> primIgualesA' 3 []         
    []
    ghci> primIgualesA' 'a' "aaadaa" 
    "aaa"
-}
--11. La funcion primIguales toma una lista y devuelve el mayor tramo inicial de la lista cuyos elementos son todos iguales entre sı. Por ejemplo:
    --a) Programa primIguales por recursion.
primIguales :: Eq a => [a] -> [a]
primIguales [] = []
primIguales (x:y:xs)    | x==y = x:primIguales (y:xs)
                        | x/=y = [x]

{- Pruebas con primIguales:         --mismos resultados que el ejemplo del proyecto.
    ghci> primIguales [3,3,4,1] 
    [3,3]
    ghci> primIguales [4,3,3,4,1]
    [4]
    ghci> primIguales []
    []
    ghci> primIguales "aaadaa"
    "aaa"
-}
    --b) Usa cualquier version de primIgualesA para programar primIguales. Esta permitido dividir en casos, pero no usar recursion.
primIguales' :: Eq a => [a] -> [a]
primIguales' [] = []
primIguales' (x:xs) = primIgualesA' x (x:xs)

{- Pruebas con primIguales':         --mismos resultados que la función anterior y el ejemplo del proyecto.
    ghci> primIguales' [3,3,4,1]  
    [3,3]
    ghci> primIguales' [4,3,3,4,1]
    [4]
    ghci> primIguales' []         
    []
    ghci> primIguales' "aaadaa"
    "aaa"
-}
--12. (*) Todas las funciones del ejercicio 4 son similares entre sı: ... ... definı de manera recursiva la funcion cuantGen (denota la cuantificacion generalizada):
cuantGen :: (b -> b -> b) -> b -> [a] -> (a -> b) -> b
cuantGen op z [] t = z
cuantGen op z (x:xs) t = op (t x) (cuantGen op z xs t)

{- Pruebas con cuantGen:
    ghci> cuantGen (+) 0 [1,2,3] (*2)
    12
    ghci> cuantGen (*) 1 [1,2,3] (*2)
    48
    ghci> cuantGen (&&) True [1,2] even     
    False
    ghci> cuantGen (&&) True [4,2] even
    True
    ghci> cuantGen (||) False [1,2] even
    True
    ghci> cuantGen (||) False [1,1] even
    False
-}
--Reescribir todas las funciones del punto 4 utilizando el cuantificador generalizado (sin usar induccion y en una lınea por funcion).
paratodo''' :: [a] -> (a -> Bool) -> Bool
paratodo''' xs t = cuantGen (&&) True xs t

{- Pruebas con paratodo''':             --mismos resultados que la función del punto 4a.
    ghci> paratodo''' [1,2,3] even
    False
    ghci> paratodo''' [2,4] even
    True
    ghci> paratodo''' "hola" esVocal
    False
    ghci> paratodo''' "aeiou" esVocal
    True
-}

existe'' :: [a] -> (a -> Bool) -> Bool
existe'' xs t = cuantGen (||) False xs t

{- Pruebas con existe'':             --mismos resultados que la función del punto 4b.
    ghci> existe'' [1,2,3] even
    True
    ghci> existe'' [1,3] even  
    False
    ghci> existe'' "hola" esVocal   
    True
    ghci> existe'' "bcdfg" esVocal
    False
-}

sumatoria'' :: [a] -> (a -> Int) -> Int
sumatoria'' xs t =  cuantGen (+) 0 xs t

{- Pruebas con sumatoria'':         --mismos resultados que la función del punto 4c.
    ghci> sumatoria'' [1,2,3,4] factorial
    33
    ghci> sumatoria'' [1,(-2),3,(-4)] valorAbsoluto
    10
    ghci> sumatoria'' ["hola"] length        
    4
    ghci> sumatoria'' ["hola","adios"] length
    9
    ghci> sumatoria'' [] length      
    0
-}

productoria'' :: [a] -> (a -> Int) -> Int
productoria'' xs t =  cuantGen (*) 1 xs t

{- Pruebas con productoria'':       --mismos resultados que la función del punto 4d.
    ghci> productoria'' [1,2,3,4] factorial
    288
    ghci> productoria'' [1,(-2),3,(-4)] valorAbsoluto
    24
    ghci> productoria'' ["hola"] length              
    4
    ghci> productoria'' ["hola","adios"] length
    20
    ghci> productoria'' [] length              
    1
-}
--13. (*) Definir una funcion que se denomina distancia de edicion...
distanciaEdicion::[Char]->[Char]-> Int
distanciaEdicion [] ys = length ys
distanciaEdicion xs [] = length xs
distanciaEdicion (x:xs) (y:ys)  | x==y = distanciaEdicion xs ys
                                | x/=y = 1+distanciaEdicion xs ys

{- Pruebas con distanciaEdicion:
    ghci> distanciaEdicion "" ""
    0
    ghci> distanciaEdicion "hola" ""
    4
    ghci> distanciaEdicion "" "adios"
    5
    ghci> distanciaEdicion "dado" "dedo"
    1
-}
--14. (*) Definı una funcion primeros que cumplen, primQueCumplen::[a]->(a->Bool)->[a], tal que, dada una lista ls y un predicado p, devuelve el tramo inicial de ls que cumple p.
primQueCumplen::[a]->(a->Bool)->[a]
primQueCumplen ls p = takeWhile p ls

{- Pruebas con primQueCumplen:
    ghci> primQueCumplen [1,2,3] even
    []                                  --la lista no empieza con un numero par
    ghci> primQueCumplen [1,2,3] odd 
    [1]                                 --la lista empieza con un único numero impar
    ghci> primQueCumplen [2,4,1] even
    [2,4]                               --la lista empieza con 2 numeros pares
    ghci> primQueCumplen [1,3,2] odd 
    [1,3]                               --la lista empieza con 2 numeros impares
    ghci> primQueCumplen "aeabbba" esVocal
    "aea"                               --la lista empieza con 3 vocales
    ghci> primQueCumplen [] even          
    []                                  --la lista esta vacía
-}
{-15. (*) Para cada uno de los siguientes patrones, decidı si estan bien tipados, y en tal caso da los tipos de cada subexpresion. En caso de estar bien tipado, ¿el patron cubre todos los casos de definicion?
    a)  f :: (a, b) -> ...      --esta función recibe una "dupla" y devuelve "algo". Los elementos "a" y "b" de la dupla pueden ser de cualquier tipo y ser diferentes entre sí.
        f (x , y) = ...         --el patrón es correcto, y permite que "x" e "y" tomen diferentes valores.

    b)  f :: [(a, b)] -> ...    --esta función recibe una "lista de duplas" y devuelve "algo". Los elementos "a" y "b" de la dupla pueden ser de cualquier tipo y ser diferentes entre sí.
        f (a , b) = ...         --el patrón no es correcto, el compilador dará un error al esperar un patrón tipo lista ([]).

    c)  f :: [(a, b)] -> ...    --la función es del mismo tipo que la anterior ya descripta.
        f (x:xs) = ...          --el patrón es correcto, toma una lista "xs" (la cual puede ser una lista de duplas) y obtiene "x", que es el primer elemento (un dupla en este caso)

    d)  f :: [(a, b)] -> ...                --la función es del mismo tipo que las 2 anteriores ya descriptas.
        f ((x, y) : ((a, b) : xs)) = ...    --el patrón es correcto, toma una lista "xs" (la cual puede ser una lista de duplas) y obtiene los 2 primeros elementos que son duplas, mediante los patrones (x,y) y (a,b).

    e)  f :: [(Int, a)] -> ...  --la función recibe una "lista de duplas" y devuelve "algo". Cada dupla contiene un entero (Int) y un elemento cualquiera ("a").
        f [(0, a)] = ...        --este patrón sólo funcionará frente a una "lista de duplas", cuyas "duplas" tengan 0 como elemento entero. Dará un error en todos los otros casos.

    f ) f :: [(Int, a)] -> ...      --la función es del mismo tipo que la anterior ya descripta.
        f ((x, 1) : xs) = ...       --el patrón no es correcto

    g)  f :: (Int -> Int) -> Int -> ...     --la función recibe otra función (toma un entero y devuelve otro entero) y un entero para devolver "algo".
        f a b = ...                         --el patrón es correcto. "a" debe ser una función y "b" un entero.

    h)  f :: (Int -> Int) -> Int -> ...     --la función es del mismo tipo que la anterior ya descripta.
        f a 3 = ...                         --el patrón es correcto. "a" debe ser una función y "3" es un entero que actúa como constante (respeta el tipo de la función).

    i)  f :: (Int -> Int) -> Int -> ...     --la función es del mismo tipo que las 2 anteriores ya descriptas.
        f 0 1 2 = ...                       --el patrón no es correcto, la función pide 2 argumentos (una función y un entero), pero aqui se declaran 3.
-}
{-16. (*) Para las siguientes declaraciones de funciones, da al menos una definicion cuando sea posible. ¿Podes dar alguna otra definicion alternativa a la que diste en cada caso?
    Por ejemplo, si la declaracion es f :: (a, b) -> a, la respuesta es: f (x,y) = x 
    a)  f :: (a, b) -> b
        f (x,y) = y         --basicamente, es una función que recibe una dupla y devuelve el segundo elemento de la dupla.

    b)  f :: (a, b) -> c
        f (x,y) = x+y       --es una función que recibe una dupla y devuelve otro valor cualquiera. En este ejemplo, si "a" y "b" son tipo "Num", pueden ser sumados.

    c)  f :: (a -> b) -> a -> b
        f op x = op(x)      --es una función que recibe otra función que toma un valor "a" y devuelve uno "b", más un valor "a" cualquiera, para ser usado en esa misma función, devolviendo un "b" al final.

    d)  f :: (a -> b) -> [a] -> [b]
        f op xs = 

-}