--Lógica de Predicados sobre listas:
--Intro: definimos una función que determine si x pertenece a la lista xs, servirá como Rango de la expresión:
--Def Infija: no válida para Haskell
    -- ∈ :: [a] -> Bool
    -- e ∈ []      = False               (1)
    -- e ∈ (x:xs)  = (e==x) || (e ∈ xs)  (2)

--Def Prefija: válida para Haskell
perteneceALista :: Eq a => a -> [a] -> Bool
perteneceALista e [ ] = False 
perteneceALista e (x:xs) = (e == x) || (perteneceALista e xs)

--Intro: se definen la funcion todosPares, que funcionará como Término de la expresión:
todosPares :: [Int] -> Bool
todosPares [] = True
todosPares (x:xs) = mod x 2 ==0 && todosPares xs

--Intro: con ambas funciones, se puede definir la expresión "todos los elementos de la lista son pares" ó "< ∀x : x ∈ xs : mod x 2 == 0 >"

--Definición de un nuevo tipo de dato: se definen los datos "Color" y "Forma", y el tipo "Figura", que es una tupla que contiene ambos datos anteriores más un número entero
data Color = Rojo | Amarillo | Azul | Verde
    deriving (Show, Eq)

data Forma = Triangulo | Cuadrado | Rombo | Circulo
    deriving (Show, Eq)

type Figura = (Forma, Color, Int)
--1-) Implementá en Haskell las funciones correspondientes a los predicados azul, amarillo, verde, circulo, rombo, cuadrado y triangulo.
rojo :: Figura -> Bool
rojo (f,c,t) = c == Rojo

azul :: Figura -> Bool
azul (f,c,t) = c == Azul

amarillo :: Figura -> Bool
amarillo (f,c,t) = c == Amarillo

verde :: Figura -> Bool
verde (f,c,t) = c == Verde

circulo :: Figura -> Bool
circulo (f,c,t) = f == Circulo

rombo :: Figura -> Bool
rombo (f,c,t) = f == Rombo

cuadrado :: Figura -> Bool
cuadrado (f,c,t) = f == Cuadrado

triangulo :: Figura -> Bool
triangulo (f,c,t) = f == Triangulo

--2-) Definí la función tam :: Figura -> Int, que dada una figura devuelve su tamaño.
tam :: Figura -> Int
tam (f,c,t) = t

--3, 4, 5-) Expresá las siguientes propiedades utilizando los cuantificadores y los predicados y funciones ya definidas, dar un ejemplo que la cumpla y uno que no la cumpla, definí la función.
    --A) Todas las figuras de xs son rojas
    --   < ∀x : x ∈ xs : rojo.x >
xsATrue :: [Figura]
xsATrue = [(Triangulo,Rojo,5 ),(Cuadrado,Rojo,10),(Circulo,Rojo,2)]
xsAFalse :: [Figura]
xsAFalse = [(Cuadrado,Azul,15),(Circulo,Rojo,1),(Triangulo,Azul,2)]

propA :: [Figura] -> Bool
propA [ ] = True
propA (x : xs) = rojo x && propA xs

    --B) Todas las figuras de xs son de tamaño menor a 5. 
    --   < ∀x : x ∈ xs : tam.x < 5 >
xsBTrue :: [Figura]
xsBTrue = [(Cuadrado,Azul,3)]
xsBFalse :: [Figura]
xsBFalse = [(Circulo,Rojo,6)]

propB :: [Figura] -> Bool
propB [ ] = True
propB (x : xs) = tam x < 5 && propB xs

    --C)  Todos los triángulos de xs son rojos. 
    --  < ∀x : x ∈ xs && triangulo.x : rojo.x >
    --  < ∀x : x ∈ xs : triangulo.x => rojo.x >
xsCTrue :: [Figura]
xsCTrue = [(Cuadrado,Rojo,5 )]
xsCFalse :: [Figura]
xsCFalse = [(Triangulo,Verde,10)]

propC :: [Figura] -> Bool
propC [ ] = True
--propC (x : xs) | triangulo x = rojo x && propC xs
--               | otherwise   = propC xs
propC (x : xs) = (not(triangulo x) || rojo x) && propC xs

    --D) Existe un cuadrado verde en xs.
    --  < ∃x : x ∈ xs : cuadrado.x && verde.x >
    --  < ∃x : x ∈ xs && cuadrado.x : verde.x >
    --  < ∃x : verde.x && cuadrado.x : x ∈ xs >
xsDTrue :: [Figura]
xsDTrue = [(Cuadrado,Verde,5 ),(Cuadrado,Rojo,10)]
xsDFalse :: [Figura]
xsDFalse = [(Cuadrado,Azul,5 ),(Cuadrado,Rojo,10)]

propD :: [Figura] -> Bool
propD [ ] = False
propD (x : xs) = (cuadrado x && verde x) || propD xs

    --E) Todos los círculos de xs son azules y de tamaño menor a 10. 
    --  < ∀x : x ∈ xs && circulo.x : azul.x && tam.x < 10 >
    --  < ∀x : x ∈ xs : circulo.x => (azul.x && tam.x < 10) >
