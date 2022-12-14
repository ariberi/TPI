//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>
#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

/*
 Sea cual sea la posicion y el tamano del tablero, pasa 3 veces por el primer loop for y 3 veces en el segundo loop for  por cada una de las 3 del primero, // o sea que entra 9 veces al segundo loop for.
 Es decir, al pasarle una posicion itera la misma cantidad de veces sin importar el tamaño del tablero de entrada.
 Por lo tanto la complejidad temporal es de orden O(1).
 */

int minasAdyacentes(tablero& t, pos p) {

    int minas = 0;
    int p0 = p.first;
    int p1 = p.second;

    for(int fila = -1; fila<=1; fila++){
        for(int col = -1; col <=1; col++){

            if (adyacenteValida(t,p, fila, col) && t[p0+fila][p1+col] == cMINA){
                minas++;
            }
        }
    }
    return minas;
}

/******++++**************************** EJERCICIO cambiarBanderita ***********+++***********************/

/*
 En esta funcion tenemos un loop for que recorre toda la lista de banderitas, y en el peor de los casos se le pasa a la funcion la ultima posicion del tablero,
 y dentro de la lista de banderitas estan todas las posiciones del tablero.
 Analogamente, con la funcion posicionJugada,que esta dentro de la funcion principal, ocurre lo mismo pero como no estan anidadas no aumento la complejidad.
 Teniendo en cuenta esto, podemos decir que la complejidad temporal es de orden O(t.size()) o seria lo mismo decir O(n).

*/
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {

    for (int i = 0; i < b.size(); i++){
        if (b[i] == p){
            b.erase(b.begin()+i);
            return;
        }
    }
    bool posJugada = posicionJugada(j,p);
    if (not(posJugada)){
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/

/*
 En este ejercicio tenemos una funcion depende temporalmente de lista de jugadas que en el peor de los casos contiene al tablero entero
 Por lo tanto la complejidad temporal es de orden O(j.size()), que seria lo mismo a decir O(n).
 */

bool perdio(tablero& t, jugadas& j) {

    bool res = false;
    for (int i = 0; i < j.size(); i++){

        pair<int,int> p = j[i].first;
        int p0 = p.first;
        int p1 = p.second;

        if (t[p0][p1] == cMINA){
            res = true;
        }
    }
    return res;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/

/*
 En este ejercicio recorremos el tablero entero fijandose que no exista ninguna posicion vacia sin jugar
 En el peor de los casos, el tablero esta lleno de casillas vacias y fueron todas jugadas, por lo tanto la complejidad temporal resutante es de orden O(n^3).
 Si bien en la primera parte de la funcion llama a la funcion perdio, que es de complejidad O(n), al no estar anidado, no aumenta la complejidad total de la funcion gano.
*/

bool gano(tablero& t, jugadas& j) {

    int res = true;

    if (perdio(t,j)){
        res = false;
    }
    for (int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){
            pos p = make_pair(i,k);
            if (t[i][k] == cVACIA && !posicionJugada(j,p)){
                    res = false;
            }
        }
    }
    return res;
}




/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/

/*
 Esta funcion se fija que la posicion que se le pasa como parametro no este jugada ni tenga una banderita,
 se le calcula la cantidad de minas adyacentes y se la agrega a la lista de jugadas.
 Luego se fija que sea una posicion vacia y que no tenga minas adyacentes, y si esto es asi,
 recorre por medio de dos loop for para descubrir todas esas posiciones.
 Y asi con todas esas posiciones descubiertas se hace lo mismo llamando otra vez a la funcion, que es entonces recursiva.
 En el peor de los casos, el tablero esta completamente lleno de casillas vacias y todas fueron jugadas.
 Al ser una funcion recursiva no se puede calcular la complejidad temporal,
 pero sabemos que en el peor de los casos se itera sobre todas las posiciones del tablero.
 Podemos decir que las condiciones pedidas en la funcion aseguran la terminacion de la misma.

*/


void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {

    bool posJugada = posicionJugada(j,p);
    bool posBanderita = posicionTieneBanderita(b,p);

    if (not posJugada && not posBanderita){

        int cantidadMinasAdyacentes = minasAdyacentes(t,p);
        j.push_back(make_pair(p, cantidadMinasAdyacentes));

        if (t[p.first][p.second] == cVACIA){
            if (cantidadMinasAdyacentes == 0){
                for(int fila = -1; fila<=1; fila++){
                    for(int col = -1; col <=1; col++){
                        if (adyacenteValida(t,p, fila, col)){
                            pos q = make_pair(p.first+fila, p.second+col);
                            jugarPlus(t, b, q, j);
                        }
                    }
                }
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/

/*
 La funcion empieza recorriendo el tablero completo, por lo tanto hasta ahi tenemos una complejidad de orden O(n^2) por tener dos ciclos for anidados, donde n es la longitud del tablero

 Siguiendo, la complejidad de la funcion esPosicionSinJugarYSinBanderita es de orden O(j.size())+O(b.size()) que en el peor de los casos,
 la longitud de las jugadas tiene todas las posiciones del tablero, y lo mismo para con las banderitas, por lo tanto es O(n) + O(n) = O(n).
 Luego, esAdyacente121 depende tambien de las posiciones de las jugadas que en peor caso son de O(n).
 Por lo tanto la complejidad entre las dos funciones es de orden O(n), dado que se suman ambas.

 Vale la pena aclarar que las funciones minasAdyacentes() y push_back() tiene complejidad O(1).

 En total, la funcion es de orden O(n^2) * O(n) = O(n^3).
*/

bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {

    bool hay = false;
    for (int i = 0; i < t.size(); i++){
        for (int k = 0; k < t[0].size(); k++){

            pos q = make_pair(i,k);
            if (esPosicionSinJugarYSinBanderita(t,j,b,q) && esAdyacente121(q, j, t)){
                if (t[i][k] == cVACIA) {
                    p = q;
                    j.push_back(make_pair(p, minasAdyacentes(t, p)));
                    hay = true;
                    return hay;
                }
            }
        }
    }
    return hay;
}
