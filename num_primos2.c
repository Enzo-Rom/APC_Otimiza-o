#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// mil 1000, cem mil 100000, milhao 1000000,
//       0s,             1s,           123s,

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
    unsigned int n;
    scanf("%u", &n);

    //alocacao de um vetor com n inteiros
    int *num_primos;
    num_primos = calloc(n, sizeof(int));

    int ind = 0; //indice do vetor de primos.
    bool eprimo;
    
    //variaveis de medição do tempo de execução
    time_t t_inicio = time(NULL);
    time_t t_fim;

    for (long i = 2; i < n; i++)
    {
        eprimo = true;
        //não precisamos continuar testando, caso i ja seja divisivel por alguem
        for (long j = 2; j < i && eprimo == true; j++)
        {
            if (i % j == 0)
            {
                eprimo = false;
            }
        }
        if (eprimo == true)
        {
            num_primos[ind] = i;
            ind++;
        }
    }

    for (size_t i = 0; i < ind; i++)
    {
        fprintf(file, "%d - ", num_primos[i]);
        if (i % 10 == 9)
        {
            fprintf(file, "\n");
        }
    }

    printf("%d Números Primos\n", ind);
    t_fim = time(NULL);
    printf(" Tempo de execucao: %lds\n", t_fim - t_inicio);

    //Deve-se liberar a memoria alocada dinamicamente e o arquivo 
    //aberto durante a execucao ao fim do programa.
    free(num_primos); 
    fclose(file);
    return 0;
}