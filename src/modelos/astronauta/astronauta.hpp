#pragma once
#include <string>

class Astronauta
{
public:
    std::string cpf;
    int idade;
    std::string nome;
    bool vivo;
    bool disponivel;

    Astronauta() = default;

    Astronauta(std::string cpf, int idade, std::string nome, bool vivo, bool disponivel)
    {
        this->cpf = cpf;
        this->idade = idade;
        this->nome = nome;
        this->vivo = vivo;
        this->disponivel = disponivel;
    }
};