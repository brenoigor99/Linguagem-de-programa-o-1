#pragma once
#include <string>
#include <vector>
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "../modelos/astronauta/astronauta.hpp"
#include "../repositories/VooRepository/VooRepository.hpp"
#include "../modelos/voo/voo.hpp"

class LancarVooUsecase
{
public:
    AstronautaRepository *astronautaRepository = NULL;
    VooRepository *vooRepository = NULL;

    LancarVooUsecase(VooRepository *vooRepository, AstronautaRepository *astronautaRepository)
    {
        this->vooRepository = vooRepository;
        this->astronautaRepository = astronautaRepository;
    }

    bool execute(int codigo)
    {
        if (vooRepository == NULL || astronautaRepository == NULL)
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
        std::vector<Astronauta> astronautasDoVoo;

        for (int i = 0; i < v.lista_cpf.size(); i++)
        {
            std::vector<Astronauta> astronautas = astronautaRepository->getByCpf(v.lista_cpf[i]);
            if (astronautas.size() == 0)
            {
                return false;
            }
            Astronauta a = astronautas[0];
            if (!a.vivo)
            {
                return false;
            }
            if (!a.disponivel)
            {
                return false;
            }
            astronautasDoVoo.push_back(a);
        }

        v.estado_voo = "em curso";

        vooRepository->update(v);

        for (int i = 0; i < astronautasDoVoo.size(); i++)
        {
            Astronauta a = astronautasDoVoo[i];
            a.disponivel = false;
            this->astronautaRepository->update(a);
        }

        return true;
    }
};
