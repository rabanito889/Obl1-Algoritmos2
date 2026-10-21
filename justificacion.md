# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Instancio dos AVL con un TAD generico, logrando que ALTA y BUSCAR sea en O(log K) en el peor caso (ya que los AVL siempre estan balanceados), mientras que rango respeta ese O(log k + r) ya que busca y acota logaritmicamente por naturaleza

## Ejercicio 2
- Se usa tabla hash abierta, haciendo x2 el valor esperado para evitar rehashing y respetar ordenes, se ordena la palabra alfabeticamente para que no haya que recorrer y comparar varias veces, manteniendose O(L), puse contadores globales de cantidad de cajpnes y el cajon con mas palabras para que este pueda accederse en O(1)

## Ejercicio 3
- Se utiliza un Min-Heap binario implementado sobre un arreglo (O(N) espacial) que extrae iterativamente los dos archivos de menor tamaño y reinserta su suma en tiempo O(logN)$ por paso, acumulando el costo total en variables para resolver el problema en O(N log N) en el peor caso.

## Ejercicio 4
- Se guarda el grafo en una lista de adyacencia y se lleva un arreglo con la cantidad de dependencias que le faltan a cada módulo, usando una idea parecida al algoritmo de orden topológico donde los módulos que quedan listos sin dependencias entran a un Min-Heap para sacar en $O(\log V)$ el de menor prioridad, logrando un tiempo de $O((V + A) \log V)$ en el peor caso

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

