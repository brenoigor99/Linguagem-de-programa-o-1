#include <iostream>
#include <string>
#include <vector>
#include "repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "repositories/VooRepository/VooRepository.hpp"
#include "usecases/AdicionaAstronautaVooUsecase.hpp"
#include "usecases/CadastrarAstronautaBaseUsecase.hpp"
#include "usecases/CadastrarVooBaseUsecase.hpp"
#include "usecases/RemoverAstronautaVoo.hpp"
#include "usecases/ExplodirVooUsecase.hpp"
#include "usecases/FinalizarVooComSucessoUsecase.hpp"
#include "usecases/LancarVooUsecase.hpp"
#include "usecases/ListarAstronautasMortosUsecase.hpp"
#include "usecases/ListarVoosUsecase.hpp"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
using namespace std;

int main()
{
    AstronautaRepository astronautaRepository;
    VooRepository vooRepository;

    AdicionaAstronautaVooUsecase adicionaAstronautaVooUsecase(&astronautaRepository, &vooRepository);
    CadastrarAstronautaBaseUsecase cadastrarAstronautaBaseUsecase(&astronautaRepository);
    CadastrarVooBaseUsecase cadastrarVooBaseUsecase(&vooRepository);
    RemoverAstronautaVoo removerAstronautaVoo(&astronautaRepository, &vooRepository);
    ExplodirVooUsecase explodirVooUsecases(&vooRepository, &astronautaRepository);
    FinalizarVooComSucessoUsecase finalizarVooComSucessoUsecase(&vooRepository, &astronautaRepository);
    LancarVooUsecase lancarVooUsecase(&vooRepository, &astronautaRepository);
    ListarAstronautasMortosUsecase listarAstronautasMortosUsecase(&astronautaRepository);
    ListarVoosUsecase listarVoosUsecase(&vooRepository, &astronautaRepository);

    string comando;

    while (cin >> comando)
    {
        if (comando == "FIM")
        {
            break;
        }
        if (comando == "CADASTRAR_ASTRONAUTA")
        {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            bool succ = cadastrarAstronautaBaseUsecase.execute(cpf, idade, nome);
            if(succ){
                cout << GREEN << "Astronauta " << YELLOW << nome << GREEN << " cadastrado com sucesso!\n" << RESET;
                cout << GREEN << "    Cpf: " << YELLOW << cpf << "\n" << GREEN << RESET;
                cout << GREEN << "    Idade: " << YELLOW << idade << "\n" << GREEN << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "CADASTRAR_VOO")
        {
            int codigo;
            cin >> codigo;
            bool succ = cadastrarVooBaseUsecase.execute(codigo);
            if(succ){
                cout << GREEN << "Voo: " << YELLOW << codigo << GREEN << " Cadastrado com sucesso!\n" << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "ADICIONAR_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            bool succ = adicionaAstronautaVooUsecase.execute(cpf, codigo);
            if(succ){
                cout << GREEN << "Astronauta " << YELLOW << cpf << GREEN << " Adicionado com sucesso!\n" << RESET;
                cout << GREEN << "    Voo: " << YELLOW << codigo << "\n" << GREEN << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "REMOVER_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf;
            cin >> codigo;
            bool succ = removerAstronautaVoo.execute(cpf, codigo);
            if(succ){
                cout << GREEN << "Astronauta " << YELLOW << cpf << GREEN << " Removido com sucesso!\n" << RESET;
                cout << GREEN << "    Voo: " << YELLOW << codigo << "\n" << GREEN << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "LANCAR_VOO")
        {
            int codigo;
            cin >> codigo;
            bool succ = lancarVooUsecase.execute(codigo);
            if(succ){
                cout << GREEN << "Voo: " << YELLOW << codigo << GREEN << " Lançado com sucesso!\n" << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "EXPLODIR_VOO")
        {
            int codigo;
            cin >> codigo;
            bool succ = explodirVooUsecases.execute(codigo);
            if(succ){
                cout << GREEN << "Voo: " << YELLOW << codigo << GREEN << " Explodido com sucesso!\n" << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "FINALIZAR_VOO")
        {
            int codigo;
            cin >> codigo;
            bool succ = finalizarVooComSucessoUsecase.execute(codigo);
            if(succ){
                cout << GREEN << "Voo: " << YELLOW << codigo << GREEN << " Finalizado com sucesso!\n" << RESET;
            }
            else{
                cout << RED << "Deu errado!\n" << RESET;
            }
        }
        if (comando == "LISTAR_VOOS")
        {
            auto listaVoos = listarVoosUsecase.execute();
            cout << "####### Lista de Voos #######" << "\n\n";
            for (auto voo : listaVoos)
            {
                cout << "codigo: " << voo.codigo << "\n";
                cout << "estado do voo: " << voo.estado << "\n";
                cout << "*** astronautas do voo ***" << "\n";
                for (auto astronauta : voo.astronautas)
                {
                    cout << "    nome completo: " << astronauta.nome << "\n";
                    cout << "    cpf: " << astronauta.cpf << "\n";
                    cout << "    ----------------------\n\n";
                }
            }
            cout << "\n##############################" << "\n\n";
        }
        if (comando == "LISTAR_MORTOS")
        {
            auto listaDeMortos = listarAstronautasMortosUsecase.execute();
            cout << "####### Lista de Mortos #######" << "\n\n";
            for (auto morto : listaDeMortos)
            {
                cout << "nome completo: " << morto.nome << "\n";
                cout << "cpf: " << morto.cpf << "\n";
                cout << "----------------------------\n\n";
            }
            cout << "\n##############################" << "\n\n";
        }
        if (comando == "LISTAR_ASTRONAUTAS")
        {
            auto listaDeAstronauta = astronautaRepository.getAll();
            for (auto a: listaDeAstronauta)
            {
                cout << "nome completo: " << a.nome << "\n";
                cout << "cpf: " << a.cpf << "\n";
                cout << "status: " << a.disponivel << "\n";
                cout << "vivo: " << a.vivo << "\n";
                cout << "--------------------------\n\n";
            }
        }
    }

    return 0;
}