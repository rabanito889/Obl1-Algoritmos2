# Justificación de órdenes — Obligatorio 1


## Ejercicio 1
- Instancio dos AVL con un TAD generico, logrando que ALTA y BUSCAR sea en O(log K) en el peor caso (ya que los AVL siempre estan balanceados), mientras que rango respeta ese O(log k + r) ya que busca y acota logaritmicamente por naturaleza

## Ejercicio 2
- Se usa tabla hash abierta, haciendo x2 el valor esperado para evitar rehashing y respetar ordenes, se ordena la palabra alfabeticamente para que no haya que recorrer y comparar varias veces, manteniendose O(L), puse contadores globales de cantidad de cajpnes y el cajon con mas palabras para que este pueda accederse en O(1)

## Ejercicio 3
- Se utiliza un Min-Heap binario implementado sobre un arreglo (O(N) espacial) que extrae iterativamente los dos archivos de menor tamaño y reinserta su suma en tiempo O(logN)$ por paso, acumulando el costo total en variables para resolver el problema en O(N log N) en el peor caso.

## Ejercicio 4
- Se guarda el grafo en una lista de adyacencia y se lleva un arreglo con la cantidad de dependencias que le faltan a cada módulo, usando una idea parecida al algoritmo de Khan donde los módulos que quedan listos sin dependencias entran a un Min-Heap para sacar en $O(\log V)$ el de menor prioridad, logrando un tiempo de $O((V + A) \log V)$ en el peor caso

## Ejercicio 5
- Use el algoritmo de Kruskal eligiendo los senderos más baratos con un Min-Heap y uniendo las zonas con un MFSet (con compresión de caminos y unión por altura para no formar ciclos). Esto asegura conectar todo el parque al menor costo posible en $O(E \log E)$ de tiempo

