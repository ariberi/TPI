¿Que pasaria si la estructura jugadas fuera una matriz conteniendo en cada posicion la
cantidad de minas adyacentes (o -1 si la casilla no fue jugada)? ¿Como afectaria eso a la complejidad temporal de peor
caso de los procedimientos jugarPlus y sugerirAutomatico121?

Si la estructura de jugadas fuera una matriz, la complejidad temporal se mantiene igual,
ya que en el peor de los casos jugadas es una matriz con las n posiciones del tablero y recorrerla tendrá un costo de O(n).
Cuando analizamos el jugadas dado por el enunciado, se tiene que en el peor caso jugadas es una lista con todas las posiciones del tablero, es decir, n posiciones.
Si bien puede pensarse que recorrer a jugadas como una matriz será de orden n^2, esto no sucede ya que la cantidad de posiciones almacenadas en la matriz siempre estará acotada por las posiciones del tablero
que será exactamente la misma cantidad de posiciones a recorrer que en jugadas pensada como una secuencia de tuplas en el peor de los casos.

Ejemplo: si tenemos una lista de jugadas con 100 elementos, entonces n = 100.
Si fuese una matriz, jugadas tendrá 10 listas de 10 elementos cada una, por lo que recorrerla será de orden m^2 = n = 100, donde m = 10 que son la cantidad de filas de la matriz.
Por lo tanto es la misma cantidad igual que recorrer la lista de jugadas.

En conclusion, la complejidad temporal de peor caso de ambas funciones no aumentaria.
