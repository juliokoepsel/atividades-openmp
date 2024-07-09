#include <cstdio>
#include <omp.h>

int main() {
    int shared_var = 0; // Variável compartilhada entre todas as threads
    omp_set_num_threads(4); // Configura o número de threads a ser utilizado
    printf("Valor inicial de shared_var: %d\n", shared_var); // Print do valor inicial da variável
    #pragma omp parallel shared(shared_var) // Inicia uma região paralela com shared(shared_var)
    {
        int tid = omp_get_thread_num(); // A variável tid recebe o valor do identificador da thread atual
        #pragma omp critical // Seção crítica para manipulação da variável compartilhada
        {
            shared_var += 1; // Incrementa a variável compartilhada
            printf("Thread ID: %d, shared_var: %d\n", tid, shared_var); // Print da tid e shared_var
        }
    }
    printf("Valor final de shared_var: %d\n", shared_var); // Print do valor final de shared_var
    return 0;
}
