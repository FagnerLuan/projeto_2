#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include<string>
#include "no.h"

/// @file lista.h
/// Aquivo de implementação da lista encadeada.

/// @tparam T o tipo genérico para a classe Lista.
template<typename T>
/**
 * @class Lista lista.h "include/lista.h"
 * @brief Classe template que implementa uma lista encadeada.
*/
class Lista {
private:
    No<T>* cabeca; /**< Ponteiro para o primeiro elemento da lista */
    No<T>* cauda; /**< Ponteiro para o último elemento da lista */
    int tamanho; /**< Quantidade de elementos na lista */
    
public:
    /**
     * @brief Construtor
     * Não recebe parâmetros e inicializa seus campos.
     * Incializa cabeca e cauda com nullprt e tamanho com 0.
    */
    Lista() {
        this->cabeca = nullptr;
        this->cauda = nullptr;
        this->tamanho = 0;
    }

    /**
     * @brief Destrutor
     * Libera a memória alocada para os Nós.
    */
    ~Lista() {
        No<T>* noAtual = cabeca;
        while (noAtual != nullptr) {
            No<T>* proximo = noAtual->proximo;
            delete noAtual;
            noAtual = proximo;
        }
    }


    /**
     * @brief função que recupera o primeiro elemento da lista.
     * @retval No<T>*
     * @returns O primeiro elemento da lista.
    */
    No<T>* getCabeca() {
        return this->cabeca;
    }

    /**
     * @brief função para inserir um elemento na lista.
     * Esta função insere um elemento sempre no fim da lista.
     * @param elemento O elemento a ser inserido na lista.
     * @retval void
    */
    void inserir(const T& elemento) {
        No<T>* novoNo = new No<T>(elemento);

        if (cabeca == nullptr) {
            cabeca = novoNo;
            cauda = novoNo;
        } else {
            cauda->proximo = novoNo;
            cauda = novoNo;
        }
        tamanho++;
    }

    /**
     * @brief Insere um elemento na lista em uma determinada posição.
     * @param elemento O elemento a ser inserido na lista.
     * @param posicao A posição a inserir o elemento.
     * @retval void
    */
    void inserirNaPosicao(const T& elemento, int posicao) {
        No<T>* novoNo = new No<T>(elemento);
        if (posicao == 0) {
            novoNo->proximo = cabeca;
            cabeca = novoNo;
        } else {
            No<T> *noAtual = cabeca;
            for (int i = 0; i < posicao - 1; i++) {
                noAtual = noAtual->proximo;
            }

            novoNo->proximo = noAtual->proximo;
            noAtual->proximo = novoNo;
        }

        tamanho++;
    }

    /**
     * @brief função para remover um elemento da lista.
     * Essa função remove o elemento na posição passada pelo usuário.
     * @param index A posição do elemento a ser removido.
     * @retval void
    */
    void remover(int index) {
        if (cabeca == nullptr) {
            return;
        }

        if (index < 0 || index >= tamanho) {
            return;
        }

        // Caso queir remover o primeiro elemento.
        if (index == 0) {
            No<T>* noAtual = cabeca;
            cabeca = cabeca->proximo;
            delete noAtual;
            tamanho--;
            // Se havia apenas um elemento, atualiza a cauda.
            if (cabeca == nullptr) {
                cauda = nullptr;
            }
            return;
        }

        No<T>* noAtual = cabeca;

        // Percorro a lista até o nó anterior a ser removido para poder atualizar os nós na lista
        for (int i = 0; i < (index - 1); i++) {
            noAtual = noAtual->proximo;
        }

        No<T>* temp = noAtual->proximo;
        noAtual->proximo = temp->proximo;
        delete temp;
        tamanho--;
    }


    /**
     * @brief função para buscar um elemento na lista.
     * @param index O incide para buscar o elemento.
     * @retval bool
     * @return falso caso não haja elementos na lista ou o incide seja inválido ou verdadeiro caso contrario.
    */
    bool busca(int index) {
        if ( (cabeca == nullptr) || (index < 0 || index > tamanho) ) {
            return false;
        }

        No<T>* noAtual = cabeca;
        for (int i = 0; i < index; i++) {
            noAtual = noAtual->proximo;
        }

        return true;
    }

    /**
     * @brief função para acessar um elemento da lista.
     * Essa função acessa o elemento na posição passada pelo usuário.
     * @param index A posição do elemento a ser acessada.
     * @retval No<T>*
     * @return O no com o elemento na posição desejada caso o indice seja válido ou nullprt caso contrário.
    */
    No<T>* get(int index) {
        if (index < 0 || index >= tamanho) {
            return nullptr;
        }

        No<T>* noAtual = cabeca;
        for (int i = 0; i < index; i++) {
            noAtual = noAtual->proximo;
        }

        return noAtual;
    }
    
    /**
     * @brief função para verificar se a lista está vazia.
     * @retval bool
     * @return verdadeiro caso a lista esteja vazia, falso caso contrário.
    */
    bool estaVazia() {
        return (tamanho == 0);
    }

    /**
     * @brief função para recuperar o tamanho da lista.
     * @retval int
     * @return A quantidade de elementos na lista.
    */
    int size() const {
        return this->tamanho;
    }

};

#endif