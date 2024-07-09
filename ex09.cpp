#include <cstdio>
#include <omp.h>

int main() {
    int tid = -1; // Variável tid, que será utilizada de forma privada pelas threads
    omp_set_num_threads(4); // Configura o número de threads a ser utilizado
    printf("Valor inicial de tid: %d\n", tid); // Print do valor inicial da variável
    #pragma omp parallel private(tid) // Inicia uma região paralela com private(tid)
    {
        tid = omp_get_thread_num(); // A variável tid recebe o valor do identificador da thread atual
        printf("Thread ID: %d\n", tid); // Print do identificador da thread
    }
    printf("Valor final de tid: %d\n", tid); // Print do valor final da variável
    return 0;
}
