--1. Tipos enumerados. Cuando los distintos valores ...
    --a) Implementa el tipo Carrera como esta definido arriba.
data Carrera = Matematica | Fisica | Computacion | Astronomia

{-
    ghci> :i Carrera
    type Carrera :: *
    data Carrera = Matematica | Fisica | Computacion | Astronomia
            -- Defined at Proyecto2.hs:3:1
-}

    --b) Defini la siguiente funcion, usando pattern matching:
titulo :: Carrera -> String
titulo Matematica = "Licenciatura en Matematica"
titulo Fisica = "Licenciatura en Fisica"
titulo Computacion = "Licenciatura en Computacion"
titulo Astronomia = "Licenciatura en Astronomia"

{- Pruebas con titulo:
    ghci> titulo Matematica
    "Licenciatura en Matematica"
    ghci> titulo Computacion
    "Licenciatura en Computacion"
-}
    --c) Para escribir musica se utiliza la denominada notacion musical...
--data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si               --comentado por estar superpuesto con el punto 2a

{-
    ghci> :i NotaBasica
    type NotaBasica :: *
    data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si
            -- Defined at Proyecto2.hs:27:1
-}

    --d) El sistema de notacion musical anglosajon, tambien...
cifradoAmericano :: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

{- Pruebas con cifradoAmericano:
    ghci> cifradoAmericano Fa
    'F'
    ghci> cifradoAmericano Sol
    'G'
-}
--2. Clases de tipos. En Haskell usamos el operador...
    --a) Completar la definicion del tipo NotaBasica para que las expresiones...
data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si deriving (Eq, Ord, Show)    --agregado Eq y Ord para poder usar "<=" y Show para poder mostar el elemento que devuelve 'min'.

{-
    ghci> Do <= Re
    True
    ghci> min Fa Sol  
    Fa
-}

--3. Polimorfismo ad hoc Recordemos la funcion sumatoria...
    --a) Definir usando polimorfismo ad hoc la funcion minimoElemento
minimoElemento :: Ord a => [a] -> a
minimoElemento [x] = x
minimoElemento (x:xs) = min x (minimoElemento xs)

{- Pruebas con minimoElemento:
    ghci> minimoElemento ['a']
    'a'
    ghci> minimoElemento [1]  
    1
    ghci> minimoElemento [3,1,2]
    1
    ghci> minimoElemento ['b','a','c']
    'a'
-}
    --b) Definir la funcion minimoElemento' de manera tal...
minimoElemento' :: (Ord a,Bounded a) => [a] -> a
minimoElemento' [] = maxBound
minimoElemento' (x:xs) = min x (minimoElemento' xs)

{- Pruebas con minimoElemento':
    ghci> minimoElemento' []
    ()
    ghci> minimoElemento' []::Bool
    True
    ghci> minimoElemento' []::Int
    9223372036854775807
    ghci> minimoElemento' [1,5,10]::Int
    1
-}
    --c) Usar la funcion minimoElemento para...
{-
    ghci> minimoElemento [Fa, La, Sol, Re, Fa] 
    Re
-}
--4. Sinonimo de tipos; constructores con parametros. En este ejercicio...
    --a) Implementa el tipo Deportista y todos sus tipos accesorios (NumCamiseta, Altura,Zona, etc) tal como estan definidos arriba.

type Altura = Int
type NumCamiseta = Int

data Zona = Arco | Defensa | Mediocampo | Delantera
    deriving (Show,Eq)     --se agrega "Eq" para la función accesoria del punto 4e: contar_futbolistas' con filter. "Show" se agrega desde el punto 7.a.1).
data TipoReves = DosManos | UnaMano
    deriving Show   --agregado "Show" desde el punto 7.a.1) ya que "Cola" incluye "Deportista" como constructor y, este a su vez, incluye "TipoReves" como constructor.
data Modalidad = Carretera | Pista | Monte | BMX
    deriving Show   --agregado "Show" desde el punto 7.a.1) ya que "Cola" incluye "Deportista" como constructor y, este a su vez, incluye "Modalidad" como constructor.
data PiernaHabil = Izquierda | Derecha
    deriving Show   --agregado "Show" desde el punto 7.a.1) ya que "Cola" incluye "Deportista" como constructor y, este a su vez, incluye "PiernaHabil" como constructor.

