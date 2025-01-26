#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

//Definiendo cantidad de elementos en del arreglo, elementos del hilo y elementos a imprimir
#define N 100
#define chunk 10
#define mostrar 15

void imprimeArreglo(float* d) //funcion para imprimir los arreglos
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;

}

int main()
{
    std::cout << "Sumando Arreglos en Paralelo\n";
   
    float a[N], b[N], c[N];     //Definicion de arreglos
    int i;
    std::srand(static_cast<unsigned int>(std::time(0))); //semilla para el generador de números aleatorios

    for (i = 0; i < N; i++)
    {
        a[i] = std::rand() % N;
        b[i] = std::rand() % N;
        ;
    }
    int pedazos = chunk; //Se da el tamaño de los grupos

 
    #pragma omp parallel for shared(a,b,c,pedazos) private(i) schedule (static, pedazos) // Instruccion for se ejecutara en paralelo, distribuye iteraciones en hilos y controla acceso compartido 

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i]; // Se suman los valores en la posicion i de a y b para asignar a c

    std::cout << "Imprimiendo los primeros " << mostrar << " valores de lo arreglo a:"<< std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores de lo arreglo b:" << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores de lo arreglo c:" << std::endl;
    imprimeArreglo(c);

}


