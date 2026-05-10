#pragma once
#include <string>
#include <vector>
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "../modelos/astronauta/astronauta.hpp"
#include "../repositories/VooRepository/VooRepository.hpp"
#include "../modelos/voo/voo.hpp"
#include <iostream>

struct VooResumoDTO
{
    int codigo;
    std::string estado;
    // ListaDe{cpfAstronauta, nomeAstronauta}
    std::vector<Astronauta> astronautas;
};

class ListarVoosUsecase
{
public:
    AstronautaRepository *astronautaRepository = NULL;
    VooRepository *vooRepository = NULL;

    ListarVoosUsecase(VooRepository *vooRepository, AstronautaRepository *astronautaRepository)
    {
        this->vooRepository = vooRepository;
        this->astronautaRepository = astronautaRepository;
    }

    std::vector<VooResumoDTO> execute()
    {
        std::vector<VooResumoDTO> voosResumo;
        if (vooRepository == NULL || astronautaRepository == NULL)
        {
            return voosResumo;
        }
        std::vector<Voo> voosPlanejados = vooRepository->getByEstado("planejado");
        std::vector<Voo> voosEmCurso = vooRepository->getByEstado("em curso");
        std::vector<Voo> voosFinalizadosComSucesso = vooRepository->getByEstado("finalizado com sucesso");
        std::vector<Voo> voosFinalizadosComExplosao = vooRepository->getByEstado("finalizado com explosão");

        for (int i = 0; i < voosPlanejados.size(); i++)
        {
            Voo vooDaVez = voosPlanejados[i];
            VooResumoDTO vr;
            vr.codigo = vooDaVez.codigo_voo;
            vr.estado = vooDaVez.estado_voo;
            std::vector<Astronauta> astronautasDoVoo = astronautaRepository->getByListaCpf(vooDaVez.lista_cpf);
            vr.astronautas = astronautasDoVoo;
            voosResumo.push_back(vr);
            ///std::cout << "aaaaa\n";
        }

        for (int i = 0; i < voosEmCurso.size(); i++)
        {
            Voo vooDaVez = voosEmCurso[i];
            VooResumoDTO vr;
            vr.codigo = vooDaVez.codigo_voo;
            vr.estado = vooDaVez.estado_voo;
            std::vector<Astronauta> astronautasDoVoo = astronautaRepository->getByListaCpf(vooDaVez.lista_cpf);
            vr.astronautas = astronautasDoVoo;
            voosResumo.push_back(vr);
        }

        for (int i = 0; i < voosFinalizadosComSucesso.size(); i++)
        {
            Voo vooDaVez = voosFinalizadosComSucesso[i];
            VooResumoDTO vr;
            vr.codigo = vooDaVez.codigo_voo;
            vr.estado = vooDaVez.estado_voo;
            std::vector<Astronauta> astronautasDoVoo = astronautaRepository->getByListaCpf(vooDaVez.lista_cpf);
            vr.astronautas = astronautasDoVoo;
            voosResumo.push_back(vr);
        }

        for (int i = 0; i < voosFinalizadosComExplosao.size(); i++)
        {
            Voo vooDaVez = voosFinalizadosComExplosao[i];
            VooResumoDTO vr;
            vr.codigo = vooDaVez.codigo_voo;
            vr.estado = vooDaVez.estado_voo;
            std::vector<Astronauta> astronautasDoVoo = astronautaRepository->getByListaCpf(vooDaVez.lista_cpf);
            vr.astronautas = astronautasDoVoo;
            voosResumo.push_back(vr);
        }

        return voosResumo;
    }
};
