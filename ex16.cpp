#include <omp.h>
#include <cstdio>
#include <iostream>
#include <random>
int main(int argc, char *argv[])
{
    int numThreads;
    int soma = 0;

    printf("Informe o número de threads: ");
    std::cin >> numThreads;

    int inicioIntervalo;
    printf("Informe o valor mínimo: ");
    std::cin >> inicioIntervalo;

    int fimIntervalo;
    printf("Informe o valor máximo: ");
    std::cin >> fimIntervalo;

#pragma omp parallel num_threads(numThreads) reduction(+:soma)
    {
        // Gerador de números aleatórios
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(inicioIntervalo, fimIntervalo);
        int id = omp_get_thread_num();

        for (int i = 0; i < 10; i++)
        {
            int num = distrib(gen);
            soma += num;
            printf("Thread id %d gerou o número %d \n", id, num);
        }
    }
    printf("Soma: %d \n", soma);

    return 0;
}