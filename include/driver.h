#ifndef DRIVER_H
#define DRIVER_H
#include<iostream>
#include "lista.h"
#include "musica.h"
#include "playlist.h"
///@file driver.h
/// Contém a definição da classe Driver.

/**
 * @brief Uma classe que gerencia as músicas do sistema e as playlists.
 * @class Driver driver.h "include/driver.h"
*/
class Driver {
private:
    Lista<Musica> sistema; /**< as musicas do sistema*/
    Lista<Playlist> playlists; /**< as playlists do usuário*/

public:
    /**
     * @brief Construtor padrão.
    */
    Driver();

    /**
     * @brief Destrutor.
     * Libera a memória alocada para as playlists.
    */
    ~Driver();

    /**
     * @brief Adiciona uma música no sistema.
     * @param musica A musica a ser cadastrada no sistema.
     * @retval void
    */
    void cadastrarMusica(const Musica musica);

    /**
     * @brief Remove uma música do sistema através de um índice.
     * @param indice O indice da música a ser removida.
     * @retval void
    */
    void removerDoSistema(int indice);

    /**
     * @brief Lista todas as musicas disponíveis no sistema.
     * @retval void
    */
    void listarMusicasDoSistema();

    /**
     * @brief Faz uma busca nas musicas e retorna o indice da musica na lista.
     * @param musica A musica a buscar no sistema.
     * @param musicas A lista com as músicas.
     * @retval int
     * @return O indice da musica caso estja no sistema, -1 caso a musica não esteja no sistema.
    */
    int buscaMusica(const Musica musica, Lista<Musica>& musicas);

    /**
     * @brief Faz uma busca nas musicas e retorna o indice da musica na lista.
     * Versão sobrecarregada de buscaMusica.
     * @param musica A musica a buscar no sistema.
     * @param musicas A lista com as musicas.
     * @retval int
     * @return O indice da musica caso estja no sistema, -1 caso a musica não esteja no sistema.
    */
    int buscaMusica(const Musica musica, Lista<Musica> *musicas);

    /**
     * @brief faz uma busca nas playlists e retorna o indice da playlist.
     * @param playlist A playlist buscada.
     * @retval int
     * @return O indice da playlist caso a playlist exista, -1 caso contrário.
    */
    int buscaPlaylist(Playlist& playlist);

    /**
     * @brief Cadastra uma Playlist no sistema.
     * @param playlist A playlist a ser adicionada no sistema.
     * @retval void
    */
    void cadastrarPlaylist(Playlist &playlist);

    /**
     * @brief Mostra as Playlists disponíveis.
     * @retval void
    */
    void mostrarPlaylists();

    /**
     * @brief Exclui uma playlist do sistema.
     * @retval void
    */
    void excluirPlaylist();

    /**
     * @brief Adiciona uma musica em uma playlist.
     * @retval void
    */
    void adicionarMusicaEmPlaylist(bool flag);

    /**
     * @brief Adiciona uma musica em uma playlist.
     * @retval void
    */
    void adicionaUma();

    /**
     * @brief Adiciona várias musicas em uma playlist.
     * @retval void
    */
    void adicionaVarias();

    /**
     * @brief Lista toas as musicas de uma Playlist.
     * @retval void
    */
    void listarMusicasDaPlaylist();

    /**
     * @brief Remove uma música de uma playlist.
     * @retval void
    */
    void removerMusicaDaPlaylist();

    /**
     * @brief Move uma musica de uma playlist.
     * A música será movida da posição atual para uma nova posição na playlist.
     * @retval void
    */
    void moverMusica();

    /**
     * @brief Reproduz uma playlist.
     * @retval void
    */
    void reproduzirPlaylist();
};
#endif