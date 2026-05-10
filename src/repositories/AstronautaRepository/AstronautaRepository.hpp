#pragma once
#include "../../modelos/astronauta/astronauta.hpp"
#include <vector>
#include <string>

class AstronautaRepository{
public:
    std::vector<Astronauta> lista_astronautas;

    AstronautaRepository();
    AstronautaRepository(std::vector<Astronauta> lista_astronautas);

    /*
    save
    recebe um astronauta a,
    procura na lista por cpf
    se já existir, retorna falso,
    se não exister, cadastra e salva
    um novo.
    */
    bool save(Astronauta a);

    /*
    delete
    recebe um astronauta a, procura na lista
    de astronautas usando cpf, se não existir,
    retorna falso, se existir, deleta todos os
    dados do astronauta e retorna verdadeiro.
    */
    bool delete_(Astronauta a);

    /*
    upadate
    recebe um astronauta a,
    procura na lista de astronautas usando cpf
    se não existir, retorna falso,
    se existir, substitui todos os dados
    pelos dados passados no parâmetro em a
    e retorna verdadeiro.
    */
    bool update(Astronauta a);

    /*
    getByCpf
    recebe um cpf e retorna uma lista com 
    todos os objetos de mesmo cpf
    (à princípio, a lista deve estar vazia
    ou conter somente um elemento).
    */
    std::vector<Astronauta> getByCpf(std::string cpf);

    /*
    getByDisponivel
    recebe o status de disponibilidade do astronauta e retorna uma 
    lista com todos os objetos da disponibilidade do astronauta.
    */
    std::vector<Astronauta> getByDisponivel(bool diponivel);

    /*
    getByVivo
    recebe um status de vivo ou morto e retorna uma lista com 
    todos os objetos desse status do astronauta.
    */
    std::vector<Astronauta> getByVivo(bool vivo);

    /*
    getAll
    retorna todos os astronautas cadastrados.
    */
    std::vector<Astronauta> getAll();

    /*
    getByListaCpf
    recebe uma lista de cpfs
    retorna uma lista de astronautas
    correspondentes à lista de cpfs
    passada.
    */
    std::vector<Astronauta> getByListaCpf(std::vector<std::string> cpfs);
};