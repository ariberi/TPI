// Tests para la función gano.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "definicionesTEST.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘


jugadas jugadasTodaviaNoPerdio = {
        jugada(pos(0, 2), 2),jugada(pos(0, 3), 1),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 3),jugada(pos(1, 1), 3),jugada(pos(1, 2), 3),
};

jugadas jugadasPerdio = {
        jugada(pos(0, 2), 2),
        jugada(pos(2,1), 0)
};


TEST(perdioTEST, todaviaNoPerdio){
    jugadas j = jugadasTodaviaNoPerdio;
    ASSERT_FALSE(perdio(t, j));
}

TEST(perdioTEST, perdioElJuego){
    jugadas j = jugadasPerdio;
    ASSERT_TRUE(perdio(t, j));
}

TEST(perdioTEST, listaVacia){
    jugadas j = {};
    ASSERT_FALSE(perdio(t, j));
}