type ManoHabil = PiernaHabil

data Deportista = Ajedrecista | Ciclista Modalidad | Velocista Altura | Tenista TipoReves ManoHabil Altura | Futbolista Zona NumCamiseta PiernaHabil Altura
    deriving Show --agregado "Show" desde el punto 7.a.1) ya que "Cola" incluye "Deportista" como constructor y debe ser mostrado por pantalla.

    --b) >Cual es el tipo del constructor Ciclista?
{-
    ghci> :t Ciclista
    Ciclista :: Modalidad -> Deportista         --el tipo de Ciclista es un constructor que espera un argumento ("Modalidad") y devuelve un elemento ("Deportista")
-}

    --c) Programa la funcion contar_velocistas :: [Deportista] -> Int ...
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0
contar_velocistas ((Velocista _):xs) = 1 + contar_velocistas xs
contar_velocistas (x:xs) = contar_velocistas xs

{- Pruebas con contar_velocistas:
    ghci> contar_velocistas []
    0
    ghci> contar_velocistas [Velocista 10,Ajedrecista]   
    1
    ghci> contar_velocistas [Velocista 10,Ajedrecista,Velocista 5]
    2
-}
    --d) Programa la funcion contar_futbolistas :: [Deportista] -> Zona -> Int ...
contar_futbolistas :: [Deportista] -> Zona -> Int    
contar_futbolistas [] z = 0
contar_futbolistas ((Futbolista Arco _ _ _):xs) Arco = 1 + contar_futbolistas xs Arco
contar_futbolistas ((Futbolista Defensa _ _ _):xs) Defensa = 1 + contar_futbolistas xs Defensa
contar_futbolistas ((Futbolista Mediocampo _ _ _):xs) Mediocampo = 1 + contar_futbolistas xs Mediocampo
contar_futbolistas ((Futbolista Delantera _ _ _):xs) Delantera = 1 + contar_futbolistas xs Delantera
contar_futbolistas (x:xs) z = contar_futbolistas xs z

{- Pruebas con contar_futbolistas:
    ghci> contar_futbolistas [] Delantera                                     
    0
    ghci> contar_futbolistas [Futbolista Delantera 10 Izquierda 170] Delantera
    1
    ghci> contar_futbolistas [Futbolista Delantera 10 Izquierda 170,Futbolista Arco 1 Derecha 180,Futbolista Arco 13 Derecha 188] Arco      
    2
    ghci> contar_futbolistas [(Ajedrecista),(Futbolista Mediocampo 5 Izquierda 170),(Ciclista Pista),(Velocista 160),(Futbolista Mediocampo 8 Izquierda 175)] Mediocampo  
    2
-}
    --e) >La funcion anterior usa filter? Si no es asi, reprogramala para usarla.
esZona :: Zona -> Deportista -> Bool
esZona zona' (Futbolista zona a b c) = zona==zona'
esZona zona' dep = False

contar_futbolistas' :: [Deportista] -> Zona -> Int
contar_futbolistas' [] zona' = 0
contar_futbolistas' xs zona' = length (filter (esZona zona') xs)

{- Pruebas con contar_futbolistas':             --mismos resultados al usar los mismos casos que la función del punto 4d.
    ghci> contar_futbolistas' [] Delantera
    0
    ghci> contar_futbolistas' [Futbolista Delantera 10 Izquierda 170] Delantera
    1
    ghci> contar_futbolistas' [Futbolista Delantera 10 Izquierda 170,Futbolista Arco 1 Derecha 180,Futbolista Arco 13 Derecha 188] Arco
    2
    ghci> contar_futbolistas' [(Ajedrecista),(Futbolista Mediocampo 5 Izquierda 170),(Ciclista Pista),(Velocista 160),(Futbolista Mediocampo 8 Izquierda 175)] Mediocampo
    2
-}

--5. Definicion de clases. Vamos ahora a representar las notas musicales...
    --a) Implementa la funcion sonidoNatural como esta definida arriba.
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

{- Pruebas con sonidoNatural:
    ghci> sonidoNatural Fa
    5
    ghci> sonidoNatural Sol
    7
-}
    --b) Definir el tipo enumerado Alteracion que consta de los constructores Bemol, Natural y Sostenido.
