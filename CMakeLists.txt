cmake_minimum_required(VERSION 4.0)
project(SituacionProblema)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(SituacionProblema
        src/main.cpp
        src/Producto.cpp
        src/Producto.h
        src/Cliente.h
        src/Cliente.cpp
        src/Repartidor.h
        src/Envio.cpp
        src/Envio.h
        src/Repartidor.cpp)
