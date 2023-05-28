#ifndef NO_H
#define NO_H
#include<iostream>

/// @file no.h
/// Aquivo com a implementação da classe No.

/// @tparam T O tipo genérico para a classe No.
template<typename T>
/**
 * @class No no.h "include/no.h"
 * @brief Classe template para ser um no de uma lista ligada.
*/
class No {
public:
    T dado; /**< O valor/dado armazenado no No.*/
    No* proximo; /**< O ponteiro de ligação para o proximo valor na lista.*/

    /**
     * @brief Construtor que recebe o valor a ser armazenado.
     * @param dado O valor que o No armazenará.
    */
    No(T dado) {
        this->dado = dado;
        this->proximo = nullptr;
    }
    /**
     * @brief Construtor que não recebe parametro.
    */
    No() {
        this->proximo = nullptr;
    }

    /**
     * @brief Destrutor.
    */
    ~No() {}
};


#endif