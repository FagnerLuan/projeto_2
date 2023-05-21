#include<string>
#include "driver.h"

Driver::Driver() {
    sistema = Lista<Musica>();
    playlists = Lista<Playlist*>();
}

Driver::~Driver() {
    No<Playlist*> *noAtual = playlists.getCabeca();
    while (noAtual != nullptr) {
        No<Playlist*> *proximo = noAtual->proximo;
        delete noAtual->dado;
        noAtual = proximo;
    }
}

void Driver::cadastrarMusica(Musica& musica) {
    if (buscaMusica(musica, sistema) != -1) {
        std::cout << "Esta musica ja se encontra no sistema!" << std::endl;
    } else {
        std::cout << musica << " Cadastrada com sucesso!" << std::endl;
        sistema.inserir(musica);
    }
}

void Driver::removerDoSistema(int indice) {
    if (sistema.estaVazia()) {
        std::cout << "Nao ha musicas no sistema!" << std::endl;
        return;
    }

    if (indice < 0 || indice >= sistema.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        return;
    }

    Musica musica = sistema.get(indice)->dado;
    // buscando a musica em cada playlist
    for (int i = 0; i < playlists.size(); i++) {
        Playlist *playlist = playlists.get(i)->dado;
        Lista<Musica> *listaDeMusicas = playlist->getMusicas();
        int indice = buscaMusica(musica, listaDeMusicas);
        if (indice != -1) {
            playlist->remover(indice);
        }
    }

    std::cout << "Musica removida com sucesso!" << std::endl;
    sistema.remover(indice);
}

void Driver::listarMusicasDoSistema() {
    if (sistema.estaVazia()) {
        std::cout << "Nao ha musicas no sistema!" << std::endl;
        return;
    }

    std::cout << " ----- Musicas do Sistema ----- " << std::endl;
    for (int i = 0; i < sistema.size(); i++) {
        Musica musica = sistema.get(i)->dado;
        std::cout << i << " ----- " << musica << std::endl;
    }
}

int Driver::buscaMusica(const Musica &musica, Lista<Musica>& musicas) {
    for (int i = 0; i < musicas.size(); i++) {
        if (musicas.get(i)->dado == musica) {
            return i;
        }
    }

    return -1;
}

int Driver::buscaMusica(const Musica &musica, Lista<Musica> *musicas) {
    for (int i = 0; i < musicas->size(); i++) {
        if (musicas->get(i)->dado == musica) {
            return i;
        }
    }

    return -1;
}

int Driver::buscaPlaylist(Playlist *playlist) {
    for (int i = 0; i < playlists.size(); i++) {
        if (playlists.get(i)->dado == playlist) {
            return i;
        }
    }

    return -1;
}

void Driver::cadastrarPlaylist(Playlist *playlist) {
    if (buscaPlaylist(playlist) != -1) {
        std::cout << "Esta Playlist ja existe!" << std::endl;
    } else {
        std::cout << "Playlist cadastrada com sucesso!" << std::endl;
        playlists.inserir(playlist);
    }
}

void Driver::mostrarPlaylists() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist disponivel!" << std::endl;
        return;
    }

    std::cout << " ----- Playlists Disponiveis ----- " << std::endl;
    for (int i = 0; i < playlists.size(); i++) {
        Playlist *play = playlists.get(i)->dado;
        std::cout << i << " ----- " << play->getNome() << std::endl;
    }
}

void Driver::excluirPlaylist() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma playlist disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha uma Playlist pelo indice: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);

    if (indice < 0 || indice >= playlists.size()) {
        std::cout << "Operacao nao finalizada!" << std::endl;
        return;
    }

    std::cout << "Playlist removida com sucesso!" << std::endl;
    delete playlists.get(indice)->dado;
    playlists.remover(indice);
}