data Alteracion = Bemol | Natural | Sostenido

    --c) Definir el tipo algebraico NotaMusical que ...
data NotaMusical = Nota NotaBasica Alteracion

    --d) Defini la funcion sonidoCromatico :: NotaMusical -> Int que ...
sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota x Bemol) = sonidoNatural x - 1
sonidoCromatico (Nota x Natural) = sonidoNatural x
sonidoCromatico (Nota x Sostenido) = sonidoNatural x + 1

{- Pruebas con sonidoCromatico:
    ghci> sonidoCromatico (Nota Fa Sostenido)
    6
    ghci> sonidoCromatico (Nota Fa Natural)  
    5
    ghci> sonidoCromatico (Nota Fa Bemol)  
    4
-}
    --e) Inclui el tipo NotaMusical a la clase Eq de manera tal que ...
instance (Eq NotaMusical) where 
    nMus1 == nMus2 = sonidoCromatico nMus1 == sonidoCromatico nMus2         --indica que la comparación entre 2 elementos de tipo "NotaMusical" se debe hacer teniendo en cuenta su valor resultante de la función "sonidoCromatico x"

{-
    ghci> sonidoCromatico (Nota Do Sostenido)
    1
    ghci> sonidoCromatico (Nota Re Bemol)    
    1
    ghci> sonidoCromatico (Nota Re Bemol) == sonidoCromatico (Nota Do Sostenido)
    True
    ghci> Nota Re Bemol == Nota Do Sostenido                                    
    True
-}

    --f ) Inclui el tipo NotaMusical a la clase Ord definiendo el operador <=. Se debe ...
instance (Ord NotaMusical) where 
    nMus1 <= nMus2 = sonidoCromatico nMus1 <= sonidoCromatico nMus2
{-
    ghci> Nota Re Bemol <= Nota Do Sostenido
    True
    ghci> sonidoCromatico (Nota Re Bemol) <= sonidoCromatico (Nota Do Sostenido)
    True
    ghci> sonidoCromatico (Nota Re Sostenido) <= sonidoCromatico (Nota Do Sostenido)
    False
    ghci> sonidoCromatico (Nota Re Sostenido) >= sonidoCromatico (Nota Do Sostenido)
    True
-}

--6. Tipos enumerados con polimorfismo.
    --a) Definir la funcion primerElemento que ...
primerElemento :: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:xs) = Just (x)

{- Pruebas con primerElemento:
    ghci> primerElemento [1,2,3]
    Just 1
    ghci> primerElemento []     
    Nothing
-}
--7. Tipos recursivos.
data Cola = VaciaC | Encolada Deportista Cola deriving Show --agregado "Show" desde el punto 7.a.1) para mostrar la "Cola" por pantalla.

    --a) Programa las siguientes funciones:
        --1) atender :: Cola -> Maybe Cola
atender :: Cola -> Maybe Cola
atender VaciaC = Nothing
atender (Encolada x y) = Just y

{- Pruebas con atender:
    ghci> atender VaciaC                       
    Nothing
    ghci> atender (Encolada Ajedrecista VaciaC)
    Just VaciaC
    ghci> atender (Encolada Ajedrecista (Encolada (Ciclista Monte) VaciaC))
    Just (Encolada (Ciclista Monte) VaciaC)
-}
        --2) encolar :: Deportista -> Cola -> Cola
encolar :: Deportista -> Cola -> Cola
encolar dep1 VaciaC = (Encolada dep1 VaciaC)
encolar dep1 (Encolada dep2 cola) = (Encolada dep2 (encolar dep1 cola))

{- Pruebas con encolar:
    ghci> encolar Ajedrecista VaciaC
    Encolada Ajedrecista VaciaC
    ghci> encolar Ajedrecista (Encolada (Ciclista Monte) VaciaC)
    Encolada (Ciclista Monte) (Encolada Ajedrecista VaciaC)
    ghci> encolar Ajedrecista (Encolada (Ciclista Monte) (Encolada (Velocista 170) VaciaC))
    Encolada (Ciclista Monte) (Encolada (Velocista 170) (Encolada Ajedrecista VaciaC))
-}
        --3) busca :: Cola -> Zona -> Maybe Deportista
