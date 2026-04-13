#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// mil 1000, cem mil 100000, milhao 1000000,
//      <1s,            19s,         >10min,

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
    int *primos;
    primos = calloc(n, sizeof(bool));

    //Quantide de numeros primos encontrados
    size_t qt = 0;
    
    //variaveis de medição do tempo de execução
    time_t t_inicio = time(NULL);
    time_t t_fim;

    for (size_t i = 2; i < n; i++)
    {
        for (size_t j = i; j < n; j += i)
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