#ifndef LISTADUPLAMENTEENCADEADALOG_H_INCLUDED
#define LISTADUPLAMENTEENCADEADALOG_H_INCLUDED
#include "jogador.h"
#include "Carta.h"


struct LogJogada{
    Carta cartaJogada;
    std::string nomeJogador;

};
struct ElementoDuplamenteEncadeada{
    LogJogada valor;
    ElementoDuplamenteEncadeada *anter = nullptr;
    ElementoDuplamenteEncadeada *prox = nullptr;
};


struct ListaDuplamenteEncadeada{
    ElementoDuplamenteEncadeada *inicio = nullptr;

    void iniciarLista(LogJogada carta){
        ElementoDuplamenteEncadeada *novo = new ElementoDuplamenteEncadeada();
        if (this->inicio == nullptr){
            this->inicio = novo;
            novo->prox = nullptr;
            novo->valor = carta;
        }

    }
    ElementoDuplamenteEncadeada* getPtrFinalLista(){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;

        while(nav->prox != nullptr){
            nav = nav->prox;
        }
        return nav;
    }
    void adicionarFim(Carta cartaJogada, std::string nomeJogador){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        ElementoDuplamenteEncadeada *novo = new ElementoDuplamenteEncadeada();
        novo->valor.cartaJogada = cartaJogada;
        novo->valor.nomeJogador = nomeJogador;
        nav = this->inicio;
        while(nav->prox != nullptr){
            nav = nav->prox;
        }
        nav->prox = novo;
        novo->anter = nav;
    }
    void adicionarInicio(LogJogada carta){
        ElementoDuplamenteEncadeada *novo = new ElementoDuplamenteEncadeada();

        this->inicio->anter = novo;
        novo->prox = this->inicio;
        novo->valor = carta;
        this->inicio= novo;
    }
    int getQuantidadeElementos(){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;
        int contador = 0;
        while(nav != nullptr){
            contador++;
            nav = nav->prox;
        }
        return contador;
    }
    bool estaNaLista(LogJogada carta){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;

        while(nav != nullptr){
            Carta cartaNav = nav->valor.cartaJogada;
            if(carta.cartaJogada.valor == cartaNav.valor && carta.cartaJogada.naipe == cartaNav.naipe){
                return true;
            }else{
                nav = nav->prox;
            }
        }
        return false;
    }
     int getIndexPosicao(LogJogada carta){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;
        int contador = 0;
        while(nav != nullptr){
            Carta cartaNav = nav->valor.cartaJogada;
            if(carta.cartaJogada.valor == cartaNav.valor && carta.cartaJogada.naipe == cartaNav.naipe){
                return contador;
            }else{
                contador++;
                nav = nav->prox;
            }
        }
        return -1;
    }
    void adicionarNaPosicao(int posicao, LogJogada carta){
        ElementoDuplamenteEncadeada *novo = new ElementoDuplamenteEncadeada();
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        ElementoDuplamenteEncadeada *proximo = new ElementoDuplamenteEncadeada();
        nav = this->inicio;
        proximo = this-> inicio;
        int maiorElemento = this->getQuantidadeElementos();

        if (posicao > (maiorElemento - 1)){
            std::cout << "Não é possível adicionar nesta posição" << std::endl;
        }else{
            int contador = 0;
            while (contador != posicao - 1){
                nav = nav->prox;
                proximo =nav->prox;
                contador++;
            }
            novo->prox = nav->prox;
            nav->prox = novo;
            novo->anter = nav;
            proximo->anter = novo;
            novo->valor = carta;
        }
    }
     Carta getPorPosicao(int posicao){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        int maiorElemento = this->getQuantidadeElementos();

        nav = this->inicio;
        if (posicao > (maiorElemento - 1)){
            std::cout << "Não é possível pegar nesta posição" << std::endl;
        }else{
            int contador = 0;

            while (contador != posicao){
                nav = nav->prox;
                contador++;
            }

            return nav->valor.cartaJogada;
        }
    }
    void removeInicio(){
        this->inicio = this->inicio->prox;
    }
    void removeFim(){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;
        while(nav != nullptr){
            if(nav->prox->prox == nullptr ){
                nav->prox = nullptr;
                break;
            }
            nav = nav->prox;
       }
    }
    void removePosicao(int posicao){
        ElementoDuplamenteEncadeada *anterior = new ElementoDuplamenteEncadeada();
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        int maiorElemento = this->getQuantidadeElementos();
        nav = this->inicio;
        if (posicao > (maiorElemento - 1)){
            std::cout << "Não é possível remover nesta posição" << std::endl;
        }else{
            int contador = 0;

            while (contador != posicao){
                if(contador + 1 == posicao){
                    anterior = nav;
                }
                contador++;
                nav = nav->prox;
            }
            anterior->prox = nav->prox;
            nav->prox->anter = anterior;
        }
    }
    void imprimirListaJogadas(){
        ElementoDuplamenteEncadeada *nav = new ElementoDuplamenteEncadeada();
        nav = this->inicio;
        int cont = 0;
        std::cout << "Numero Jogada      Jogador       ,Valor , Naipe" << std::endl;
        while(nav != nullptr){

            std::cout << cont <<"  "<< nav->valor.nomeJogador << "   "<< nav->valor.cartaJogada.valor <<"   "<< nav->valor.cartaJogada.naipe <<std::endl;
            nav = nav->prox;
            cont++;
       }
    }
};
#endif // LISTADUPLAMENTEENCADEADALOG_H_INCLUDED
