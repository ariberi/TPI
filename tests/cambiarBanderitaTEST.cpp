#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"


using namespace std;

TEST(cambiarBanderitasTest, posConBanderitaYNoJugada){
    tablero tt =
            {{ cMINA,  cVACIA,  cVACIA },
             { cMINA, cVACIA, cVACIA},
             { cVACIA, cVACIA, cVACIA}};
    jugadas j = {make_pair(make_pair(1,1),1)};
    pos p = make_pair(1,0);
    banderitas b = {make_pair(0,0), make_pair(1,0)};
    cambiarBanderita(tt, j, p, b);
    banderitas b_esperada = {make_pair(0,0)};
    ASSERT_EQ(b, b_esperada);
}

TEST(cambiarBanderitasTest, posSinBanderitaYNoJugada){
    tablero tt =
            {{ cMINA,  cVACIA,  cVACIA },
             { cMINA, cVACIA, cVACIA},
             { cVACIA, cVACIA, cVACIA}};
    jugadas j = {make_pair(make_pair(1,1),1), make_pair(make_pair(1,2),1)};
    pos p = make_pair(1,0);
    banderitas b = {make_pair(0,0)};
    cambiarBanderita(tt, j, p, b);
    banderitas b_esperada = {make_pair(0,0), make_pair(1,0)};
    ASSERT_EQ(b, b_esperada);
}

TEST(cambiarBanderitasTest, posSinBanderitaYPreviamenteJugada){
    tablero tt =
            {{ cMINA,  cVACIA,  cVACIA },
             { cMINA, cVACIA, cVACIA},
             { cVACIA, cVACIA, cVACIA}};
    jugadas j = {make_pair(make_pair(1,1),1), make_pair(make_pair(2,2),0)};
    pos p = make_pair(2,2);
    banderitas b = {make_pair(0,0)};
    cambiarBanderita(tt, j, p, b);
    banderitas b_esperada = {make_pair(0,0)};
    ASSERT_EQ(b, b_esperada);
}



