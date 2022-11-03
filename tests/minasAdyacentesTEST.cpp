#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "definicionesTEST.h"

using namespace std;

TEST(minasAdyacentesTEST, posicionCentral) {
    tablero tt =
            {{ cMINA,  cMINA,  cMINA },
            { cMINA, cVACIA, cMINA},
            { cMINA, cMINA, cMINA}};
    pos p = make_pair(1,1);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(8, result);
}

TEST(minasAdyacentesTEST, bordeSuperiorIzquierdo) {
    tablero tt =
            {{ cVACIA,  cMINA,  cMINA },
             { cMINA, cMINA, cMINA},
             { cVACIA, cVACIA, cVACIA}};
    pos p = make_pair(0,0);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(3, result);
}

TEST(minasAdyacentesTEST, bordeInferiorDerechoConMina) {
    tablero tt =
            {{ cVACIA,  cMINA,  cMINA },
             { cMINA, cMINA, cMINA},
             { cVACIA, cVACIA, cMINA}};
    pos p = make_pair(2, 2);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(2, result);
}

TEST(minasAdyacentesTEST, sinMinas) {
    tablero tt =
            {{ cVACIA,  cVACIA,  cVACIA },
             { cVACIA, cVACIA, cVACIA},
             { cVACIA, cVACIA, cVACIA}};
    pos p = make_pair(1,2);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(0, result);
}

TEST(minasAdyacentesTEST, m2x2) {
    tablero tt =
            {{ cMINA,  cVACIA},
             { cMINA, cVACIA}};
    pos p = make_pair(0,0);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(1, result);
}

TEST(minasAdyacentesTEST, unSoloElemento) {
    tablero tt =
            {{cMINA}};
    pos p = make_pair(0,0);
    int result = minasAdyacentes(tt,p);
    ASSERT_EQ(0, result);
}