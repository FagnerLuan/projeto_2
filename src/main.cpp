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
    std::cout << "9 ---- Excluir musica de uma playlist" << std::endl;
    std::cout << "10 --- Mover musica na playlist" << std::endl;
    std::cout << "11 --- Reproduzir uma playlist" << std::endl;
}


Playlist convert_from(Playlist* p) {
    Playlist res = Playlist("Teste");
    for (int i = 0; i < p->getMusicas()->size(); i++) {
        res.adicionar(p->getMusicas()->get(i)->dado);
    }

    return res;
}

void mostar_musicas(Lista<Musica> &lista) {
    for (int i = 0; i < lista.size(); i++) {
        std::cout << i << " ----- " << lista.get(i)->dado << std::endl;
    }
}

void testes() {
    Musica m1 = Musica("La ele", "Manoel");
    Musica m2 = Musica("Caneta azul", "Manoel");
    Musica m3 = Musica("Ai ai ai", "Manoel");
    Musica m4 = Musica("Ela e muito vagabunda", "Manoel");
    Musica m5 = Musica("So pra testar", "Luan");

    Playlist *p1 = new Playlist("Todas");
    Playlist *p2 = new Playlist("Adicionada");
    Playlist *p3 = new Playlist("Removida");

    //Lista<Musica> com_duas;
    //Lista<Musica> com_tres;
    //com_duas.inserir(m1);
    //com_duas.inserir(m2);
    //com_tres.inserir(m3);
    //com_tres.inserir(m4);
    //com_tres.inserir(m5);
//
    //Lista<Musica> todas = com_duas + com_tres;
//
    //std::cout << "com duas: " << std::endl;
    //mostar_musicas(com_duas);
    //std::cout << "com tres: " << std::endl;
    //mostar_musicas(com_tres);
    //std::cout << "todas: " << std::endl;
    //mostar_musicas(todas);

    p1->adicionar(m1);
    p1->adicionar(m2);
    p2->adicionar(m3);
    p2->adicionar(m4);
    p2->adicionar(m1);
    p3->adicionar(*p2);
//
    Playlist* copia(p2);
    p1->listarMusicas();
    p2->listarMusicas();
    copia->setNome("copia de p2");
    Playlist* copia_p2 = copia->toPointer();
    copia_p2->listarMusicas();
    //copia.listarMusicas();
    //p3->listarMusicas();

    Playlist* uniao = (*p1 + *p2);
    uniao->setNome("uniao");
    uniao->listarMusicas();

    delete p1;
    delete p2;
    delete p3;
    delete copia_p2;
    delete uniao;
}

int main(int argc, char* argv[]) {
    Driver driver;
    int opcao = -1;
    std::string input;
    bool flag = (argc > 1) ? true : false;

    testes();

    /*while (opcao != 0) {
        menu();
        std::cout << "Escolha uma opcao: ";
        std::getline(std::cin, input);
        opcao = stoi(input);

        switch (opcao) {
        case 0:
            std::cout << "Finalizando o Programa!" << std::endl;
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
            driver.adicionarMusicaEmPlaylist(flag);
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
        default:
            std::cout << "Opcao Invalida!" << std::endl;
        }
    }*/
}