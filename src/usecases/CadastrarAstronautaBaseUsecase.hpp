#pragma once
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include <string>
#include "../modelos/astronauta/astronauta.hpp"
#include <vector>

class CadastrarAstronautaBaseUsecase
{
public:
    AstronautaRepository *repository = NULL;

    CadastrarAstronautaBaseUsecase(AstronautaRepository *repository)
    {
        this->repository = repository;
    }

    bool execute(std::string cpf, int idade, std::string nome)
    {
        if (repository == NULL)
        {
            return false;
        }
        std::vector<Astronauta> astronautas = repository->getByCpf(cpf);
        if (astronautas.size() > 0)
        {
            return false;
        }
        Astronauta a(cpf, idade, nome, true, true);
        repository->save(a);
        
        return true;
    }
};