void Driver::adicionaUma() {
    if (sistema.estaVazia()) {
        std::cout << "Nenhuma musica disponivel no sistema!" << std::endl;
        return;
    }

    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }


    mostrarPlaylists();
    std::cout << "Escolha uma Playlist pelo indice: ";
    std::string input;
    std::getline(std::cin, input);
    int indicePlaylist = std::stoi(input);

    if (indicePlaylist < 0 || indicePlaylist >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    Playlist *play = playlists.get(indicePlaylist)->dado;

    listarMusicasDoSistema();
    std::cout << "Escolha o indice da musica para adicionar na playlist " << play << ": ";
    std::getline(std::cin, input);
    int indiceMusica = std::stoi(input);

    if (indiceMusica < 0 || indiceMusica >= sistema.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    Musica musica = sistema.get(indiceMusica)->dado;
    Musica novaMusica = Musica(musica.getTitulo(), musica.getArtista());
    play->adicionar(novaMusica);
    std::cout << "Musica adicionada com sucesso!" << std::endl;
}

void Driver::adicionaVarias() {
    if (sistema.estaVazia()) {
        std::cout << "Nenhuma musica disponivel no sistema!" << std::endl;
        return;
    }

    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha a primeira Playlist pelo indice: ";
    std::string input;
    std::getline(std::cin, input);
    int indicePlaylist1 = std::stoi(input);

    if (indicePlaylist1 < 0 || indicePlaylist1 >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha a segunda Playlist pelo indice: ";
    std::getline(std::cin, input);
    int indicePlaylist2 = std::stoi(input);

    if (indicePlaylist2 < 0 || indicePlaylist2 >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    if (indicePlaylist1 == indicePlaylist2) {
        return;
    }

    Playlist *playlist1 = playlists.get(indicePlaylist1)->dado;
    Playlist *playlist2 = playlists.get(indicePlaylist2)->dado;

    // TODO: Terminar de implementar

}

void Driver::adicionarMusicaEmPlaylist(bool flag) {
    adicionaUma();
}

void Driver::listarMusicasDaPlaylist() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist que deseja listar: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);

    if (indice < 0 || indice >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    Playlist *play = playlists.get(indice)->dado;
    if (play->getMusicas()->estaVazia()) {
        std::cout << "Playlist vazia!" << std::endl;
    } else {
        play->listarMusicas();
    }
}

void Driver::removerMusicaDaPlaylist() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indicePlaylist = std::stoi(input);

    if (indicePlaylist < 0 || indicePlaylist >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    Playlist *play = playlists.get(indicePlaylist)->dado;
    if (play->getMusicas()->estaVazia()) {
        std::cout << "Playlist vazia!" << std::endl;
        return;
    }

    play->listarMusicas();
    std::cout << "Escolha o indice da musica que deseja remover: ";
    std::getline(std::cin, input);
    int indiceMusica = std::stoi(input);

    if (indiceMusica < 0 || indiceMusica >= play->getMusicas()->size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    play->remover(indiceMusica);
    std::cout << "Musica removida com sucesso!" << std::endl;
}

void Driver::moverMusica() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }
    
    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);
    
    if (indice < 0 || indice >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *play = playlists.get(indice)->dado;
    if (play->getMusicas()->estaVazia()) {
        std::cout << "Playlist vazia!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    play->listarMusicas();
    std::cout << "Escolha o indice da musica: ";
    std::getline(std::cin, input);
    int indiceMusica = std::stoi(input);
    if (indiceMusica < 0 || indiceMusica >= play->getMusicas()->size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Musica musica = play->getMusicas()->get(indiceMusica)->dado;
    int tamanho = play->getMusicas()->size();
    Musica novaMusica = Musica(musica.getTitulo(), musica.getArtista());

    play->listarMusicas();
    std::cout << "Escolha a Nova posicao da musica(indice entre 0 e " << tamanho - 1 << "): ";
    std::getline(std::cin, input);
    int posicao = std::stoi(input);

    if (posicao < 0 || posicao >= tamanho) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    play->remover(indiceMusica);
    play->adicionarMusicaNaPosicao(novaMusica, posicao);
    std::cout << "Musica movida com sucesso!" << std::endl;
}

void Driver::reproduzirPlaylist() {
    if (playlists.estaVazia()) {
        std::cout << "Nenhuma Playlist Disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);

    if (indice < 0 || indice >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        return;
    }

    Playlist *play = playlists.get(indice)->dado;
    if (play->getMusicas()->estaVazia()) {
        std::cout << "Playlist vazia!" << std::endl;
        return;
    }

    std::string opcao = "";
    No<Musica> *musicaAtual = play->proximaATocar();
    if (musicaAtual == nullptr) {
        opcao = "N";
    }
    std::cout << "Reprduzindo " << play << std::endl;
    while (opcao != "N" && opcao != "n") {
        std::cout << "Faixa: " << musicaAtual->dado << std::endl;
        std::cout << "Tocar a Proxima?[s/n]: ";
        std::getline(std::cin, opcao);
        if (opcao == "s" || opcao == "S") {
            musicaAtual = play->proximaATocar();
        }

        if (musicaAtual == nullptr) {
            opcao = "N";
        }
    }

    std::cout << "Fim da playlist!" << std::endl;
}