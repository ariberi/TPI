Si la variable jugadas fuera una matriz de enteros, para encontrar un elemento en ella, habria que
iterar dos veces en vez de una. Por lo que cada vez que se quiera hallar una posición la complejidad sería de O(n^2) en
lugar de O(n).
En jugarPlus sabemos que aumentaría su complejidad en al menos O(n), pero al ser recursiva no podemos definir su
complejidad.
Para sugerirAutomatico121, aumentaría su complejidad en al menos O(n). Pero en cada procedimiento donde queremos buscar
la cantidad de minas adyacentes, aumentará la cantidad de iteraciones, y asi la complejidad.

Vale la pena aclarar que, minasAdyacentes seguira siendo de complejidad constante O(1). Cada vez que una posicion se
juegue, reescribir la posición jugada seguirá siendo de complejidad O(1).