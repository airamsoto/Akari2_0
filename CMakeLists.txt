cmake_minimum_required(VERSION 3.24)
project(Akari2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Akari2_0 main.cpp posicion.h posicion.cpp listaPosiciones.h listaPosiciones.cpp partida.h partida.cpp tablero.h tablero.cpp reglasJuego.h reglasJuego.cpp color.h celda.h celda.cpp listaPartidas.h listaPartidas.cpp)
