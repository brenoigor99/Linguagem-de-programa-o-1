#pragma once
#include "../repositories/VooRepository/VooRepository.hpp"
#include <string>
#include <vector>
#include "../modelos/voo/voo.hpp"

class CadastrarVooBaseUsecase
{
public:
    VooRepository *repository = NULL;

    CadastrarVooBaseUsecase(VooRepository *repository)
    {
        this->repository = repository;
    }

    bool execute(int codigo)
    {
        if (repository == NULL)
        {
            return false;
        }
        std::vector<Voo> voos = repository->getByCodigo(codigo);
        if (voos.size() > 0)
        {
            return false;
        }
        Voo v(codigo);
        repository->save(v);
        return true;
    }
};