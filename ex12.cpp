#include <cstdio>
#include <omp.h>

int main() {
    int sum = 0; // Variável para armazenar a soma
    omp_set_num_threads(4); // Configura o número de threads a ser utilizado
    printf("Valor inicial de sum: %d\n", sum); // Print do valor inicial da variável
    #pragma omp parallel reduction(+:sum) // Inicia uma região paralela com reduction(+:sum)
    {
        int tid = omp_get_thread_num(); // A variável tid recebe o valor do identificador da thread atual
        sum = 10; // Recebe 10 em cada thread, para que a soma do valor em cada thread seja múltiplo de 10
        printf("Thread ID: %d, sum: %d\n", tid, sum);
    }
    printf("Valor final de sum: %d\n", sum); // Print do valor final da variável
    return 0;
}
