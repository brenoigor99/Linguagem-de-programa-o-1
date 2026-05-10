#include "AstronautaRepository.hpp"

AstronautaRepository::AstronautaRepository() = default;

AstronautaRepository::AstronautaRepository(std::vector<Astronauta> lista_astronautas)
{
    this->lista_astronautas = lista_astronautas;
}

bool AstronautaRepository::save(Astronauta a)
{
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (a.cpf == this->lista_astronautas[i].cpf)
        {
            return false;
        }
    }
    this->lista_astronautas.push_back(a);

    return true;
}

bool AstronautaRepository::update(Astronauta a)
{
    int indice = -1;
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (this->lista_astronautas[i].cpf == a.cpf)
        {
            indice = i;
            break;
        }
    }
    if (indice != -1)
    {
        this->lista_astronautas[indice] = a;
        return true;
    }

    return false;
}

std::vector<Astronauta> AstronautaRepository::getByCpf(std::string cpf)
{
    std::vector<Astronauta> resultado;
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (cpf == lista_astronautas[i].cpf)
        {
            resultado.push_back(lista_astronautas[i]);
            break;
        }
    }
    return resultado;
}

std::vector<Astronauta> AstronautaRepository::getByDisponivel(bool diponivel)
{
    std::vector<Astronauta> resultado;
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (diponivel == lista_astronautas[i].disponivel)
        {
            resultado.push_back(lista_astronautas[i]);
        }
    }
    return resultado;
}

std::vector<Astronauta> AstronautaRepository::getByVivo(bool vivo)
{
    std::vector<Astronauta> resultado;
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (vivo == lista_astronautas[i].vivo)
        {
            resultado.push_back(lista_astronautas[i]);
        }
    }
    return resultado;
}

bool AstronautaRepository::delete_(Astronauta a)
{
    int indice = -1;
    for (int i = 0; i < this->lista_astronautas.size(); i++)
    {
        if (this->lista_astronautas[i].cpf == a.cpf)
        {
            indice = i;
            break;
        }
    }
    if (indice != -1)
    {
        this->lista_astronautas.erase(this->lista_astronautas.begin() + indice);
        return true;
    }
    return false;
}

std::vector<Astronauta> AstronautaRepository::getAll()
{
    return this->lista_astronautas;
}

std::vector<Astronauta> AstronautaRepository::getByListaCpf(std::vector<std::string> cpfs)
{
    std::vector<Astronauta> resultado;
    for (int i = 0; i < cpfs.size(); i++)
    {
        std::vector<Astronauta> astronautas = this->getByCpf(cpfs[i]);
        if (astronautas.size() == 1)
        {
            resultado.push_back(astronautas[0]);
        }
    }
    return resultado;
}
