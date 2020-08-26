#include "set.hpp"
#include <limits>
#include <algorithm>
#include <iostream>

// Construir lista vazia, mas com capacidade máxima informada.
set::set(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção.
// Retornar indicativo de sucesso da inserção.
// NOTE Deve aumentar a capacidade caso necessário.
// NOTE Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool set::inserir(int elemento) {

    bool elementoJaInserido = pertence(elemento);
    
    if(!elementoJaInserido){

        if(this->tamanho < this->capacidade){
            this->vetor[tamanho] = elemento; //caso o vetor tenha tamanho suficiente ele aloca o elemento e aumenta em 1 o tamanho
            this->tamanho++;

            return true;
        }

        if(this->tamanho >= this->capacidade){
        this -> vetor = (int*) realloc (this -> vetor, sizeof(int) * (this -> capacidade * 2));

            if(!this->tamanho){ //caso nao tenha tamanho suficiente abandona a execução do programa
                return false;
            } else {
                this->capacidade = capacidade * 2;
                this->vetor[tamanho] = elemento;
                this->tamanho++;

                return true;
            }
        }else{
            this->vetor[tamanho] = elemento; //caso o vetor tenha tamanho suficiente ele aloca o elemento e aumenta em 1 o tamanho
            this->tamanho++;

            return true;
        }

    }else{
       return false;
    }

    
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool set::remover(int elemento) {

    if (this->tamanho == 0){
        return false;
    }

    bool elementoPertence = pertence(elemento);

        if(elementoPertence){
            for(unsigned int i = 0; i < this->tamanho; i++){
                if(vetor[i] == elemento){
                     for (unsigned int indiceRemovido = i; indiceRemovido < this->tamanho; indiceRemovido++) {
                       vetor[indiceRemovido] = vetor[indiceRemovido + 1];
                }
                this->tamanho--;
                return true;
            }
        }
        
    }else{
        return false;
    }
    return false;
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool set::pertence(int elemento) const {

    if(this->tamanho == 0){
       return false;
    }

    for(unsigned int i = 0; i < this->tamanho; i++){
        if(this->vetor[i] == elemento){
            return true;
        }
    }

    return false;
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
void set::uniao_com(set const &conjunto) {


    bool elementoPertenceConjunto;

        for(unsigned int conjuntoA = 0; conjuntoA < this->tamanho; conjuntoA++){
            for(unsigned int conjuntoB = 0; conjuntoB < conjunto.tamanho; conjuntoB++){
                if(vetor[conjuntoA] != conjunto.vetor[conjuntoB]){
                    this->inserir(conjunto.vetor[conjuntoB]);

                }
            }
        }

}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void set::intersecao_com(set const &conjunto) {
    if(conjunto.tamanho == 0){
        return;
    }

    unsigned int *vetorAuxiliar = new unsigned int[tamanho];

    for(unsigned int valorA = 0; valorA < this->tamanho ; valorA++){
        for(unsigned int valorB = 0; valorB < conjunto.tamanho; valorB++){
            if(this->vetor[valorA] == conjunto.vetor[valorB]){
                for(int k = 0; k < this->tamanho; k++){
                    vetorAuxiliar[k] = this->vetor[valorA];
                }
            }
        }
    }

}

// Testar se este conjunto (`this`) está contido no outro informado.
bool set::esta_contido_em(set const &conjunto) const {

    if (conjunto.tamanho == 0) {
        return true;
    }

        for(unsigned int i = 0; i < this->tamanho; i++){
            if(pertence(conjunto.vetor[i])){
                return true;
            }
        }
    return false;
}
