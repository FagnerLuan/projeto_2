#include<string>
#include "driver.h"

/**
 * @brief Exibe o menu de opções do sistema.
 * @retval void
*/
void menu() {
    std::cout << " ----- Menu de Opcoes ----- " << std::endl;
    std::cout << "0 ---- Finalizar Programa!" << std::endl;
    std::cout << "1 ---- Cadastrar Musica no Sistema" << std::endl;
    std::cout << "2 ---- Listar Musicas do Sistema" << std::endl;
    std::cout << "3 ---- Excluir Musica do Sistema" << std::endl;
    std::cout << "4 ---- Cadastrar Plalist" << std::endl;
    std::cout << "5 ---- Mostar Playlists Disponiveis" << std::endl;
    std::cout << "6 ---- Excluir uma Playlist" << std::endl;
    std::cout << "7 ---- Adicionar musicas em uma playlist" << std::endl;
    std::cout << "8 ---- Listar as musicas de uma playlist" << std::endl;
    std::cout << "9 ---- Excluir musicas de uma playlist" << std::endl;
    std::cout << "10 --- Mover musica na playlist" << std::endl;
    std::cout << "11 --- Reproduzir uma playlist" << std::endl;
    std::cout << "12 --- Unir Playlists" << std::endl;
    std::cout << "13 --- Adicionar musica no fim da playlist" << std::endl;
    std::cout << "14 --- Diferenca enrtre playlists" << std::endl;
}

int main(int argc, char* argv[]) {
    Driver driver;
    int opcao = -1;
    std::string input;
    bool flag = (argc > 1) ? true : false;


    if (flag) {
        driver.setup();
    }

    while (opcao != 0) {
        menu();
        std::cout << "Escolha uma opcao: ";
        std::getline(std::cin, input);
        opcao = stoi(input);

        switch (opcao) {
        case 0:
            std::cout << "Finalizando o Programa!" << std::endl;
            std::cout << "Salvando Informaçoes..." << std::endl;
            driver.save();
            break;
        case 1:
            {
                std::string titulo;
                std::string artista;
                std::cout << "Titulo da musica: ";
                std::getline(std::cin, titulo);
                std::cout << "Arista: ";
                std::getline(std::cin, artista);
                
                Musica musica = Musica(titulo, artista);
                driver.cadastrarMusica(musica);
            }
            break;
        case 2:
            driver.listarMusicasDoSistema();
            break;
        case 3:
            {
                driver.listarMusicasDoSistema();
                std::cout << "Escolha A Musica pelo Indice: ";
                std::getline(std::cin, input);
                int indice = stoi(input);
                driver.removerDoSistema(indice);
            }
            break;
        case 4:
            {
                std::string nome;
                std::cout << "Nome da Playlist: ";
                std::getline(std::cin, nome);
                Playlist *playlist = new Playlist(nome);
                driver.cadastrarPlaylist(playlist);
            }
            break;
        case 5:
            driver.mostrarPlaylists();
            break;
        case 6:
            driver.excluirPlaylist();
            break;
        case 7:
            driver.adicionarMusicaEmPlaylist();
            break;
        case 8:
            driver.listarMusicasDaPlaylist();
            break;
        case 9:
            driver.removerMusicaDaPlaylist();
            break;
        case 10:
            driver.moverMusica();
            break;
        case 11:
            driver.reproduzirPlaylist();
            break;
        case 12:
            driver.unirPlaylists();
            break;
        case 13:
            driver.playlistComMusicaNoFim();
            break;
        case 14:
            driver.diferencaEntrePlaylists();
            break;
        default:
            std::cout << "Opcao Invalida!" << std::endl;
        }
    }

    return 0;
}