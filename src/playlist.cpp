#include<iostream>
#include "playlist.h"

Playlist::Playlist(std::string nome) {
    musicas = new Lista<Musica>();
    this->nome = nome;
    proximaMusica = -1;
}

Playlist::Playlist(const Playlist& outra) {
    this->nome = outra.nome;
    this->musicas = outra.musicas;
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
void Playlist::adicionarMusica(Musica& musica) {
    musicas->inserir(musica);
}

void Playlist::adicionarMusicaNaPosicao(Musica& musica, int posicao) {
    musicas->inserirNaPosicao(musica, posicao);
}

// Remove uma musica da playlist
void Playlist::removerMusica(int index) {
    musicas->remover(index);
}

// Faz uma busca na playlist 
bool Playlist::busca(int index) {
    if (musicas->busca(index)) {
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
Lista<Musica> *Playlist::getMusicas() {
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

std::ostream& operator<<(std::ostream& saida, Playlist* playlist) {
    saida << playlist->nome;
    return saida;
}