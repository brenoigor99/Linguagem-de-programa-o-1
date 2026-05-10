#include "VooRepository.hpp"

VooRepository::VooRepository() = default;

VooRepository::VooRepository(std::vector<Voo> lista_voos){
    this->lista_voos = lista_voos;
}

bool VooRepository::save(Voo v){
    for(int i = 0; i < this->lista_voos.size(); i++){
        if(v.codigo_voo == this->lista_voos[i].codigo_voo){
            return false;
        }
    }
    this->lista_voos.push_back(v);

    return true;
}

bool VooRepository::delete_(Voo v){
    int indice = -1;
    for(int i = 0; i < this->lista_voos.size(); i++){
        if(this->lista_voos[i].codigo_voo == v.codigo_voo){
            indice = i;
            break;
        }
    }
    if(indice != -1){
        this->lista_voos.erase(this->lista_voos.begin() + indice);
        return true;
    }
    return false;
}

bool VooRepository::update(Voo v){
    int indice = -1;
    for(int i = 0; i < this->lista_voos.size(); i++){
        if(this->lista_voos[i].codigo_voo == v.codigo_voo){
            indice = i;
            break;
        }
    }
    if(indice != -1){
        this->lista_voos[indice] = v;
        return true;
    }

    return false;
}

std::vector<Voo> VooRepository::getByCodigo(int codigo){
    std::vector<Voo> resultado;
    for(int i = 0; i < this->lista_voos.size(); i++){
        if(codigo == this->lista_voos[i].codigo_voo){
            resultado.push_back(lista_voos[i]);
            break;
        }
    }
    return resultado;
}

std::vector<Voo> VooRepository::getByEstado(std::string estado){
    std::vector<Voo> resultado;
    for(int i = 0; i < this->lista_voos.size(); i++){
        if(estado == this->lista_voos[i].estado_voo){
            resultado.push_back(lista_voos[i]);
        }
    }
    return resultado;
}

std::vector<Voo> VooRepository::getAll(){
    return this->lista_voos;
}