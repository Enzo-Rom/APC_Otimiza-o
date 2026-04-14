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

    //Numero maximo até onde calcularemos os naop.
    //Tipo unsigned porque so consideraremos os numeros naturais.
    size_t n;
    scanf("%lu", &n);

    //Alocacao de um vetor com n booleanos
    //Para cada posição, naop diz se o indice é primo
    bool *naop;
    naop = calloc(n, sizeof(bool));

    //Quantide de numeros naop encontrados
    size_t qt = 0;
    
    //Variaveis de medição do tempo de execução
    time_t t_inicio = time(NULL);
    time_t t_fim;

    //Para cada numero, diz que seus multiplos não são primos
    for (size_t i = 2; i < n; i++)
    {
        for (size_t j = 2*i; j < n; j += i)
        {
            naop[j] = true;
        }
    }

    //Se o numero é primo, naop eh falso, portanto ele sera printado no arquivo
    for (size_t i = 2; i < n; i++)
    {
        if (naop[i] == false)
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
    free(naop); 
    fclose(file);
    return 0;
}