busca :: Cola -> Zona -> Maybe Deportista
busca VaciaC zon = Nothing
busca (Encolada (Futbolista zona a b c) cola) zona' | zona==zona' = Just (Futbolista zona a b c)
                                                    | otherwise   = busca cola zona'
busca (Encolada dep cola) zona' = busca cola zona'

{- Pruebas con busca:
    ghci> busca VaciaC Arco 
    Nothing
    ghci> busca (Encolada Ajedrecista VaciaC) Arco
    Nothing
    ghci> busca (Encolada Ajedrecista (Encolada (Futbolista Arco 1 Izquierda 180) VaciaC)) Arco
    Just (Futbolista Arco 1 Izquierda 180)
    ghci> busca (Encolada Ajedrecista (Encolada (Futbolista Arco 1 Izquierda 170) (Encolada (Futbolista Arco 1 Izquierda 180) VaciaC))) Arco
    Just (Futbolista Arco 1 Izquierda 170)                                                                                                  --devuelve el 1ero encontrado.
-}

    --b) >A que otro tipo se parece Cola?.
    {-
        El tipo "Cola" es similar al tipo "Lista" de Haskell.
        Si tipeamos " :i [] " en ghci nos informa que "[]" tiene " type [] :: * -> * " y " data [] a = [] | a : [a] ".
        Si bien no son exactamente iguales en su definición de "type", ya que Cola es " type Cola :: * ", en sus definiciones de "data" podemos ver las similitudes:
        -Por un lado, "VaciaC" actúa similar a "[]" ya que puede representar una lista sin "Deportistas" dentro (no requiere de este parámetro para funcionar).
        -Por otro lado, "Encolada Deportista Cola" actúa similar a "a:[a]" en donde un "Deportista" se "pega" a la "Cola", la cual puede tener un número no especificado de elementos (hasta terminar en un "VaciaC").
-}

--8. Tipos recursivos y polimorficos.
data ListaAsoc a b = Vacia | Nodo a b ( ListaAsoc a b ) deriving Show       --se agrega "Show" a partir del ejercicio 8.b.2) en donde debe devolver una "ListAsoc a b" por pantalla

    --a) >Como se debe instanciar el tipo ListaAsoc para representar la informacion almacenada en una guia telefonica?
type GuiaTelefonica = ListaAsoc String Int      --donde el String hace referencia a un nombre y el Int a un número de teléfono.

    --b) Programa las siguientes funciones:
        --1) la_long :: ListaAsoc a b -> Int
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b listA) = 1 + la_long listA

{- Pruebas con la_long:
    ghci> la_long Vacia           
    0
    ghci> la_long (Nodo 1 1 Vacia)
    1
    ghci> la_long (Nodo 1 1 (Nodo 1 1 Vacia))
    2
-}
        --2) la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat Vacia listaA2 = listaA2
la_concat (Nodo a b listaA1) listaA2 = Nodo a b (la_concat listaA1 listaA2)

{- Pruebas con la_concat:
    ghci> la_concat Vacia (Nodo 1 1 Vacia)
    Nodo 1 1 Vacia
    ghci> la_concat Vacia (Nodo 1 1 (Nodo 2 2 Vacia))
    Nodo 1 1 (Nodo 2 2 Vacia)
    ghci> la_concat (Nodo 3 3 Vacia) (Nodo 1 1 (Nodo 2 2 Vacia))
    Nodo 3 3 (Nodo 1 1 (Nodo 2 2 Vacia))
    ghci> la_concat (Nodo 3 3 (Nodo 4 4 Vacia)) (Nodo 1 1 (Nodo 2 2 Vacia))
    Nodo 3 3 (Nodo 4 4 (Nodo 1 1 (Nodo 2 2 Vacia)))
-}
        --3) la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia clave dato = (Nodo clave dato Vacia)
la_agregar (Nodo a b listA) clave dato  | a/=clave = (Nodo a b (la_agregar listA clave dato))
                                        | a==clave = (Nodo a dato listA)

