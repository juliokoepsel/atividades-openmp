#include <cstdio>
#include <omp.h>

int main() {
    omp_set_num_threads(2); // Configura o número de threads a ser utilizado
    for (int i = 1; i <= 5; i++) {
        #pragma omp parallel if(i % 2 == 0) // Inicia uma região paralela com if(i % 2 == 0)
        { // Este bloco só será executado de forma paralela se i for par, caso contrário, será executado de forma serial
            if (i % 2 == 0) { // Se for par, mostra o id da thread junto com o valor de i
                int tid = omp_get_thread_num(); // A variável tid recebe o valor do identificador da thread atual
                printf("Thread ID: %d, ", tid);
            }
            printf("i: %d\n", i);
        }
    }
    return 0;
}
