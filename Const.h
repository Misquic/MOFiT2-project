#ifndef CONST_H
#define CONST_H
#include <vector>

// plik w ktory ma byc zaloczony w kazdym innym pliku, definiuje stale i przydatne nazwy

namespace Const{
const int N       = 2;
const float DX    = 2;                  //krok miedzy kolejnymi wezlami w nm
const float nm_au = 18.89726133921252;  //liczba przez ktora nalezy wymnozyc by dokonac konwersji
const float Lnm   = 100;                // dlugosc boku calego ukladu nm
const float L     = nm_au*Lnm;         // dlugosc boku calego ukladu
const float anm   = Lnm/(2*N);          // dlugosc boku malego elementu nm
const float a     = L/(2*N);            // dlugosc boku malego elementu
}

using float2 = std::vector<std::vector<float>>;
using int2 = std::vector<std::vector<int>>;

#endif