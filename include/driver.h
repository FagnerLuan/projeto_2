#ifndef DRIVER_H
#define DRIVER_H
#include<iostream>
#include<fstream>
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
    Lista<Playlist*> playlists; /**< as playlists do usuário*/
    std::ifstream entrada; /** stream para a leitura de arquivos*/
    std::ofstream saida; /** stream para a escrita em arquivos*/
    std::string filePath; /** caminho do aquivo para leitura e escrita*/

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
    void cadastrarMusica(Musica &musica);

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
     * @param musica A musica a ser buscada.
     * @param musicas A lista com as músicas.
     * @retval int
     * @return O indice da musica caso estja no sistema, -1 caso a musica não esteja no sistema.
    */
    int buscaMusica(const Musica &musica, Lista<Musica>& musicas);

    /**
     * @brief Faz uma busca nas musicas e retorna o indice da musica na lista.
     * Versão sobrecarregada de buscaMusica.
     * @param musica A musica a ser buscada.
     * @param musicas A lista com as musicas.
     * @retval int
     * @return O indice da musica caso estja no sistema, -1 caso a musica não esteja no sistema.
    */
    int buscaMusica(const Musica &musica, Lista<Musica> *musicas);

    /**
     * @brief faz uma busca nas playlists e retorna o indice da playlist.
     * @param playlist A playlist buscada.
     * @retval int
     * @return O indice da playlist caso a playlist exista, -1 caso contrário.
    */
    int buscaPlaylist(Playlist *playlist);

    /**
     * @brief Cadastra uma Playlist no sistema.
     * @param playlist A playlist a ser adicionada no sistema.
     * @retval void
    */
    void cadastrarPlaylist(Playlist *playlist);

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
    void adicionarMusicaEmPlaylist();

    

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

    /**
     * @brief Faz a configuração incicial para a lista de música do sistema e as playlists a partir do arquivo
     * @retval void
    */
    void setup(std::string fileName);

    /**
     * @brief Seta o campo filePath para leitura e escrita em arquivo
     * @retval void
    */
    void setFilePath(std::string path);

    /**
     * @brief Salva os dados atuais no arquivo.
     * @retval void
    */
    void save();

    /**
     * @brief Faz a união entre duas playlists.
     * @retval void
    */
    void unirPlaylists();

    /**
     * @brief Cria uma nova playlist com uma musica nova no final.
     * @retval void
    */
    void playlistComMusicaNoFim();

    /**
     * @brief Faz a diferença entre duas playlists.
     * @retval void
    */
    void diferencaEntrePlaylists();

    /**
     * @brief Cria uma nova playlist sem uma determinada musica.
     * @retval void
    */
    void playlistMenos();

private:

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
     * @brief Remove uma música de uma playlist.
     * @retval void
    */
    void removeUma();

    /**
     * @brief Remove várias músicas de uma playlist.
     * @retval void
    */
    void removeVarias();


    /**
     * @brief Conta a quantidade de vezes que um caracter aparece em uma string.
     * @param texto O texto onde procuramos o caracter.
     * @param c O caracter procurado.
     * @retval int
     * @return O número de vezes que o caracter aparece no texto.
    */
    int countChar(std::string texto, char c);

    /**
     * @brief Separa uma string em varias a partir de um separador.
     * @param texto O texto a ser quebrado.
     * @param sep O caracter separador.
     * @retval Lista<std::string>
     * @return Uma lista com os textos separados.
    */
    Lista<std::string> split(std::string texto, char sep);
};
#endif