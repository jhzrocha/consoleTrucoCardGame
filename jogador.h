#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#include <iostream>
#include "Carta.h"
#include "ListaEncadeadaSimples.h"
#include "ListaDuplamenteEncadeadaLog.h"
#include "baralho.h"
using namespace std;

struct Jogador{
    string nome;
    Baralho cartas;

    void iniciar(Carta a, Carta b, Carta c){
        cartas.insereNoInicio(a.valor, a.naipe, a.valorHierarquico);
        cartas.insereNoInicio(b.valor, b.naipe,b.valorHierarquico);
        cartas.insereNoInicio(c.valor, c.naipe, c.valorHierarquico);
    }

    int getIndexMaiorCarta(){
        int indexMaiorCarta = 0;
        for(int i = 0; i < 3; i++){
            if(cartas.obterCartaPorPosicao(indexMaiorCarta).valorHierarquico < cartas.obterCartaPorPosicao(i).valorHierarquico){
                indexMaiorCarta = i;
            }
        }
        return indexMaiorCarta;
    }

    int getIndexMenorCarta(){
        int indexMenorCarta = 0;
        for(int i = 0; i < 3; i++){
            if(cartas.obterCartaPorPosicao(indexMenorCarta).valorHierarquico > cartas.obterCartaPorPosicao(i).valorHierarquico){
                indexMenorCarta = i;
            }
        }
        return indexMenorCarta;
    }

    Carta jogarMaiorCarta(ListaDuplamenteEncadeada log){
        Carta cartaJogada = cartas.obterCartaPorPosicao(getIndexMaiorCarta());
        this->cartas.zerarValoresPorPosicao(getIndexMaiorCarta());
        log.adicionarFim(cartaJogada,this->nome);


        return cartaJogada;
    }

    Carta jogarMenorCarta(ListaDuplamenteEncadeada log){
        Carta cartaJogada = cartas.obterCartaPorPosicao(getIndexMenorCarta());
        cartas.zerarValoresPorPosicao(getIndexMenorCarta());

        log.adicionarFim(cartaJogada,this->nome);
        return cartaJogada;
    }

    void iniciarMaoJogador(ListaEncadeadaSimples *baralhoEmbaralhado, string nome){

        Carta cartasRecebidas[3];
        for(int i =0; i < 4; i++){
            cartasRecebidas[i] = baralhoEmbaralhado->getPorPosicao(i);
            baralhoEmbaralhado->removeInicio();
        }
        this->iniciar(cartasRecebidas[0],cartasRecebidas[1],cartasRecebidas[2]);
        this->nome = nome;
    }

    Carta fazerJogada(Carta cartaMaiorJogo, ListaDuplamenteEncadeada log){
            return this->jogarMaiorCarta(log);
    }

};
#endif // JOGADOR_H_INCLUDED
