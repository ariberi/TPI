¿que pasaria si la estructura jugadas fuera una matriz conteniendo en cada posicion la
cantidad de minas adyacentes (o -1 si la casilla no fue jugada)? ¿Como afectaria eso a la complejidad temporal de peor
caso de los procedimientos jugarPlus y sugerirAutomatico121?

Si la variable jugadas fuera una matriz de enteros, para encontrar un elemento en ella, habria que
iterar dos veces en vez de una. Por lo que cada vez que se quiera hallar una posición la complejidad sería de O(n^2) en
lugar de O(n).
En jugarPlus sabemos que aumentaría su complejidad en al menos O(n), pero al ser recursiva no podemos definir su
complejidad.
Para sugerirAutomatico121, aumentaría su complejidad en al menos O(n). Pero en cada procedimiento donde queremos buscar
la cantidad de minas adyacentes, aumentará la cantidad de iteraciones, y asi la complejidad.

Vale la pena aclarar que, minasAdyacentes seguira siendo de complejidad constante O(1). Cada vez que una posicion se
juegue, reescribir la posición jugada seguirá siendo de complejidad O(1).



Si la estructura de jugadas fuera una matriz(...) la complejidad temporal se mantiene igual ya que en el peor de los casos jugadas es una matriz con las n posiciones del tablero y 
recorrerla tendra un costo de O(n^2).
Cuando analizamos el jugadas dado por el enunciado, se tiene que en el peor caso jugadas es una lista con todas las posiciones del tablero, es decir, n posiciones