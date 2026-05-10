#pragma once
#include <string>
#include <vector>
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "../modelos/astronauta/astronauta.hpp"
#include "../repositories/VooRepository/VooRepository.hpp"
#include "../modelos/voo/voo.hpp"

class FinalizarVooComSucessoUsecase
{
public:
    AstronautaRepository *astronautaRepository = NULL;
    VooRepository *vooRepository = NULL;

    FinalizarVooComSucessoUsecase(VooRepository *vooRepository, AstronautaRepository *astronautaRepository)
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

        if (v.estado_voo != "em curso")
        {
            return false;
        }

        for (int i = 0; i < v.lista_cpf.size(); i++)
        {
            std::vector<Astronauta> astronautas = astronautaRepository->getByCpf(v.lista_cpf[i]);
            
            Astronauta a = astronautas[0];

            a.disponivel = true;

            astronautaRepository->update(a);

        }

        v.estado_voo = "finalizado com sucesso";

        vooRepository->update(v);

        return true;
    }
};
