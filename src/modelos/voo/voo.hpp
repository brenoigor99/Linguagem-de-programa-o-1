#pragma once
#include <iostream>
#include <string>
#include <vector>

class Voo
{
public:
    int codigo_voo;
    std::vector<std::string> lista_cpf;
    std::string estado_voo = "planejado";

    Voo();
    Voo(int codigo_voo);
    int getQtdAstroCad(void);
    bool addCpf(std::string cpf);
    bool removerCpf(std::string cpf);
    bool verificarDuplicacaoCpf(std::string cpf);

};