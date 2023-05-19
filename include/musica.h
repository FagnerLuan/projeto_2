#ifndef MUSICA_H
#define MUSICA_H
#include<iostream>
#include<string>

/// @file musica.h
/// Arquivo de definição da classe Musica.

/**
 * @brief Classe que representa uma música.
 * @class Musica musica.h "include/musica.h"
*/
class Musica {
private:
    std::string titulo; /**< O titulo da música.*/
    std::string artista; /**< O nome do(a) artista.*/

public:
    /**
     * @brief Construtor que recebe as informações da música.
     * @param titulo O titulo da música.
     * @param artista O nome do(a) artista.
    */
    Musica(std::string titulo, std::string artista);

    /**
     * @brief Construtor vazio.
     * Inicializa os atributos com strings vazias.
    */
    Musica();

    /**
     * @brief Destrutor.
     * simplismente exibe uma mensagem para o usuário.
    */
    ~Musica();

    /**
     * @brief função que recupera o título da música.
     * @retval std::string
     * @return O título da música.
    */
    std::string getTitulo() const;

    /**
     * @brief função que recupera o artista da música.
     * @retval std::string
     * @return O nome do(a) artista da música.
    */
    std::string getArtista() const;

    /**
     * @brief função para setar o titulo da musica.
     * @param titulo O novo titulo a ser definido.
     * @retval void
    */
    void setTitulo(std::string titulo);

    /**
     * @brief função para setar um(a) artista para a musica.
     * @param artista o(a) artista a ser a tribuido.
     * @retval void
    */
    void setArtista(std::string artista);

    /**
     * @brief Sobrecarga do operador == para obejetos musica.
     * @param outra A outra musica a comparar.
     * @retval bool
     * @return true caso as musicas sejam iguais, false caso contrario.
    */
    bool operator==(const Musica& outra);

    /**
     * @brief Sobrecarga do operador != para obejetos musica.
     * @param outra A outra musica a comparar.
     * @retval bool
     * @return true caso as musicas sejam diferentes, false caso contrario.
    */
    bool operator!=(const Musica& outra);

    /**
     * @brief Sobrecarrega o operador << para impressão de objetos Musica.
     * @param saida O stream de saída para qual as informações serão mandadas.
     * @param musica O obejeto musica a ser impresso.
     * @retval std::ostream
     * @return O stream de saída com as informações.
    */
    friend std::ostream& operator<<(std::ostream& saida, const Musica& musica);
};

#endif