#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "definicionesTEST.h"

using namespace std;


banderitas b = {pos(0,1), pos(4,0), pos(2,1)};


TEST(jugarPlusTEST, posicionConBanderita){

    pos p = make_pair(0,1);
    jugadas j = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };
    jugadas j_esperada = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0)
    };
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j, j_esperada);
}

TEST(jugarPlusTEST, posicionYaJugada){

    pos p = make_pair(0,2);
    jugadas j = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };
    jugadas j_esperada = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0)
    };
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j, j_esperada);
}

TEST(jugarPlusTEST, posicionConMina){

    pos p = make_pair(0,0);
    jugadas j = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };
    jugadas j_esperada = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
            jugada(pos(0,0), 1)
    };
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j, j_esperada);
}

TEST(jugarPlusTEST, posicionInicialVaciaConAlMenosUnaMinaAdyacente){

    pos p = make_pair(0,3);
    jugadas j = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };
    jugadas j_esperada = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
            jugada(pos(0,3), 1)
    };
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j, j_esperada);
}

TEST(jugarPlusTEST, posicionInicialVaciaSinMinasAdyacentes){

    pos p = make_pair(3,4);
    jugadas j = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
    };
    jugadas j_esperada = {
            jugada(pos(0, 2), 2), jugada(pos(0, 4), 1),
            jugada(pos(1, 0), 3), jugada(pos(1, 4), 1),
            jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
            jugada(pos(3,4), 0), jugada(pos(2, 3), 1), jugada(pos(2, 4), 1), jugada(pos(3, 3), 1)
    };
    jugarPlus(t,b,p,j);
    ASSERT_EQ(j, j_esperada);
}

