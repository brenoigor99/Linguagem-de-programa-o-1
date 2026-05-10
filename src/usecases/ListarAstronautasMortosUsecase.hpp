#pragma once
#include <string>
#include <vector>
#include "../repositories/AstronautaRepository/AstronautaRepository.hpp"
#include "../modelos/astronauta/astronauta.hpp"

class ListarAstronautasMortosUsecase
{
public:
    AstronautaRepository *astronautaRepository = NULL;

    ListarAstronautasMortosUsecase(AstronautaRepository *astronautaRepository)
    {
        this->astronautaRepository = astronautaRepository;
    }

    std::vector<Astronauta> execute()
    {
        if (astronautaRepository == NULL)
        {
            return {};
        }

        return astronautaRepository->getByVivo(false);
    }
};
