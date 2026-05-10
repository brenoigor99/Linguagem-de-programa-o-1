all:
	g++ src/main.cpp \
	src/modelos/voo/voo.cpp \
	src/repositories/AstronautaRepository/AstronautaRepository.cpp \
	src/repositories/VooRepository/VooRepository.cpp \
	-o bin/main
run:
	./bin/main
