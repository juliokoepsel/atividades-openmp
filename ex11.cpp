#include <cstdio>
#include <omp.h>

int main() {
    int var = 10; // Variável var, com um valor inicial
    omp_set_num_threads(4); // Configura o número de threads a ser utilizado
    printf("Valor inicial de var: %d\n", var); // Print do valor inicial da variável
    #pragma omp parallel firstprivate(var) // Inicia uma região paralela com firstprivate(var)
    {
        int tid = omp_get_thread_num(); // A variável tid recebe o valor do identificador da thread atual
        var += tid; // Incrementa a variável firstprivate var com o id da thread
        printf("Thread ID: %d, var: %d\n", tid, var);
    }
    printf("Valor final de var: %d\n", var); // Print do valor final da variável
    return 0;
}
