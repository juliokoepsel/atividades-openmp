#include <omp.h>
#include <cstdio>
#include <iostream>

int varGlobal;
// A diretiva threadprivate especifica quais variáveis serão privadas em
// todo o escopo do código, ou seja, em todas as regiões paralelas.
#pragma omp threadprivate(varGlobal)

int main(int argc, char *argv[])
{
    int numThreads;

    printf("Informe o número de threads: ");
    std::cin >> numThreads;
    varGlobal = 5;
    /**
    A cláusula copyin permite que as cópias de cada thread de uma
    variável definida como threadprivate sejam iniciadas com o mesmo valor.
    O valor da variável da thread mestre é copiado, no início da região paralela,
    para as variáveis correspondentes das outras threads
     *
    */

#pragma omp parallel num_threads(numThreads) copyin(varGlobal)
    {
        int id = omp_get_thread_num();
        printf("Thread id %d - variável global: %d \n", id, varGlobal);
    }
}