#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return this->alto_; //this-> puede NO incluirse porque ya se entiende que está apuntando a este contexto
}

uint Rectangulo::ancho() {
    return ancho_; //this-> puede NO incluirse porque ya se entiende que está apuntando a este contexto
}

float Rectangulo::area() {
    return ancho_ * alto_;
}

// Ejercicio 2

// Clase Elipse

float PI = 3.14;

class Elipse{
    public:
        Elipse (uint a, uint b);
        uint r_a();
        uint r_b();
        float area();

    private:
        uint r_a_;
        uint r_b_;

};

Elipse::Elipse(uint r_a, uint r_b) : r_a_(r_a),r_b_(r_b) {};

uint Elipse::r_a() {
    return this->r_a_; //this-> puede NO incluirse porque ya se entiende que está apuntando a este contexto
}

uint Elipse::r_b() {
    return r_b_; //this-> puede NO incluirse porque ya se entiende que está apuntando a este contexto
}

float Elipse::area() {
    return r_a_ * r_b_ * PI;
}

// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.ancho(); //Asumo por lado del cuadrado al ancho del rectangulo r_.Podría ser el alto también.
}

float Cuadrado::area() {
    return r_.ancho() * r_.ancho();
}

// Ejercicio 4

// Clase Circulo

class Circulo{
public:
    Circulo (uint a);
    uint radio();
    float area();

private:
    Elipse e_;

};

Circulo::Circulo(uint radio) : e_(radio,radio) {};

uint Circulo::radio() {
    return e_.r_a(); //Asumo por radio del circulo al radio_a de la elipse e_. Podría ser radio_b también.
}

float Circulo::area() {
    return e_.r_a() * e_.r_a() * PI;
}


// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}

// Ejercicio 6

ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}


