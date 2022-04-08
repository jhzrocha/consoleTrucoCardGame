#include <iostream>
#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED
struct Carta{
    int valor;
    int naipe;
    int valorHierarquico;

    std::string retornaNaipeEmString(){
        std::string naipes[5]= {"Ouro", "Espadas","Copas", "Paus", "X"};
        return naipes[this->naipe];
    }
};

#endif
