#include<iostream>
#include "playlist.h"

Playlist::Playlist(std::string nome) {
    musicas = new Lista<Musica>();
    this->nome = nome;
    proximaMusica = -1;
}

Playlist::Playlist(Playlist& outra) {
    this->nome = outra.nome;
    musicas->adicionar(*outra.musicas);
    this->proximaMusica = outra.proximaMusica;
}

Playlist::Playlist() {
    musicas = new Lista<Musica>();
    this->nome = "Sem nome";
    proximaMusica = -1;
}

Playlist::~Playlist() {
    delete musicas;
}

// atribui um nome a uma playlist
void Playlist::setNome(std::string nome) {
    this->nome = nome;
}

// Adiciona uma musica na playlist
void Playlist::adicionar(Musica &musica) {
    musicas->inserir(musica);
}

// Versão sobrecarregada para dar suporte a ponteiros
void Playlist::adicionar(Playlist *playlist) {
    this->musicas->adicionar(playlist->getMusicas());
}

void Playlist::adicionar(Playlist &playlist) {
    Playlist *newPlaylist = playlist.toPointer();
    this->musicas->adicionar(newPlaylist->getMusicas());
    delete newPlaylist;
}

void Playlist::adicionarMusicaNaPosicao(Musica &musica, int posicao) {
    musicas->inserirNaPosicao(musica, posicao);
}

// Remove uma musica da playlist
void Playlist::remover(int index) {
    musicas->remover(index);
}

int Playlist::remover(Playlist& playlist) {
    Lista<Musica> *listaDeMusicas = playlist.getMusicas();
    return musicas->remover(*listaDeMusicas);   
}

// Faz uma busca na playlist 
bool Playlist::busca(int index) {
    return musicas->busca(index);
}

bool Playlist::busca(Musica &musica) {
    if (musicas->busca(musica) != -1) {
        return true;
    }

    return false;
}

// Retorna a proxima musica a na playlist
No<Musica>* Playlist::proximaATocar() {
    proximaMusica++;
    if (proximaMusica >= musicas->size()) {
        return nullptr;
    }

    return musicas->get(proximaMusica);
}

// Exibe as msuicas da playlist recursivamente
void Playlist::mostrarMusicas(int index) {
    if (index < musicas->size()) {
        std::cout << index << "-----" << musicas->get(index)->dado << std::endl;
        mostrarMusicas(index + 1);
    }
    
}

// Retorna a lista de musicas da playlist
Lista<Musica>* Playlist::getMusicas() {
    return this->musicas;
}

// Retorna o nome da playlist
std::string Playlist::getNome() const {
    return this->nome;
}

// Lista as musicas da playlist usando a função mostrarMusicas
void Playlist::listarMusicas() {
    std::cout << " ----- Musicas na Playlist " << nome <<  " ----- " << std::endl;
    mostrarMusicas(0);
}

bool Playlist::operator==(const Playlist& outra) {
    return this->nome == outra.nome;
}

std::ostream& operator<<(std::ostream& saida, Playlist *playlist) {
    saida << playlist->nome;
    return saida;
}

Playlist* Playlist::operator+(Playlist &outra) {
    Playlist *result = new Playlist();
    result->adicionar(*this);
    Lista<Musica> *listaDeMusicas = outra.musicas;
    for (int i = 0; i < listaDeMusicas->size(); i++) {
        Musica musica = listaDeMusicas->get(i)->dado;
        if (!busca(musica)) {
            result->adicionar(musica);
        }
    }

    return result;
}

Playlist* Playlist::operator+(Musica &musica) {
    Playlist *result = new Playlist();
    result->adicionar(*this);
    result->adicionar(musica);
    return result;
}

Playlist* Playlist::operator-(Playlist &outra) {
    Playlist *result = new Playlist();
    for (int i = 0; i < musicas->size(); i++) {
        Musica musica = musicas->get(i)->dado;
        if (!outra.busca(musica)) {
            result->adicionar(musica);
        }
    }

    return result;
}

Playlist* Playlist::operator-(Musica &musica) {
    Playlist *result = new Playlist();
    result->adicionar(*this);
    Lista<Musica> *listaDeMusicas = result->getMusicas();
    int indice = listaDeMusicas->busca(musica);
    
    if (indice != -1) {
        result->remover(indice);
    }

    return result;
}

void Playlist::operator>>(No<Musica> *musica) {
    if (musicas->estaVazia()) {
        musica = nullptr;
        return;
    }

    *musicas >> musica;
}

void Playlist::operator<<(No<Musica> *musica) {
    if (musica != nullptr) {
        Lista<Musica> *antiga = this->musicas;
        Lista<Musica> *nova = new Lista<Musica>();
        for (int i = 0; i < antiga->size(); i++) {
            nova->inserir(antiga->get(i)->dado);
        }
        delete musicas;
        *nova << musica;
        this->musicas = nova;
    }
}

// Retorna uma cópia da playlist atual como um ponteiro.
// Util para a função adicionar(Playlist &playlist).
Playlist* Playlist::toPointer() {
    Playlist *result = new Playlist();
    result->nome = this->nome;
    for (int i = 0; i < musicas->size(); i++) {
        result->adicionar(musicas->get(i)->dado);
    }

    return result;
}