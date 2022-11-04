#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


tablero tt_sin_patron = {
         {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
         {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
         {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
         {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
         {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA}
};

tablero tt_horizontal = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cMINA, cVACIA, cMINA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA}
};

tablero tt_vertical = {
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cMINA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cMINA, cVACIA, cVACIA},
        {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA}
};

jugadas jj_horizontal= {
        jugada(pos(1, 1), 1), jugada(pos(1, 2), 2), jugada(pos(1, 3), 1),
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 2), jugada(pos(3, 3), 1)
};

jugadas jj_horizontal_pos_ya_jugadas = {
        jugada (pos(0,2), 0), jugada(pos(2,2),0), jugada(pos (4,2),0),
        jugada(pos(1, 1), 1), jugada(pos(1, 2), 2), jugada(pos(1, 3), 1),
        jugada(pos(3, 1), 1), jugada(pos(3, 2), 2), jugada(pos(3, 3), 1)
};
jugadas jj_vertical = {
        jugada(pos(1, 1), 1), jugada(pos(1, 3), 1),
        jugada(pos(2, 1), 2), jugada(pos(2, 3), 2),
        jugada(pos(3, 1), 1), jugada(pos(3, 3), 1)
};

TEST(sugerir121TEST, noTieneAdyacente121){
    pos p = pos(2,2);
    banderitas b = {pos(4,3)};
    ASSERT_FALSE(sugerirAutomatico121(tt_sin_patron,b,jj_horizontal,p));
};


TEST(sugerir121TEST, posicionesEnBanderita){
    pos p = pos(2,2);
    banderitas b = {pos(2,2), pos(0,2), pos(4,2)};
    ASSERT_FALSE(sugerirAutomatico121(tt_horizontal,b,jj_horizontal_pos_ya_jugadas,p));
}

TEST(sugerir121TEST, posicionesYaJugadas){
    pos p = pos(2,0);
    banderitas b = {pos(4,3)};
    ASSERT_FALSE(sugerirAutomatico121(tt_horizontal,b,jj_horizontal_pos_ya_jugadas,p));
}

TEST(sugerir121TEST, posicionConMina){
    pos p = pos(2,1);
    banderitas b = {pos(4,3)};
    ASSERT_FALSE(sugerirAutomatico121(tt_horizontal,b,jj_horizontal_pos_ya_jugadas,p));
}

TEST(sugerir121TEST, posicionSugeribleHorizontal){
    pos p = pos(2,2);
    banderitas b = {pos(4,3)};
    ASSERT_TRUE(sugerirAutomatico121(tt_horizontal,b,jj_horizontal,p));
}

TEST(sugerir121TEST, posicionSugeribleVertical){
    pos p = pos(2,2);
    banderitas b = {pos(4,3)};
    ASSERT_TRUE(sugerirAutomatico121(tt_vertical,b,jj_vertical,p));
}