xsETrue :: [Figura]
xsETrue = [(Cuadrado,Verde,5 ),(Circulo,Azul,2)]
xsEFalse :: [Figura]
xsEFalse = [(Circulo,Verde,5 ),(Circulo,Azul,11)]

propE :: [Figura] -> Bool
propE [ ] = True
--propE (x : xs) | circulo x = (azul x && tam x < 10) && propE xs
--               | otherwise   = propE xs
propE (x : xs) = (not(circulo x) || (azul x && tam x < 10)) && propE xs

    --F) Ningún triángulo de xs es azul. 
    --  ¬< ∃x : x ∈ xs && triangulo.x : azul.x >
    --   < ∀x : x ∈ xs && triangulo.x : ¬(azul.x) >
    --  ¬< ∃x : x ∈ xs : triangulo.x => azul.x >
    --   < ∀x : x ∈ xs : triangulo.x => ¬(azul.x) >
xsFTrue :: [Figura]
xsFTrue = [(Cuadrado,Verde,5 )]
xsFFalse :: [Figura]
xsFFalse = [(Triangulo,Azul,5 )]

propF :: [Figura] -> Bool
propF [ ] = True
--propF (x : xs) | triangulo x && azul x = False
--               | otherwise   = propF xs
propF (x : xs) = (not(triangulo x) || not(azul x)) && propF xs

    --G) En xs no hay círculos amarillos ni verdes. 
    --  ¬< ∃x : x ∈ xs && circulo.x : amarillo.x || verde.x > 
    --  < ∀x : x ∈ xs && circulo.x : ¬(amarillo.x || verde.x) >
    --  < ∀x : x ∈ xs : circulo.x => ¬amarillo.x && ¬verde.x >
xsGTrue :: [Figura]
xsGTrue = [(Circulo,Rojo,3 ),(Cuadrado,Verde,5 )]
xsGFalse :: [Figura]
xsGFalse = [(Circulo,Verde,6 ),(Circulo,Amarillo,5 )]

propG :: [Figura] -> Bool
propG [ ] = True
--propG (x : xs) | circulo x && (amarillo x || verde x) = False
--               | otherwise   = propG xs
propG (x : xs) = (not(circulo x) || (not(verde x) && not(amarillo x))) && propG xs

    --H) Existe (al menos) un cuadrado de tamaño menor a 5 en xs 
    --  < ∃x : x ∈ xs && cuadrado.x : tam.x < 5 >
xsHTrue :: [Figura]
xsHTrue = [(Cuadrado,Verde,4 )]
xsHFalse :: [Figura]
xsHFalse = [(Cuadrado,Verde,6 )]

propH :: [Figura] -> Bool
propH [ ] = False
propH (x : xs) = (cuadrado x && tam x < 5 ) || propH xs

    --I) Si hay círculos rojos en xs entonces hay cuadrados rojos. 
    --  < ∃x : x ∈ xs : circulo.x && rojo.x > => < ∃y : y ∈ xs : cuadrado.y && rojo.y >
xsITrue :: [Figura]
xsITrue = [(Circulo,Verde,4), (Cuadrado,Verde,4)]
xsIFalse :: [Figura]
xsIFalse = [(Cuadrado,Rojo,6), (Cuadrado,Verde,6)]

existeCirculoRojo :: [Figura] -> Bool
existeCirculoRojo [ ] = False
existeCirculoRojo (x : xs) = (circulo x && rojo x) || existeCirculoRojo xs

existeCuadradoRojo :: [Figura] -> Bool
existeCuadradoRojo [ ] = False
existeCuadradoRojo (x : xs) = (cuadrado x && rojo x) || existeCuadradoRojo xs

propI:: [Figura] -> Bool
--propI [ ] = True
propI xs = not(existeCirculoRojo xs) || existeCuadradoRojo xs

--6-) Construí una lista de figuras xs en las que se satisfagan progresivamente cada una de las siguientes sentencias. Formalizá las oraciones con la lógica de predicados.
    --a) Alguna figura de xs es de tamaño mayor a 10.
    --  < ∃x : x ∈ xs : tam.x > 10 >
--xs6A :: [Figura]
--xs6A = [(xx,xx,11)]
    --b) Hay un cuadrado en xs.
    --  < ∃x : x ∈ xs : cuadrado.x >
--xs6AB :: [Figura]
--xs6AB = [(Cuadrado,xx,11)]
    --c) En xs hay un cuadrado de tamaño mayor a 10.
    --  < ∃x : x ∈ xs : cuadrado.x && tam.x > 10 >
--xs6ABC :: [Figura]
--xs6ABC = [(Cuadrado,xx,11)]
    --d) De las figuras de xs, un cuadrado azul es más grande que alguno de los círculos.
    --  < Ǝx : x ∈ xs: cuadrado.x && azul.x && <Ǝy : y ∈ xs: circulo.y && (tam.x > tam.y)> >
