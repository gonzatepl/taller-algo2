# Para los tests

## Preliminares: 
* Ver _tp4-consigna_ para tener contexto del código propuesto. 
* La semántica teórica de los módulos que se encuentran en el documento _tp3-modulos_, que sirven como documentación preliminar para el desarrollo del proyecto, es propia de la cátedra de la materia. 

## Opción 1: Compilar y Ejecutar desde CLion

## Opción 2:

### Compilación: Requiere algún compilador de C++ como g++ o gcc

1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`

### Ejecución:

Desde el inicio del proyecto:

1. `cd build/`
2. `./correrTests`

############################

# Para la interfaz gráfica

# Dependencias

Se necesitan dependencias que pueden ser instaladas en Ubuntu corriendo el siguiente comando en una terminal:

    sudo apt install libsdl2-dev


Las instrucciones no están probadas en Mac OS pero pueden funcionar. Para
Windows, se puede probar instalando la dependencia como se indica arriba dentro
del WSL. En caso de usar Mingw, es necesario instalar la dependencia
`libsdl2-dev` usando la herramienta de dependencias.

Otra opción en Windows (usando MinGW) es descargar SDL desde:
https://www.libsdl.org/download-2.0.php
(En la sección "Development Libraries:" -> "Windows:" -> "SDL2-devel-2.0.14-mingw.tar.gz (MinGW 32/64-bit)")
Luego descomprimir los archivos descargados y copiarlos en la carpeta de instalación de MinGW.