{- Pruebas con la_agregar:
    ghci> la_agregar Vacia 1 1 
    Nodo 1 1 Vacia
    ghci> la_agregar (Nodo 2 2 Vacia) 1 1
    Nodo 2 2 (Nodo 1 1 Vacia)
    ghci> la_agregar (Nodo 2 2 (Nodo 3 3 Vacia)) 1 1
    Nodo 2 2 (Nodo 3 3 (Nodo 1 1 Vacia))
    ghci> la_agregar (Nodo 2 2 (Nodo 1 3 Vacia)) 1 1
    Nodo 2 2 (Nodo 1 1 Vacia)
    ghci> la_agregar (Nodo 1 3 (Nodo 3 3 Vacia)) 1 1
    Nodo 1 1 (Nodo 3 3 Vacia)
-}
        --4) la_pares :: ListaAsoc a b -> [(a, b)]
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b listaA) = (a,b):la_pares listaA

{- Pruebas con la_pares:
    ghci> la_pares (Nodo 1 1 Vacia)
    [(1,1)]
    ghci> la_pares (Nodo 1 1 (Nodo 2 2 Vacia))
    [(1,1),(2,2)]
-}
        --5) la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia clave = Nothing
la_busca (Nodo a b listaA) clave    | a==clave = Just (b)
                                    | a/=clave = la_busca listaA clave

{- Pruebas con la_busca:
    ghci> la_busca Vacia 1
    Nothing
    ghci> la_busca (Nodo 1 1 Vacia) 2
    Nothing
    ghci> la_busca (Nodo 1 1 (Nodo 2 2 Vacia)) 2
    Just 2
    ghci> la_busca (Nodo 1 'a' (Nodo 2 'b' Vacia)) 2
    Just 'b'
-}
        --6) la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar clave Vacia = Vacia
la_borrar clave (Nodo a b listaA)    | clave==a = la_borrar clave listaA
                                     | clave/=a = (Nodo a b (la_borrar clave listaA))

{- Pruebas con la_borrar:           --como no quedaba claro si cada clave es única, lo programé para que siga borrando los datos al encontrar otra clave igual.
    ghci> la_borrar 1 Vacia
    Vacia
    ghci> la_borrar 1 (Nodo 1 1 Vacia)
    Vacia
    ghci> la_borrar 1 (Nodo 2 2 Vacia)
    Nodo 2 2 Vacia
    ghci> la_borrar 1 (Nodo 2 2 (Nodo 1 1 Vacia))
    Nodo 2 2 Vacia
    ghci> la_borrar 1 (Nodo 1 1 (Nodo 1 1 (Nodo 2 2 Vacia)))
    Nodo 2 2 Vacia
-}

--9. (Punto *) Programa las siguientes funciones:
data Arbol a = Hoja | Rama ( Arbol a ) a ( Arbol a ) deriving (Show)  --agregado Show a partir del punto 9c
    --a) a_long :: Arbol a -> Int
a_long :: Arbol a -> Int
a_long Hoja = 0
a_long (Rama arb1 valor arb2) = 1+ a_long arb1 + a_long arb2

{- Pruebas con a_long:
    ghci> a_long Hoja
    0
    ghci> a_long (Rama (Hoja) 1 (Hoja)) 
    1
    ghci> a_long (Rama (Rama (Hoja) 1 (Hoja)) 1 (Hoja))
    2
    ghci> a_long (Rama (Rama (Hoja) 1 (Hoja)) 1 (Rama (Hoja) 1 (Hoja)))
    3
    ghci> a_long (Rama (Rama (Rama (Hoja) 1 (Hoja)) 1 (Hoja)) 1 (Rama (Hoja) 1 (Hoja)))
    4
-}
    --b) a_hojas :: Arbol a -> Int
a_hojas :: Arbol a -> Int
a_hojas Hoja = 1
a_hojas (Rama arb1 valor arb2) = a_hojas arb1 + a_hojas arb2

