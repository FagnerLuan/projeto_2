#include<iostream>
#include<cstring>
#include "musica.h"

// Construtor recebe o titulo e o artista da musica
Musica::Musica(std::string titulo, std::string artista) {
    this->titulo = titulo;
    this->artista = artista;
}

Musica::Musica() {
    this->titulo = "";
    this->artista = "";
}

Musica::~Musica() {}

// Retorna o titulo da muisca
std::string Musica::getTitulo() const {
    return this->titulo;
}

// Retorna o artista
std::string Musica::getArtista() const {
    return this->artista;
}

void Musica::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void Musica::setArtista(std::string artista) {
    this->artista = artista;
}

bool Musica::operator==(const Musica& outra) {
    std::string tituloMusicaAtual = "";
    std::string tituloOutraMusica = "";
    std::string artistaMusicaAtual = "";
    std::string artistaOutraMusica = "";

    for (auto l : this->titulo) {
        tituloMusicaAtual += tolower(l);
    }

    for (auto l : outra.getTitulo()) {
        tituloOutraMusica += tolower(l);
    }

    for (auto l : this->artista) {
        artistaMusicaAtual += tolower(l);
    }

    for (auto l : outra.getArtista()) {
        artistaOutraMusica += tolower(l);
    }

    return (tituloMusicaAtual == tituloOutraMusica && artistaMusicaAtual == artistaOutraMusica);
}

bool Musica::operator!=(const Musica& outra) {
    std::string tituloMusicaAtual = "";
    std::string tituloOutraMusica = "";
    std::string artistaMusicaAtual = "";
    std::string artistaOutraMusica = "";

    for (auto l : this->titulo) {
        tituloMusicaAtual += tolower(l);
    }

    for (auto l : outra.getTitulo()) {
        tituloOutraMusica += tolower(l);
    }

    for (auto l : this->artista) {
        artistaMusicaAtual += tolower(l);
    }

    for (auto l : outra.getArtista()) {
        artistaOutraMusica += tolower(l);
    }

    return (tituloMusicaAtual != tituloOutraMusica && artistaMusicaAtual != artistaOutraMusica);
}

std::ostream& operator<<(std::ostream& saida, const Musica& musica) {
    saida << musica.getArtista() << ", " << musica.getTitulo();
    return saida;
}