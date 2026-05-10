#pragma once
#include <string>
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "../modelos/astronauta/astronauta.hpp"
#include "../repositories/VooRepository/VooRepository.hpp"
#include "../modelos/voo/voo.hpp"

class RemoverAstronautaVoo
{
public:
    AstronautaRepository *astronautaRepository = NULL;
    VooRepository *vooRepository = NULL;

    RemoverAstronautaVoo(AstronautaRepository *astronautaRepository, VooRepository *vooRepository)
    {
        this->astronautaRepository = astronautaRepository;
        this->vooRepository = vooRepository;
    }

    bool execute(std::string cpf, int codigo)
    {
        if (astronautaRepository == NULL)
        {
            return false;
        }
        std::vector<Astronauta> astronautas = astronautaRepository->getByCpf(cpf);
        if (astronautas.size() == 0)
        {
            return false;
        }
        Astronauta a = astronautas[0];

        if (vooRepository == NULL)
        {
            return false;
        }
        std::vector<Voo> voos = vooRepository->getByCodigo(codigo);
        if (voos.size() == 0)
        {
            return false;
        }
        Voo v = voos[0];

        if (v.estado_voo != "planejado")
        {
            return false;
        }

        if (!v.verificarDuplicacaoCpf(a.cpf))
        {
            return false;
        }

        v.removerCpf(a.cpf);

        this->vooRepository->update(v);

        return true;
    }
};