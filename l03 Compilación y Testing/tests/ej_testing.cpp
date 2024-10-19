#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int valor_calculado = 15 + 7;
    int valor_esperado = 22;
    EXPECT_EQ(valor_calculado, valor_esperado);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    int valor_calculado = 10^2;
    float valor_esperado = pow(10,2);
    EXPECT_EQ(valor_calculado, valor_esperado);
}

// Ejercicios 6..9

TEST(Aritmetica, potenciaGeneral) {
    for(int i=-5;i<=5;i++){
        if (i != 0) {
            int valor_calculado = pow(i,2);
            float valor_esperado = i*i;
            EXPECT_EQ(valor_calculado, valor_esperado);
        }
    }
}

TEST(Diccionario, obtener) {
    map<int, int> m;
    m[4] = 3;
    EXPECT_EQ(m.at(4), 3);

}

TEST(Diccionario, definir) {
    map<int, int> m;
    EXPECT_EQ(m.count(2),0);
    m[2] = 3;
    EXPECT_EQ(m.count(2),1);

}

TEST(Truco, inicio) {
    Truco t;
    int valor_calculado1 = t.puntaje_j1();
    int valor_calculado2 = t.puntaje_j2();
    int valor_esperado = 0;
    EXPECT_EQ(valor_calculado1, valor_esperado);
    EXPECT_EQ(valor_calculado2, valor_esperado);

}


 // i++ and ++i are very similar but not exactly the same. Both increment the number, but ++i increments the number
 // before the current expression is evaluated, whereas i++ increments the number after the expression is evaluated.

TEST(Truco, buenas) {
    Truco t;
    EXPECT_FALSE(t.buenas(1));
    for (int i = 0; i < 15; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));




}




