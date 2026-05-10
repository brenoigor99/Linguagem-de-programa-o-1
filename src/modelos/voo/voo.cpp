#include "voo.hpp"

Voo::Voo() = default;
Voo::Voo(int codigo_voo)
{
    this->codigo_voo = codigo_voo;
    this->estado_voo = "planejado";
};
int Voo::getQtdAstroCad(void)
{
    return this->lista_cpf.size();
}
bool Voo::addCpf(std::string cpf)
{
    if (this->verificarDuplicacaoCpf(cpf))
    {
        return false;
    }

    this->lista_cpf.push_back(cpf);

    return true;
}
bool Voo::removerCpf(std::string cpf)
{
    int indice_cpf = -1;
    for (int i = 0; i < this->lista_cpf.size(); i++)
    {
        if (this->lista_cpf[i] == cpf)
        {
            indice_cpf = i;
        }
    }
    if (indice_cpf != -1)
    {
        this->lista_cpf.erase(this->lista_cpf.begin() + indice_cpf);
        return true;
    }

    return false;
}
bool Voo::verificarDuplicacaoCpf(std::string cpf)
{
    for (int i = 0; i < this->lista_cpf.size(); i++)
    {
        if (this->lista_cpf[i] == cpf)
        {
            return true;
        }
    }
    return false;
}
