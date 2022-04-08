#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "jogador.h"

#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <unistd.h>
struct Jogo{
    Baralho baralho;
    ListaEncadeadaSimples baralhoEmbaralhado;

    int qtdJogadores = 4;
    Jogador jogadores[10];

    ListaDuplamenteEncadeada logJogadas;
    Carta cartaMaisAlta;
    Carta coringa;

    int indexJogadoresEquipe1[2] = {0,2};
    int indexJogadoresEquipe2[2] = {1,3};

    int indexJogadorCartaMaisAltaRodada;

    int placarRodadaEq1 = 0;
    int placarRodadaEq2= 0;

    int placarJogoEq1 = 0;
    int placarJogoEq2 = 0;

      void imprimirCartasHorizontal(Jogador jogador){
            std::cout << "           ____   " << " ____   "<< " ____   "<< std::endl;
            std::cout << "            " << jogador.cartas.obterCartaPorPosicao(0).valor<< "      " << " " << jogador.cartas.obterCartaPorPosicao(1).valor<< "      "<< " " << jogador.cartas.obterCartaPorPosicao(2).valor<< "      "<< std::endl;
            std::cout << "          "<< jogador.cartas.obterCartaPorPosicao(0).retornaNaipeEmString() <<"   "<< " "<< jogador.cartas.obterCartaPorPosicao(1).retornaNaipeEmString() <<"   " << " "<< jogador.cartas.obterCartaPorPosicao(2).retornaNaipeEmString() <<"   "<< std::endl;
            std::cout << "          ____  "  << " ____  " << " ____  "<< std::endl;
    }
    void imprimirCartasVertical(Jogador jogador, Jogador jogador2){
            std::cout << "  ______   " << "                       " << " ______   "<<  std::endl;
            std::cout << "    " << jogador.cartas.obterCartaPorPosicao(0).valor<< "     " << "                       " << "   " << jogador2.cartas.obterCartaPorPosicao(0).valor<< "     " <<  std::endl;
            std::cout << "  " << jogador.cartas.obterCartaPorPosicao(0).retornaNaipeEmString() << "  " << "                       " << "  " << jogador2.cartas.obterCartaPorPosicao(0).retornaNaipeEmString() << "     " << std::endl;
            std::cout << "    ______  "<< "                       " << "  ______  "<< std::endl;

            std::cout << "  ______   " << "        "<<"______" << "            " << " ______   "<<  std::endl;
            std::cout << "    " << jogador.cartas.obterCartaPorPosicao(1).valor<< "     " << "           "<< this->cartaMaisAlta.valor<< "             " << "   " << jogador2.cartas.obterCartaPorPosicao(1).valor<< "     " <<   std::endl;
            std::cout << "  "<< jogador.cartas.obterCartaPorPosicao(1).retornaNaipeEmString() <<"  "<< "              " << this->cartaMaisAlta.retornaNaipeEmString()<< "         " << "  " << jogador2.cartas.obterCartaPorPosicao(1).retornaNaipeEmString()<< "     "<< std::endl;
            std::cout << "   ______  "<< "        " << "______"<< "          " << "  ______  "<< std::endl;

            std::cout << "   ______   " << "                       " << " ______   "<<  std::endl;
            std::cout << "    " << jogador.cartas.obterCartaPorPosicao(2).valor<< "                "<<"            " << "   " << jogador2.cartas.obterCartaPorPosicao(2).valor<< "     " <<  std::endl;
            std::cout << "  "<< jogador.cartas.obterCartaPorPosicao(2).retornaNaipeEmString() <<"  "<< "                       " << "  " << jogador2.cartas.obterCartaPorPosicao(2).retornaNaipeEmString()<< "     "<< std::endl;
            std::cout << "  ______  "<< "                       " << "  ______  "<< std::endl;
    }

    void imprimirCoringa(){
          std::cout << "Coringa :" << std::endl;
          std::cout << "   ______   "  << std::endl;
          std::cout << "    " << this->coringa.valor + 1 <<  std::endl;
          std::cout << "  "<< this->coringa.retornaNaipeEmString()<< std::endl;
          std::cout << "  ______  "<< std::endl;

    }