{- Pruebas con a_hojas:
    ghci> a_hojas Hoja
    1
    ghci> a_hojas (Rama (Hoja) 1 (Hoja)) 
    2
    ghci> a_hojas (Rama (Rama (Hoja) 1 (Hoja)) 1 (Hoja))
    3
    ghci> a_hojas (Rama (Rama (Hoja) 1 (Hoja)) 1 (Rama (Hoja) 1 (Hoja)))
    4
    ghci> a_hojas (Rama (Rama (Rama (Hoja) 1 (Hoja)) 1 (Hoja)) 1 (Rama (Hoja) 1 (Hoja)))
    5
-}
    --c) a_inc :: Num a => Arbol a -> Arbol a
a_inc :: Num a => Arbol a -> Arbol a
a_inc Hoja = Hoja
a_inc (Rama arb1 valor arb2) = Rama (a_inc arb1) (valor+1) (a_inc arb2)

{- Pruebas con a_inc:
    ghci> a_inc Hoja     
    Hoja
    ghci> a_inc (Rama (Hoja) 1 (Hoja)) 
    Rama Hoja 2 Hoja
    ghci> a_inc (Rama (Rama (Hoja) 1 (Hoja)) 2 (Hoja))
    Rama (Rama Hoja 2 Hoja) 3 Hoja
    ghci> a_inc (Rama (Rama (Hoja) 1 (Hoja)) 2 (Rama (Hoja) 3 (Hoja)))
    Rama (Rama Hoja 2 Hoja) 3 (Rama Hoja 4 Hoja)
-}
    --d) a_map :: (a -> b) -> Arbol a -> Arbol b
a_map :: (a -> b) -> Arbol a -> Arbol b
a_map op Hoja = Hoja
a_map op (Rama arb1 valor arb2) = Rama (a_map op arb1) (op valor) (a_map op arb2)

{- Pruebas con a_map:
    ghci> a_map (*2) Hoja
    Hoja
    ghci> a_map (*2) (Rama (Hoja) 1 (Hoja))
    Rama Hoja 2 Hoja
    ghci> a_map (*2) (Rama (Rama (Hoja) 1 (Hoja)) 2 (Hoja))
    Rama (Rama Hoja 2 Hoja) 4 Hoja
    ghci> a_map (*2) (Rama (Rama (Hoja) 1 (Hoja)) 2 (Rama (Hoja) 3 (Hoja)))
    Rama (Rama Hoja 2 Hoja) 4 (Rama Hoja 6 Hoja)
-}
a_inc' :: Num a => Arbol a -> Arbol a
a_inc' arbol = a_map (+1) arbol

{- Pruebas con a_inc':          --mismos resultados que al usar a_inc del punto 9c.
    ghci> a_inc' Hoja     
    Hoja
    ghci> a_inc' (Rama (Hoja) 1 (Hoja)) 
    Rama Hoja 2 Hoja
    ghci> a_inc' (Rama (Rama (Hoja) 1 (Hoja)) 2 (Hoja))
    Rama (Rama Hoja 2 Hoja) 3 Hoja
    ghci> a_inc' (Rama (Rama (Hoja) 1 (Hoja)) 2 (Rama (Hoja) 3 (Hoja)))
    Rama (Rama Hoja 2 Hoja) 3 (Rama Hoja 4 Hoja)
-}

--10. (Punto *) Programar los siguientes apartados:
    --a) : Definir el tipo recursivo ABB
data ABB a = VacioABB | RamaABB (ABB a) a (ABB a)   deriving Show       --Agregado Show para el punto 10b.

    --b) Definir una funcion insertarABB
insertarABB :: Ord a => a -> ABB a -> ABB a
insertarABB valor' VacioABB = RamaABB (VacioABB) valor' (VacioABB)
insertarABB valor' (RamaABB (arbol1) valor (arbol2))    | valor'>valor = (RamaABB (arbol1) valor (insertarABB valor' arbol2))
                                                        | valor'<valor = (RamaABB (insertarABB valor' arbol1) valor (arbol2))
                                                        | valor'==valor= (RamaABB (arbol1) valor (arbol2))                      --Agregado el caso en el que sean iguales, por lo que devuelva el mismo árbol.

