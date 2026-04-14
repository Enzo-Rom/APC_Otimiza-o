#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// dez milhoes 10000000, cem milhoes 100000000,
//                   0s,                   14s,

int main(){
    //inicialização do arquivo.
    FILE *file;
    file = fopen("NumerosPrimos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // numero maximo até onde calcularemos os primos.
    // tipo unsigned porque so consideraremos os numeros naturais.
    size_t n;
    scanf("%lu", &n);

    //alocacao de um vetor com n booleanos
    bool *primos;
    primos = calloc(n, sizeof(bool));

    //Quantide de numeros primos encontrados
    size_t qt = 0;
    
    //variaveis de medição do tempo de execução
    time_t t_inicio = time(NULL);
    time_t t_fim;

    for (size_t i = 2; i < n; i++)
    {
        for (size_t j = 2*i; j < n; j += i)
        {
            primos[j] = true;
        }
    }

    for (size_t i = 2; i < n; i++)
    {
        if (primos[i] == false)
        {
            fprintf(file, "%lu - ", i);
            qt++;
            if (qt % 10 == 0)
            {
                fprintf(file, "\n");
            }
        }
    }

    printf("%lu Números Primos\n", qt);
    t_fim = time(NULL);
    printf(" Tempo de execucao: %lds\n", t_fim - t_inicio);

    //Deve-se liberar a memoria alocada dinamicamente e o arquivo 
    //aberto durante a execucao ao fim do programa.
    free(primos); 
    fclose(file);
    return 0;
}