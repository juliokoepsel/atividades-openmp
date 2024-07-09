#include <omp.h>
#include <cstdio>
#include <iostream>


int main(int argc, char *argv[])
{
    int numThreads;

    printf("Informe o número de threads: ");
    std::cin >> numThreads;
    int soma = 0;
    /**
    Default especifica o comportamento de variáveis sem escopo em uma região paralela.
    Nesse caso, shared, que estará em vigor se a cláusula default não for especificada, 
    significa que qualquer variável em uma região paralela será tratada 
    como se tivesse sido especificada com a cláusula shared
     *
    */

#pragma omp parallel num_threads(numThreads) default(shared)
    {
        int id = omp_get_thread_num();
        soma += id;
        printf("Thread id %d - soma: %d \n", id, soma);
    }
}