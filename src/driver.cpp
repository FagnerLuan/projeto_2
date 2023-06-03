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

    if (entrada.is_open()) {
        entrada.close();
    }

    if (saida.is_open()) {
        saida.close();
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
        std::cout << i << " ----- " << play << std::endl;
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

    playlist1->adicionar(*playlist2);
    std::cout << "Musicas da playlist " << playlist2->getNome() << " adicionadas a playlist " << playlist1->getNome() << std::endl;

}

void Driver::adicionarMusicaEmPlaylist() {
    std::cout << "1 para adicionar uma musica" << std::endl;
    std::cout << "2 para adicionar varias musicas" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::string input;
    std::getline(std::cin, input);
    int opcao = std::stoi(input);

    while (opcao < 1 && opcao > 2) {
        std::cout << "Opção Invalida!";
        std::cout << "1 para adicionar uma musica" << std::endl;
        std::cout << "2 para adicionar varias musicas" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::getline(std::cin, input);
        opcao = std::stoi(input);
    }

    if (opcao == 1) {
        adicionaUma();
    } else {
        adicionaVarias();
    }
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

void Driver::removeUma() {
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

void Driver::removeVarias() {
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

    Playlist *playlist1 = playlists.get(indicePlaylist)->dado;
    if (playlist1->getMusicas()->estaVazia()) {
        std::cout << "Playlist vazia!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist com as musicas a remover: ";
    std::getline(std::cin, input);
    int indicePlaylist2 = std::stoi(input);

    if (indicePlaylist2 < 0 || indicePlaylist2 >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operação nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist2 = playlists.get(indicePlaylist)->dado;

    int removidas = playlist1->remover(*playlist2);
    std::cout << removidas << " musicas foram removidas da playlist " << playlist1->getNome() << std::endl;
}

void Driver::removerMusicaDaPlaylist() {
    std::cout << "1 para remover uma musica" << std::endl;
    std::cout << "2 para remover varias musicas" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::string input;
    std::getline(std::cin, input);
    int opcao = std::stoi(input);

    while (opcao < 1 && opcao > 2) {
        std::cout << "Opção Invalida!";
        std::cout << "1 para remover uma musica" << std::endl;
        std::cout << "2 para remover varias musicas" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::getline(std::cin, input);
        opcao = std::stoi(input);
    }

    if (opcao == 1) {
        removeUma();
    } else {
        removeVarias();
    }
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

int Driver::countChar(std::string texto, char c) {
    int count = 0;
    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] == c) {
            count++;
        }
    }
    
    return count;
}

Lista<std::string> Driver::split(std::string texto, char sep) {
    Lista<std::string> result = Lista<std::string>();
    std::string novoTexto = texto;

    if (novoTexto[0] == sep || novoTexto[novoTexto.length() - 1] == sep) {
        novoTexto = novoTexto.substr(1, novoTexto.length());
    }

    int times = countChar(texto, sep);

    if (times == 0) {
        result.inserir(novoTexto);
    } else if (times == 1) {
        for (int i = 0; i < novoTexto.length(); i++) {
            if (novoTexto[i] == sep) {
                std::string sub1 = novoTexto.substr(0, i);
                std::string sub2 = novoTexto.substr(i + 1, novoTexto.length());
                result.inserir(sub1);
                result.inserir(sub2);
            }
        }
    } else {
        int start = 0;
        int sCount = 0;
        int counter = 0;
        while (sCount < times) {
            if (novoTexto[counter] == sep) {
                std::string sub = novoTexto.substr(start, counter);
                result.inserir(sub);
                start = counter + 1;
                novoTexto = novoTexto.substr(start, novoTexto.length());
                sCount++;
            }
            counter++;
        }
        result.inserir(novoTexto);
    }

    return result;
}

void Driver::setup(std::string fileName) {
    setFilePath(fileName);
    entrada.open(this->filePath, std::ios::in);
    if (!entrada) {
        abort();
    }

    std::string linha;
    while (!entrada.eof()) {
        std::getline(entrada, linha);
        Lista<std::string> info = split(linha, ';');
        Playlist *playlist = new Playlist(info.get(0)->dado);
        cadastrarPlaylist(playlist);
        info.remover(0);
        Lista<std::string> musicas = split(info.get(0)->dado, ',');
        for (int i = 0; i < musicas.size(); i++) {
            Lista<std::string> musicaEArtista = split(musicas.get(i)->dado, ':');
            Musica musica = Musica(musicaEArtista.get(0)->dado, musicaEArtista.get(1)->dado);
            cadastrarMusica(musica);
            playlist->adicionar(musica);
        }
    }

    entrada.close();
}

void Driver::setFilePath(std::string path) {
    this->filePath = "../data/" + path;
}

void Driver::save() {
    saida.open(this->filePath,  std::ios::out);
    for (int i = 0; i < playlists.size(); i++) {
        Playlist *play = playlists.get(i)->dado;
        saida << play->getNome() << ';';
        Lista<Musica> *musicas = play->getMusicas();
        for (int j = 0; j < musicas->size(); j++) {
            Musica m = musicas->get(j)->dado;
            if (musicas->size() > 0) {
                if (j < musicas->size() - 1) {
                    saida << m.getTitulo() << ':' << m.getArtista() << ',';
                } else {
                    saida << m.getTitulo() << ':' << m.getArtista();
                }
            }
        }

        if (i < playlists.size() - 1) {
            saida << '\n';
        }
    }

    saida.close();

}

void Driver::unirPlaylists() {
    if (playlists.estaVazia()) {
        std::cout << "Sem playlists disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da primeira playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indicePlaylist1 = std::stoi(input);

    if (indicePlaylist1 < 0 || indicePlaylist1 > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist1 = playlists.get(indicePlaylist1)->dado;

    mostrarPlaylists();
    std::cout << "Escolha o indice da segunda playlist: ";
    std::getline(std::cin, input);
    int indicePlaylist2 = std::stoi(input);

    if (indicePlaylist2 < 0 || indicePlaylist2 > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist2 = playlists.get(indicePlaylist2)->dado;

    Playlist *uniao = *playlist1 + *playlist2;

    std::string nome;
    std::cout << "Escolha um nome para a nova playlist: ";
    std::getline(std::cin, nome);
    uniao->setNome(nome);
    cadastrarPlaylist(uniao);
}

void Driver::playlistComMusicaNoFim() {
    if (playlists.estaVazia()) {
        std::cout << "Sem playlists disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);

    if (indice < 0 || indice > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist = playlists.get(indice)->dado;

    listarMusicasDoSistema();
    std::cout << "Escolha o indice da musica a adicionar no fim da playlist: ";
    std::getline(std::cin, input);
    int indiceMusica = std::stoi(input);

    if (indiceMusica < 0 || indiceMusica > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Musica musica = sistema.get(indiceMusica)->dado;

    Playlist *novaPlaylist = *playlist + musica;

    std::string nome;
    std::cout << "Escolha um nome para a nova playlist: ";
    std::getline(std::cin, nome);
    novaPlaylist->setNome(nome);
    cadastrarPlaylist(novaPlaylist);
}

void Driver::diferencaEntrePlaylists() {
    if (playlists.estaVazia()) {
        std::cout << "Sem playlists disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da primeira playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indicePlaylist1 = std::stoi(input);

    if (indicePlaylist1 < 0 || indicePlaylist1 > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist1 = playlists.get(indicePlaylist1)->dado;

    mostrarPlaylists();
    std::cout << "Escolha o indice da segunda playlist: ";
    std::getline(std::cin, input);
    int indicePlaylist2 = std::stoi(input);

    if (indicePlaylist2 < 0 || indicePlaylist2 > playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist2 = playlists.get(indicePlaylist2)->dado;

    Playlist *diferenca = *playlist1 - *playlist2;

    std::string nome;
    std::cout << "Escolha um nome para a nova playlist: ";
    std::getline(std::cin, nome);
    diferenca->setNome(nome);
    cadastrarPlaylist(diferenca);
}

void Driver::playlistMenos() {
    if (playlists.estaVazia()) {
        std::cout << "Sem playlists disponivel!" << std::endl;
        return;
    }

    mostrarPlaylists();
    std::cout << "Escolha o indice da primeira playlist: ";
    std::string input;
    std::getline(std::cin, input);
    int indice = std::stoi(input);

    if (indice < 0 || indice >= playlists.size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Playlist *playlist = playlists.get(indice)->dado;

    playlist->listarMusicas();
    std::cout << "Escolha o indice da musica a remover: ";
    std::getline(std::cin, input);
    int indiceMusica = std::stoi(input);

    if (indiceMusica < 0 || indiceMusica >= playlist->getMusicas()->size()) {
        std::cout << "Indice Invalido!" << std::endl;
        std::cout << "Operacao nao concluida!" << std::endl;
        return;
    }

    Musica musica = playlist->getMusicas()->get(indiceMusica)->dado;
    Playlist *novaPlaylist = *playlist - musica;

    std::string nome;
    std::cout << "Escolha um nome para a nova playlist: ";
    std::getline(std::cin, nome);
    novaPlaylist->setNome(nome);
    cadastrarPlaylist(novaPlaylist);
}