#include <stdio.h>
#include <string.h>
#include <time.h>  // Incluindo a biblioteca time.h

// Definicao da struct Cliente
typedef struct {
    char nome[100];
    int idade;
    char endereco[200];
} Cliente;

// Funcao para ler os dados dos clientes
void lerClientes(Cliente clientes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite os dados do cliente %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]%*c", clientes[i].nome);
        printf("Idade: ");
        scanf("%d", &clientes[i].idade);
        printf("Endereco: ");
        scanf(" %[^\n]%*c", clientes[i].endereco);
    }
}

// Funcao para imprimir os dados dos clientes
void imprimirClientes(Cliente clientes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Endereco: %s\n\n", clientes[i].endereco);
    }
}

// Funcao para ordenar os clientes por idade usando insertion sort
void insertionSort(Cliente clientes[], int n) {
    for (int i = 1; i < n; i++) {
        Cliente key = clientes[i];
        int j = i - 1;
        while (j >= 0 && clientes[j].idade > key.idade) {
            clientes[j + 1] = clientes[j];
            j = j - 1;
        }
        clientes[j + 1] = key;
    }
}

int main() {
    int n = 10;
    Cliente clientes[n];
    clock_t inicio, fim;  // Variaveis para medir o tempo

    // Ler os dados dos clientes
    lerClientes(clientes, n);

    // Inicia a medicao de tempo
    inicio = clock();

    // Ordenar os clientes por idade
    insertionSort(clientes, n);

    // Finaliza a medicao de tempo
    fim = clock();

    // Calcular o tempo gasto
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Imprimir os clientes ordenados por idade
    printf("\nClientes ordenados por idade:\n");
    imprimirClientes(clientes, n);

    // Exibir o tempo gasto para ordenar os clientes
    printf("Tempo de execucao do insertion sort: %f segundos\n", tempo_gasto);

    return 0;
}