xs6ABCD :: [Figura]
xs6ABCD = [(Cuadrado,Azul,11),(Circulo,Azul,9)]
    --e) Algún círculo de xs no es azul.
    --  < ∃x : x ∈ xs : circulo.x && ¬(azul.x) >
xs6ABCDE :: [Figura]
xs6ABCDE = [(Cuadrado,Azul,11),(Circulo,Rojo,9)]

--7-) Da un ejemplo de una lista de figuras xs que satisfaga simultáneamente los siguientes predicados
    --a) ⟨∀x : x ∈ℓ xs ∧ (¬rojo.x ∨ triangulo.x) : tam.x > 10⟩
    --b) ⟨∃x : x ∈ℓ xs ∧ rojo.x : True⟩ ∧ ⟨∃y : y ∈ℓ xs : ¬rojo.y⟩
    --c) ⟨∀x : x ∈ℓ xs ∧ rojo.x : cuadrado.x ∧ tam.x > 10⟩
xs6True :: [Figura]
xs6True = [(Cuadrado,Rojo,11 ),(Cuadrado,Verde,11 )]

--8-) Formalizá las siguientes sentencias escritas en lenguaje natural, utilizando cuantificadores y predicados arbitrarios para aquellas propiedades elementales.
    --a) Todo entero es par o impar.                            
            -- < ∀x : x ∈ xs : (par.x || impar.x) >
            -- < ∀x : entero.x : (mod.x.2 == 1 ∨ mod.x.2 == 0) >
    --b) La lista xs consiste sólo de 0’s y 1’s.
            -- < ∀x : x ∈ xs : x==0 || x==1 >
    --c) Si el 1 está en xs, entonces también el 0 esta.
            -- < ∃x,y : x,y ∈ xs : x==1 => y==0 >
            -- < ∃x : x ∈ xs ∧ x == 1 : 0 ∈ xs >
    --d) La lista xs contiene al menos un True.
            -- < ∃x : x ∈ xs : x == True >
    --e) Si xs es no vacía, su primer elemento es 0.
            -- xs /= [] => head.xs == 0
            -- #xs > 0 ⟹ xs!!0 == 0
    --f ) Todos los elementos de xs son iguales.
            -- < ∀i,j : 0 <= i < #xs && 0 <= j < #xs && i<j : xs!!i == xs!!j >
            -- < ∀x : x ∈ xs : < ∀y : y ∈ xs : y == x > >
    --g) Todos los elementos de la lista xs son distintos.
            -- < ∀i,j : 0 <= i < #xs && 0 <= j < #xs && i<j : xs!!i /= xs!!j >
    --h) La lista xs está ordenada de manera decreciente.
            -- < ∀i : 0 <= i < #xs - 1 : xs!!i >= xs!!i + 1 >
    --i) Las listas xs e ys tienen los mismos elementos.
            -- < ∀x : x ∈ xs : < ∃i : <= i < #ys : x==ys!!i > > && < ∀y : y ∈ ys : < ∃i : <= i < #xs : y==xs!!i > >
    --j) Todos los elementos de xs tienen al menos un elemento.
            -- < ∀x : x ∈ xs : #x > 0 >
            -- < ∀i : 0 <= i < #xs : < ∃x :: x ∈ xs!!i > >

--9-) Una propiedad que nos interesa expresar muchas veces es la unicidad, es decir, expresar que una propiedad se cumple una y sólo una vez. Expresá las siguientes propiedades:
    --a) Hay sólo un hombre en el mundo que es Papa.
            -- < ∃i : 0 <= i < #xs ∧ esPapa.xs!!i : < ∀j : 0 <= j < #xs ∧ j /= i : ∧ ¬(esPapa.xs!!j) > >
            -- < ∃x : hombre.x ^ esPapa.x: < ∀y : hombre.y ^ x!=y : ¬esPapa.y > >
    --b) En la lista xs hay sólo un 0.
            -- < ∃i : 0 <= i < #xs Λ xs!!i == 0: <∀ j : 0 <= j < #xs Λ i /= j : xs!!j /= 0 > >
    --c) x aparece sólo una vez en xs.
            -- < ∃i : 0 <= i < #xs Λ xs!!i == x : < ∀j : 0 <= j < #xs Λ i /= j : xs!!j /= x > >
            -- < ∃i : 0 <= i < #xs : xs!!i == x Λ < ∀j : 0 <= j < #xs Λ i /= j : xs!!j /= x > >
    --d) Hay un único cuadrado azul en xs.
            -- < ∃i : 0 <= i < #xs ∧ cuadrado.xs!!i ∧ azul.xs!!i : < ∀j : 0 <= j < #xs ∧ j /= i : ¬(cuadrado.xs!!j) ∧ ¬(azul.xs!!j) > >

--10-) ¿Cómo expresarías la propiedad “x ocurre exactamente dos veces en xs”?
        -- 