    void imprimirJogo(){
        std::cout << "Placar do Jogo :" << this->placarJogoEq1 << "X" << this->placarJogoEq2 << std::endl;
        std::cout << "Placar da Rodada :" << this->placarRodadaEq1 << "X" << this->placarRodadaEq2<< std::endl;
        imprimirCartasHorizontal(jogadores[0]);
        imprimirCartasVertical(jogadores[1],jogadores[3]);
        imprimirCartasHorizontal(jogadores[2]);
        imprimirCoringa();


    }

    void embaralharBaralho(){
        srand((unsigned)time(0));
        int maior = 0;
        int menor = 40;
        int aleatorio = rand()%(maior-menor);

        baralho.inicializaBaralhoTruco();
        this->coringa = baralho.cartas[aleatorio];
        baralho.definirValor(this->coringa);
        baralhoEmbaralhado.iniciarLista(baralho.cartas[aleatorio]);
        baralho.cartasEmbaralhadas[aleatorio] = true;

        while(!baralho.estaTodoEmbaralhado()){
            int aleatorio = rand()%(maior-menor);
            if(baralho.cartasEmbaralhadas[aleatorio] == false){
                baralhoEmbaralhado.adicionarFim(baralho.cartas[aleatorio]);
                baralho.cartasEmbaralhadas[aleatorio] = true;
            }
        }
    }
    void recebeJogada(Carta cartaDoJogador, int indexJogador){
        if(cartaDoJogador.valorHierarquico > this->cartaMaisAlta.valorHierarquico){
            this->cartaMaisAlta = cartaDoJogador;
            this->indexJogadorCartaMaisAltaRodada = indexJogador;
        }
    }

    void zerarRodada(){
        this->cartaMaisAlta.valorHierarquico = 0;
        this->cartaMaisAlta.valor=0;
        this->cartaMaisAlta.naipe = 4;

        this->indexJogadorCartaMaisAltaRodada = 0;

        this->placarRodadaEq1 = 0;
        this->placarRodadaEq2 = 0;
    }



    void adicionarCartasMaoJogadores(){
        for(int i=0; i < this->qtdJogadores ; i++){
            string nomesJogadores[10] = {"Roberto", "Felipe", "Julio", "Juliana"};
            ListaEncadeadaSimples * baralhoEmbaralhado = &this->baralhoEmbaralhado;
            this->jogadores[i].iniciarMaoJogador(baralhoEmbaralhado,nomesJogadores[i]);

        }
    }

    void avaliaVencedorSubRodada(){
        if(this->indexJogadorCartaMaisAltaRodada == 0 || this->indexJogadorCartaMaisAltaRodada == 2){
            this->placarRodadaEq1  = placarRodadaEq1  + 1;
        }else{
            this->placarRodadaEq2  = placarRodadaEq2 + 1;
        }
    }

    void avaliaVencedorRodada(){
        if(this->placarJogoEq1 < 12 || this->placarJogoEq2 < 12){
            if(this->placarRodadaEq1 >= 2){
                this->placarJogoEq1++;
                this->placarRodadaEq1 = 0;
                this->placarRodadaEq2 = 0;
            }
            if(this->placarRodadaEq2 >= 2){
                this->placarJogoEq2++;
                this->placarRodadaEq1 = 0;
                this->placarRodadaEq2 = 0;
            }

        }
    }

    void esperarJogada(){
        sleep(1000);
    }
    void iniciarJogo(){

        this->embaralharBaralho();
        this->adicionarCartasMaoJogadores();

        this->zerarRodada();
        LogJogada iniciarLog;
        iniciarLog.cartaJogada = cartaMaisAlta;
        iniciarLog.nomeJogador = "Log Iniciado";
        std::string entrada;
        this->logJogadas.iniciarLista(iniciarLog);
         while(this->placarJogoEq1 < 12 ||this->placarJogoEq2 < 12 ){
            while(this->placarRodadaEq1 < 2 ||this->placarRodadaEq2 < 2){
                for(int jog = 0 ; jog < this->qtdJogadores ; jog++){
                    system("cls");
                    this->imprimirJogo();
                    this->recebeJogada(jogadores[jog].fazerJogada(this->cartaMaisAlta,this->logJogadas),jog);
                    std::cin >> entrada;

                    if(entrada == "a"){
                        this->logJogadas.imprimirListaJogadas();
                        system("Pause");
                    }
                }
                this->avaliaVencedorSubRodada();
                this->avaliaVencedorRodada();
            }
            this->zerarRodada();
            this->embaralharBaralho();
            this->adicionarCartasMaoJogadores();

        }
    }


};

#endif // JOGO_H_INCLUDED
