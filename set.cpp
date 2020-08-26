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
    // TODO Implementação.

    for(unsigned int i = tamanho; i >= 0; i--){
        if(elemento == vetor[elemento]){
            return false;
        }
    }

     if(this->tamanho >= this->capacidade){
        this -> vetor = (int*) realloc (this -> vetor, sizeof(int) * (this -> capacidade * 2));

       if(!this->tamanho){ //caso nao tenha tamanho suficiente abandona a execução do programa
            return false;
        } else {
            this->capacidade = capacidade * 2;
            this->vetor[tamanho] = elemento;
            this->tamanho++;
       }
    }else{
        this->vetor[tamanho] = elemento; //caso o vetor tenha tamanho suficiente ele aloca o elemento e aumenta em 1 o tamanho
        this->tamanho++;
    }
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool set::remover(int elemento) {
    // TODO Implementação.

     if(this->tamanho == 0) return false;

    bool elementoPertence = pertence(elemento);
    unsigned int indiceDoElemento = 0;


        if(elementoPertence){ 
            for(int i = indiceDoElemento; i < this->tamanho; i++){
                this->vetor[i-1] = this->vetor[i];
            }
            this->tamanho--;
            return true;
        }

    return false;
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool set::pertence(int elemento) const {
    // TODO Implementação.

    for(unsigned int i = 0; i < this->tamanho; i++){
        if(vetor[i] == elemento){
            return true;
        }
    }
    return false;
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
void set::uniao_com(set const &conjunto) {
    // TODO Implementação.


}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void set::intersecao_com(set const &conjunto) {
    // TODO Implementação.
}

// Testar se este conjunto (`this`) está contido no outro informado.
bool set::esta_contido_em(set const &conjunto) const {
    // TODO Implementação.
}
