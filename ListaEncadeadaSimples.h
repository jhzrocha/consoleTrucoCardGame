#ifndef LISTAENCADEADASIMPLES_H_INCLUDED
#define LISTAENCADEADASIMPLES_H_INCLUDED



struct ElementoEncadeadaSimples{
    Carta valor;
    ElementoEncadeadaSimples *prox = nullptr;
};

struct ListaEncadeadaSimples{
    ElementoEncadeadaSimples *inicio = nullptr;

    void iniciarLista(Carta carta){
        ElementoEncadeadaSimples *novo = new ElementoEncadeadaSimples();
        if (this->inicio == nullptr){
            this->inicio = novo;
            novo->prox = nullptr;
            novo->valor = carta;
        }
        std::cout << this->inicio << std::endl;
    }
    ElementoEncadeadaSimples* getPtrFinalLista(){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
        nav = this->inicio;

        while(nav->prox != nullptr){
            nav = nav->prox;
        }
        return nav;
    }
    void adicionarFim(Carta carta){
        ElementoEncadeadaSimples *novo = new ElementoEncadeadaSimples();
        ElementoEncadeadaSimples * ultimoElemento = this->getPtrFinalLista();
        ultimoElemento->prox = novo;
        novo->valor = carta;
    }
    void adicionarInicio(Carta carta){
        ElementoEncadeadaSimples *novo = new ElementoEncadeadaSimples();
        novo->prox = this->inicio;
        novo->valor = carta;
        this->inicio= novo;
    }
    int getQuantidadeElementos(){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
        nav = this->inicio;
        int contador = 0;
        while(nav != nullptr){
            contador++;
            nav = nav->prox;
        }
        return contador;
    }
    bool estaNaLista(Carta carta){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
        nav = this->inicio;

        while(nav != nullptr){
            Carta cartaNav = nav->valor;
            if(carta.valor == cartaNav.valor && carta.naipe == cartaNav.naipe){
                return true;
            }else{
                nav = nav->prox;

            }
        }
        return false;
    }
     int getIndexPosicao(Carta carta){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
        nav = this->inicio;
        int contador = 0;
        while(nav != nullptr){
            Carta cartaNav = nav->valor;
            if(carta.valor == cartaNav.valor && carta.naipe == cartaNav.naipe){
                return contador;
            }else{
                contador++;
                nav = nav->prox;
            }
        }
        return -1;
    }
    void adicionarNaPosicao(int posicao, Carta carta){
        ElementoEncadeadaSimples *novo = new ElementoEncadeadaSimples();
        ElementoEncadeadaSimples *nav,*proximo = new ElementoEncadeadaSimples();
        int maiorElemento = this->getQuantidadeElementos();

        if (posicao > (maiorElemento - 1)){
            std::cout << "Não é possível adicionar nesta posição" << std::endl;
        }else{
            int contador = 0;

            while (contador != posicao - 1){
                nav = nav->prox;
                contador++;
            }

            if(nav->prox != nullptr){
                novo->prox = nav->prox;
            }

            nav->prox = novo;
            novo->valor = carta;
        }
    }
     Carta getPorPosicao(int posicao){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
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

            return nav->valor;
        }
    }
    void removeInicio(){
        this->inicio = this->inicio->prox;
    }
    void removeFim(){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
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
        ElementoEncadeadaSimples *nav,*anterior = new ElementoEncadeadaSimples();
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
        }
    }
    void imprimirListaCartas(){
        ElementoEncadeadaSimples *nav = new ElementoEncadeadaSimples();
        nav = this->inicio;
        std::cout << "Valor , Naipe" << std::endl;
        while(nav != nullptr){

            std::cout << nav->valor.valor <<"   "<<nav->valor.naipe <<std::endl;
            nav = nav->prox;
       }
    }
};
#endif // LISTAENCADEADASIMPLES_H_INCLUDED
