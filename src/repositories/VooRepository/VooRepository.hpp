#pragma once
#include "../../modelos/voo/voo.hpp"
#include <string>

class VooRepository
{
public:
std::vector<Voo> lista_voos;
    VooRepository();
    VooRepository(std::vector<Voo> lista_voos);

    bool save(Voo v);

    bool delete_(Voo v);

    bool update(Voo v);

    std::vector<Voo> getByCodigo(int codigo);

    std::vector<Voo> getByEstado(std::string estado);

    std::vector<Voo> getAll();
};