{- Pruebas con insertarABB:
    ghci> insertarABB 2 VacioABB
    RamaABB VacioABB 2 VacioABB
    ghci> insertarABB 3 (RamaABB VacioABB 2 VacioABB)
    RamaABB VacioABB 2 (RamaABB VacioABB 3 VacioABB)
    ghci> insertarABB 1 (RamaABB VacioABB 2 VacioABB)
    RamaABB (RamaABB VacioABB 1 VacioABB) 2 VacioABB
    ghci> insertarABB 3 (RamaABB VacioABB 2 (RamaABB VacioABB 3 VacioABB))
    RamaABB VacioABB 2 (RamaABB VacioABB 3 VacioABB)                        --devuelve el mismo árbol ABB si el valor ya esta presente, asumiendo que deban ser únicos.
-}
    --c) Define una funcion llamada buscarEnArbol
buscarABB :: Eq a => a -> ABB a -> Bool
buscarABB valor' VacioABB = False
buscarABB valor' (RamaABB (arbol1) valor (arbol2))  | valor'==valor = True
                                                    | valor'/=valor = (buscarABB valor' arbol1) || (buscarABB valor' arbol2)
--                                                  | valor' >valor = buscarABB valor' arbol2    --Si "a" tuviese la clase "Ord", se podría hacer más eficiente la búsqueda, ya que si valor' fuese
--                                                  | valor' <valor = buscarABB valor' arbol1    --mayor al valor de la ramaABB, continua buscando por la derecha, caso contrario, busca por izquierda.
{- Pruebas con buscarABB:
    ghci> buscarABB 1 VacioABB 
    False
    ghci> buscarABB 1 (RamaABB (RamaABB (RamaABB VacioABB 1 VacioABB) 2 VacioABB) 3 (RamaABB VacioABB 4 (RamaABB VacioABB 5 VacioABB)))
    True
    ghci> buscarABB 1 (RamaABB (RamaABB (RamaABB VacioABB 0 VacioABB) 2 VacioABB) 3 (RamaABB VacioABB 4 (RamaABB VacioABB 5 VacioABB)))
    False
-}
    --d) Notar que los constructores RamaABB y VacioABB
mayor_a_todos :: Ord a => a -> ABB a -> Bool
mayor_a_todos valor' VacioABB = True
mayor_a_todos valor' (RamaABB (arbol1) valor (arbol2))  | valor'>valor = True && (mayor_a_todos valor' arbol1) && (mayor_a_todos valor' arbol2)
                                                        | valor'<valor = False

menor_a_todos :: Ord a => a -> ABB a -> Bool
menor_a_todos valor' VacioABB = True
menor_a_todos valor' (RamaABB (arbol1) valor (arbol2))  | valor'>valor = False
                                                        | valor'<valor = True && (menor_a_todos valor' arbol1) && (menor_a_todos valor' arbol2)

verificarABB :: Ord a => ABB a -> Bool
verificarABB VacioABB = True
verificarABB (RamaABB (arbol1) valor (arbol2)) = (mayor_a_todos valor arbol1) && (menor_a_todos valor arbol2) && (verificarABB arbol1) && (verificarABB arbol2) --No estoy seguro si esta función debe ser recursiva también, pero me pareció apropiado.
                                                                                                                                                                --De esta forma, verifica que la condición se cumpla para todos los nodos, además de la raíz.
ejemplo1 = RamaABB  ( RamaABB VacioABB 10 VacioABB ) 2 ( RamaABB VacioABB 11 VacioABB )

ejemplo2 = RamaABB  ( RamaABB ( RamaABB VacioABB 1 VacioABB ) 3 ( RamaABB VacioABB 7 VacioABB ) ) 5 ( RamaABB VacioABB 8 ( RamaABB VacioABB 10 VacioABB ) )

{- Pruebas con verificarABB:
    ghci> verificarABB ejemplo1
    False
    ghci> verificarABB ejemplo2
    False
    ghci> verificarABB VacioABB 
    True
    ghci> verificarABB (RamaABB VacioABB 1 VacioABB)
    True
    ghci> verificarABB (RamaABB (RamaABB VacioABB 0 VacioABB) 1 (RamaABB VacioABB 2 VacioABB))
    True
    ghci> verificarABB (RamaABB (RamaABB VacioABB 0 VacioABB) 1 (RamaABB VacioABB 0 VacioABB))
    False
    ghci> verificarABB (RamaABB (RamaABB VacioABB 2 VacioABB) 1 (RamaABB VacioABB 2 VacioABB))
    False
-}