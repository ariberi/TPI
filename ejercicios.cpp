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

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

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

bool gano(tablero& t, jugadas& j) {

    vector<pos> posicionesDeCasillasVacias = CasillasVacias(t);

    int contador = 0;

    for (int i = 0; i < posicionesDeCasillasVacias.size(); i++){
        pos p = posicionesDeCasillasVacias[i];
        if (posicionValida(t,p)){
            if (posicionJugada(j,p)){
                contador++;
            }
        }
    }
    bool res = (contador == posicionesDeCasillasVacias.size());
    return res;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/

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
                }
            }
        }
    }
    return hay;
}

