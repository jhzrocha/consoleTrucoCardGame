#ifndef BARALHO_H_INCLUDED
#define BARALHO_H_INCLUDED

struct Baralho{
    Carta cartas[40];
    bool cartasEmbaralhadas[40];
    int quantidadeCartas = 0;



    void definirValor(Carta coringa){
        for(int i = 0; i < 40; i++){
            switch(cartas[i].valor){
            case 3:
                    cartas[i].valorHierarquico = 11;
                break;
            case 2:
                    cartas[i].valorHierarquico = 10;
                break;
            case 1:
                    cartas[i].valorHierarquico = 9;
                break;
            case 12:
                    cartas[i].valorHierarquico = 8;
                break;
            case 11:
                    cartas[i].valorHierarquico = 7;
                break;
            case 10:
                    cartas[i].valorHierarquico = 6;
                break;
            case 7:
                    cartas[i].valorHierarquico = 5;
                break;
            case 6:
                    cartas[i].valorHierarquico = 4;
                break;
            case 5:
                    cartas[i].valorHierarquico = 3;
                break;
            case 4:
                    cartas[i].valorHierarquico = 2;
                break;
            }
            for(int i = 0; i < 40; i++){
                if (coringa.valor != 3 && coringa.valor != 12 && coringa.valor != 7){
                        if(cartas[i].valor == coringa.valor + 1){
                            definirHierarquiaCoringa(cartas[i]);
                        }
                }
                if((coringa.valor == 3 && cartas[i].valor == 4)||(coringa.valor == 12 && cartas[i].valor == 1)||(coringa.valor == 7 && cartas[i].valor == 10)){
                    definirHierarquiaCoringa(cartas[i]);
                }
            }
        }
    }

    void definirHierarquiaCoringa(Carta carta){
        switch(carta.naipe){
            case 0:
                carta.valorHierarquico = 12;
                break;
            case 1:
                carta.valorHierarquico = 13;
                break;
            case 2:
                carta.valorHierarquico = 14;
                break;
            case 3:
                carta.valorHierarquico = 15;
                break;
        }
    }
    void iniciarCartasEmbaralhadas(){
        for(int i = 0; i <40 ; i++){
            cartasEmbaralhadas[i] = false;
        }
    }

    bool estaTodoEmbaralhado(){
        for(int i=0; i < 40; i++){
            if(cartasEmbaralhadas[i] == false){
                return false;
            }
        }
        return true;
    }
    void insereNoFim(int valor, int naipe){
        cartas[this->quantidadeCartas].valor = valor;
        cartas[this->quantidadeCartas].naipe = naipe;
        this->quantidadeCartas++;
    }
    void insereNoInicio(int valor, int naipe, int valorHierarquico){

        if(this->quantidadeCartas + 1 >= 40){
            std::cout << "Não é possível inserir, limite já alcançado!" << std::endl;
        }else{
            for(int i = this->quantidadeCartas; i != 0; i--){
                cartas[i] = cartas[i-1];
            }
            cartas[0].valor = valor;
            cartas[0].naipe = naipe;
            cartas[0].valorHierarquico = valorHierarquico;
            this->quantidadeCartas++;
        }
    }
    void zerarValoresPorPosicao(int posicao){
        cartas[posicao].valor = 0;
        cartas[posicao].naipe = 4;
        cartas[posicao].valorHierarquico = -1;
    }

    void inserePosicao(int valor, int naipe, int posicao){
        if(this->quantidadeCartas + 1 >= 40){
            std::cout << "Não é possível inserir, limite já alcançado!" << std::endl;
        }else{
            for(int i = this->quantidadeCartas; i != posicao; i--){
                cartas[i] = cartas[i-1];
            }
            cartas[posicao].valor = valor;
            cartas[posicao].naipe = naipe;
            this->quantidadeCartas++;
        }

    }
    void removeInicio(){
        for(int i = 0; i != this->quantidadeCartas; i++){
                cartas[i] = cartas[i+1];
        }
        this->quantidadeCartas--;
    }
    void removePosicao(int posicao){
        for(int i = this->quantidadeCartas; i != posicao; i--){
                cartas[i-1] = cartas[i];
        }
        this->quantidadeCartas--;
    }
    void removeFim(){
        this->quantidadeCartas--;
    }
    void inicializaBaralhoTruco(){
        for(int valorCarta = 1; valorCarta < 8; valorCarta++){
            for(int naipeCarta = 0 ; naipeCarta < 4; naipeCarta++){
                insereNoFim(valorCarta,naipeCarta);
            }
        }
        for(int valorCarta = 10; valorCarta < 13; valorCarta++){
            for(int naipeCarta = 0 ; naipeCarta < 4; naipeCarta++){
                insereNoFim(valorCarta,naipeCarta);
            }
        }
    }
    Carta obterCartaPorPosicao(int posicao){
        if( posicao > this->quantidadeCartas){
            std::cout << "Não existem cartas o suficiente" << std::endl;
        } else{
            return cartas[posicao];
        }
    }
    bool verificaCartaNoBaralho(int valor, int naipe){
        for(int i = 0; i < this->quantidadeCartas; i++){
            if(cartas[i].valor == valor && cartas[i].naipe== naipe){
                return true;
            }
        }
        return false;
    }
    int retornarIndexCarta(int valor, int naipe){
        for(int i = 0; i < this->quantidadeCartas; i++){
            if(cartas[i].valor == valor && cartas[i].naipe== naipe){
                return i;
            }
        }
        return -1;
    }
    void printAllCartas(){
        for(int i = 0; i < 40; i++){
            std::cout << cartas[i].valor << ", ";
            std::cout << cartas[i].naipe << std::endl;
        }
    }
};

#endif // BARALHO_H_INCLUDED
