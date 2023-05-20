#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<iostream>
#include<string>
#include "lista.h"
#include "musica.h"

/// @file playlist.h
/// Aquivo de definição da classe Playlist.

/**
 * @class Playlist playlist.h "include/playlist.h"
 * @brief Uma classe que representa uma playlist
*/
class Playlist {
private:
    std::string nome; /**< O nome da Playlist */
    Lista<Musica> musicas; /**< Uma lista com as músicas da playlist */
    int proximaMusica; /**< A próxima música a ser reproduzida */

public:
    /**
     * @brief Construtor que recebe o nome da playlist.
     * Inicializa o campo nome com o parâmetro nome, *musicas com new Lista<Musica>() e proximaMusica com 0.
     * @param nome O nome da playlist.
    */
    Playlist(std::string nome);

    /**
     * @brief Construtor padrão que inicializa os campos com valores padrão.
     * Inicializa nome com uma string "Sem nome", *musicas com new Lista<Musica>() e proximaMusica com 0.
    */
    Playlist();

    /**
     * @brief Construtor de cópia.
     * Incializa os campos com os valores dos campos de outra.
     * @param outra A outra playlist que será copiada.
    */
    Playlist(const Playlist& outra);

    /**
     * @brief Destrutor.
     * O destrutor libera a memória alocada para *musicas.
    */
    virtual ~Playlist();

    /**
     * @brief função para setar o nome da playlist.
     * @param nome O nome a ser atribuido para a playlist.
     * @retval void
    */
    void setNome(std::string nome);

    /**
     * @brief função para adicionar uma música na playlist.
     * @param musica a música a ser adicionada na playlist.
     * @retval void
    */
    void adicionar(Musica& musica);

    /**
    * @brief Adiciona várias músicas em uma playlist.
    * @param playlist A playlist com as músicas a ser adicionada.
    * @retval void
   */
    void adicionar(Playlist& playlist);

    /**
     * @brief Adiciona uma musica na playlist na posicao desejada.
     * @param musica A música a ser adicionada na playlist.
     * @param posicao A posicao a adicionar a música.
     * @retval void
    */
    void adicionarMusicaNaPosicao(Musica& musica, int posicao);

    /**
     * @brief função para remover uma música da playlist.
     * Remove a música da playlist na posição desejada.
     * @param index A posição da música a ser removida.
     * @retval void
    */
    void remover(int index);

    /**
     * @brief Remove várias músicas de uma playlist.
     * @param playlist A playlist com as musicas a serem removidas.
     * @retval int
     * @return O número de elementos remmovidos da playlist.
    */
    int remover(Playlist& playlist);

    /**
     * @brief função para buscar uma música na playlist.
     * @param index O indice da música a se buscar.
     * @retval bool
     * @return verdadeiro caso o indice seja válido, falso caso contrário.
    */
    bool busca(int index);

    /**
     * @brief Faz uma busca por uma música na playlist.
     * @param musica A música buscada.
     * @retval bool
     * @return true caso a musica se encontre na playlist, false caso contrario.
    */
    bool busca(const Musica &musica);

    /**
     * @brief função que retorna a próxima musica na playlist.
     * @retval No<Musica>*
     * @return O nó com a proxima música na playlist, ou nullprt caso não haja mais músicas na playlist.
    */
    No<Musica> *proximaATocar();

    /**
     * @brief função para mostrar todas as músicas disponíveis na playlist.
     * Essa função mostra todas as músicas disponíveis na playlist de forma recursiva.
     * @param index O indice da música inicial.
     * @retval void
    */
    void mostrarMusicas(int index);

    /**
     * @brief função que recupera a lista de musicas da playlist.
     * @retval Lista<Musica>*
     * @return A lista com as músicas da playlist.
    */
    Lista<Musica> getMusicas();

    /**
     * @brief função que recupera o nome da playlist.
     * @retval std::string
     * @return O nome da playlist.
    */
    std::string getNome() const;

    /**
     * @brief função que lista todas as músicas na playlist.
     * Essa função lista as músicas da playlist. Ela usa a função mostrarMusicas.
     * @retval void
    */
    void listarMusicas();

    /**
     * @brief Sobrecarga do operdor ==
     * Usado para comparar a igualdade entre duas playlists
    */
    bool operator==(const Playlist& outra);

   /**
    * @brief Sobrecarga do operador << para impressão de objetos Playlist.
    * @param saida O stream de saída para qual as informações serão mandadas.
    * @param playlist A playlist a ser impressa.
    * @retval std::ostream
    * @return O stream de saída com as informações.
   */
   friend std::ostream& operator<<(std::ostream& saida, Playlist& playlist);

   /**
    * @brief Sobrecarga do operador + para realizar a união entre duas playlists.
    * @param outra A segunda playlist da união.
    * @retval Playlist
    * @return Uma nova playlist a partir da união das duas primeiras.
   */
    Playlist operator +(Playlist &outra);

    /**
    * @brief Sobrecarga do operador + para adicionar uma música no final da playlist.
    * @param musica A música a ser adicionada.
    * @retval Playlist
    * @return Uma nova playlist com a nova música no final.
   */
    Playlist operator +(Musica &musica);

    /**
     * @brief Sobrecarga do operador - para realizar a diferença entre duas playlists.
     * @param outra A segunda playlist da operação.
     * @retval Playlist
     * @return Uma nova playlist resultante da operação.
    */
    Playlist operator -(Playlist &outra);

    /**
     * @brief Sobrecarga do operador - para remover uma música da playlist.
     * @param musica A música a ser removida.
     * @retval Playlist
     * @return Uma nova playlist sem a música removida.
    */
    Playlist operator -(Musica &musica);

    /**
     * @brief Sobrecarga do operador >> para extrair a última música da playlist.
     * @param musica O que receberá a música extraida.
     * @retval void
    */
    void operator >>(No<Musica> *musica);

    /**
     * @brief Sobrecarga do operador << para adicionar uma música no fim da playlist.
     * @param musica O no com a música a ser adicionada.
     * @retval void
    */
    void operator <<(No<Musica> *musica);
};

#endif