
# InsertionSort
## Desenvolvedores
- [Roby Nogueira](https://github.com/Robyhow)
- [Ruan Victor](https://github.com/RuanVNBezerra)

  ## Seções
 > [Oque é Insertion Sort](#oque-%C3%A9-insertion-sort)
 >  
 > [Como ele funciona](#como-ele-funciona)
> 
> [exemplo em C](#exemplo-de-insertion-sort-em-linguaguem-c)
>
> [complexiade de tempo](#an%C3%A1lise-de-complexidade-de-tempo)
>
> [complexiade de espaço](#complexidade-de-espaço)
  
***

 
## Oque é Insertion sort?
Insertion Sort é um algoritmo de ordenação simples e intuitivo que funciona de maneira semelhante à forma como você organizaria cartas em suas mãos. Ele constrói a lista ordenada um item de cada vez, movendo cada novo item para a posição correta entre os itens já ordenados.
## Como ele funciona?
- Inicialização: Começa com o segundo elemento do array (considerando que o primeiro elemento está, por definição, ordenado).
- Comparação e Deslocamento:
  O elemento atual é comparado com os elementos anteriores.
  Enquanto o elemento anterior for maior que o elemento atual, os elementos anteriores são deslocados uma posição para frente, abrindo 
  espaço para o elemento atual.
- Inserção: Quando encontrar a posição correta (onde o elemento anterior não é maior que o elemento atual), insere o elemento atual 
  nessa posição.
- Repetição: Esse processo é repetido para cada elemento da lista até que a lista inteira esteja ordenada.
- Resultado final: todos os elementos da lista são ordenados de maneira correta

  **Propriedades do Insertion Sort**
- Online: Classificar os elementos à medida que os recebe. Caso seja acrescentado mais alguns elementos às listas, é feito apenas a iteração nos elementos recém-adicionados.
- No lugar: O espaço é constante e não requer espaço extra. Este algoritmo classifica os elementos no lugar.
- Estável: Não troca os elementos se seus valores forem iguais. 
- Adaptável: A algoritmo de classificação é adaptativo se levar menos tempo, se os elementos de entrada ou subconjunto de elementos já estiverem classificados. Sendo assim, o tempo de execução do melhor caso é O(N) e o pior tempo de execução é O(N^2). A classificação por inserção é um dos algoritmos de classificação adaptativa.

  ![Insertion Sort](https://markbowman.org/LCC/SortInsertion.gif)
  ***

### Exemplo de Insertion Sort em Linguaguem C
**Insertion Sort**
```c
// Função para realizar o Insertion Sort em um array
void insertionSort(int arr[], int n) {
int i,key,j;
    // Começa a partir do segundo elemento (índice 1)
    for ( i = 1; i < n; i++) {
        // Armazena o valor do elemento atual
         key = arr[i];
        // Inicializa j para comparar com elementos anteriores
         j = i - 1;

        // Move elementos que são maiores que 'key' uma posição à frente
        // do seu índice original
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Desloca o elemento para a direita
            j = j - 1;            // Move para o próximo elemento à esquerda
        }

        // Insere o 'key' na posição correta
        arr[j + 1] = key;
    }
}
```
***

## Análise de complexidade de tempo
## BIG O
- Notação Big-O: A complexidade de tempo é frequentemente expressa usando a notação Big-O, que descreve o crescimento da quantidade de operações no pior caso, à medida que o tamanho da entrada (n) aumenta. Por exemplo:
- O(1): Tempo constante - o tempo de execução não depende do tamanho da entrada.
- O(n): Tempo linear - o tempo de execução cresce linearmente com o tamanho da entrada.
- O(n²): Tempo quadrático - o tempo de execução cresce proporcionalmente ao quadrado do tamanho da entrada.
- O(log n): Tempo logarítmico - o tempo de execução cresce logaritmicamente em relação ao tamanho da entrada.
## Exemplo de Big O em insertion sort 

- Melhor caso (O(n)): Ocorre quando a lista já está ordenada, pois cada elemento só é comparado uma vez.
- Pior caso (O(n²)): Ocorre quando a lista está em ordem inversa, exigindo comparações e deslocamentos para cada elemento
## pior caso
>Complexidade: T(n) = O(n²). Classificar um array em ordem cresccente quando ele está em ordem decrescente é o pior cenário. Indica que o tempo de execução cresce quadraticamente conforme o tamanho da entrada aumenta.
```c
void insertionSort(int arr[], int n){
  int i, key, j; // 1 vez, c1 
  for(i=1;i<n; i++){ // n-1 vez, c2 
    key=arr[i]; // n-1 vez, c3
    j=i-1; // n-1 vez, c4
    while(j>=0 && arr[j]>key){ 
      arr[j+1]=arr[j]; 
      j=j-1; 
    }
    arr[j+1]=key; //n-1 vez, c8 
  }
}
```

> Análise da complexidade com base na implementação do Insertion Sort
```c
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
	int count1, count2; //c1 - 1vez
	Clientes cliente_atual; 

	for (count1 = 1; count1 < Quantidade_Clientes; count1++) { //c2 - (n-1)
		cliente_atual = Clientes_Var[count1]; //c3 - (n-1)
		count2= count1 - 1; //c4 - (n-1)

		while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ //c5 - n(n-1)
			Clientes_Var[count2 + 1] = Clientes_Var[count2]; //c6 - n(n-1)
			count2--; //c7 - n(n-1)
		}

	Clientes_Var[count2 + 1] = cliente_atual; //c8 - (n-1)
  	}

return Clientes_Var; //c9 - 1 vez
}
```

> Cálculos para verificação da complexidade do tempo
```latex
    T(n) = c1 + c9 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)
    T(n) = c + b(n-1) + n(n-1)a
    T(n) = c + bn - b + (n² - n)a
    T(n) = c + bn - b + an² - an
    T(n) = bn + an² - an
    T(n) = n + n² - n
    T(n) = n²
    T(n) = O(n²)
 ```

## **Caso Médio**
> Caso Médio Complexidade: T(n)= O(n²). Acontece quando os elementos de um array ocorrem em ordem confusa, que não é crescente nem decrescente. 
```c
void insertionSort(int arr[], int n){
  int i, key, j; // 1 vez, c1 
  for(i=1;i<n; i++){ // n-1 vez, c2 
    key=arr[i]; // n-1 vez, c3
    j=i-1; // n-1 vez, c4
    while(j>=0 && arr[j]>key){ 
      arr[j+1]=arr[j]; 
      j=j-1; 
    }
    arr[j+1]=key; //n-1 vez, c8 
  }
}
```

> Análise da complexidade com base na implementação do Insertion Sort
```c
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
	int count1, count2; //c1 - 1vez
	Clientes cliente_atual; 

	for (count1 = 1; count1 < Quantidade_Clientes; count1++) { //c2 - (n-1)
		cliente_atual = Clientes_Var[count1]; //c3 - (n-1)
		count2= count1 - 1; //c4 - (n-1)

		while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ //c5 - n(n-1)
			Clientes_Var[count2 + 1] = Clientes_Var[count2]; //c6 - n(n-1)
			count2--; //c7 - n(n-1)
		}

	Clientes_Var[count2 + 1] = cliente_atual; //c8 - (n-1)
  	}

return Clientes_Var; //c9 - 1 vez
}
```

> Cálculos para verificação da complexidade do tempo
```latex
    T(n) = c1 + c9 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)
    T(n) = c + b(n-1) + n(n-1)a
    T(n) = c + bn - b + (n² - n)a
    T(n) = c + bn - b + an² - an
    T(n) = bn + an² - an
    T(n) = n + n² - n
    T(n) = n²
    T(n) = O(n²)
 ```

## **Melhor Caso**
> Melhor Caso Complexidade: T(n) = O(n). Existe apenas n número de comparações, neste caso, complexa realidade é linear. Ocorre quando a entrada está parcialmente ordenada, resultando em um crescimento linear no tempo de execução em relação ao tamanho da entrada.
```c
void insertionSort(int arr[], int n){
  int i, key, j; // 1 vez, c1
  for(i=1;i<n; i++){ // n-1 vez, c2 
    key=arr[i]; // n-1 vez, c3
    j=i-1; // n-1 vez, c4

    while(j>=0 && arr[j]>key){ 
      arr[j+1]=arr[j]; 
      j=j-1; 
    }
    arr[j+1]=key; //n-1 vez, c8 
  }
}
```

> Análise da complexidade com base na implementação do Insertion Sort
```c
Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) {
	int count1, count2; //c1 - 1vez
	Clientes cliente_atual; 

	for (count1 = 1; count1 < Quantidade_Clientes; count1++) { //c2 - (n-1)
		cliente_atual = Clientes_Var[count1]; //c3 - (n-1)
		count2= count1 - 1; //c4 - (n-1)

		/*while (count2 >= 0 && strcmp(Clientes_Var[count2].Nome, cliente_atual.Nome) > 0){ //c5 - n(n-1)
			Clientes_Var[count2 + 1] = Clientes_Var[count2]; //c6 - n(n-1)
			count2--; //c7 - n(n-1)
		}*/

	Clientes_Var[count2 + 1] = cliente_atual; //c8 - (n-1)
  	}

return Clientes_Var; //c9 - 1 vez
}
```

```latex
    T(n) = c1 + c9 + (c2+c3+c4+c8)(n-1) 
    T(n) = c + b(n-1)
    T(n) = c + bn - b 
    T(n) = bn
    T(n) = n
    T(n) = O(n)
 ```
# complexidade de espaço

## O que é complexidade espacial?

 A complexidade espacial de um algoritmo se refere à quantidade de memória extra que um algoritmo utiliza durante sua execução, em relação ao tamanho da entrada. Em outras palavras, mede o quanto de espaço adicional além da entrada original é necessário para o algoritmo funcionar.

## Complexidade espacial do Insertion Sort

O Insertion Sort é considerado um algoritmo in-place. Isso significa que ele realiza a ordenação diretamente sobre o array de entrada, sem a necessidade de criar um novo array para armazenar os elementos ordenados.
Por que o Insertion Sort é in-place?
Uma variável auxiliar: O algoritmo utiliza apenas uma variável auxiliar (geralmente chamada de key) para armazenar o elemento que está sendo inserido na posição correta.
Trocas de elementos: Durante o processo de inserção, os elementos são trocados de posição dentro do próprio array, sem a criação de novas estruturas de dados.

> Análise da complexidade do espaço da implementação com insertion sort
```c
struct clientes{ //Espaco constante
  char Nome[80]; // 80 bytes de espaço - Cada caractere oculpa 1 byte
  char Endereco[80]; //80 bytes
  int Codigo_de_Cliente; // 4 bytes - inteiro
};

void Escrever_dados() { //Espaço constante - função
  int Quantidade_Clientes; //4 bytes
  int contador; // 4 bytes

Clientes *Clientes_Var = (Clientes *)malloc(sizeof(Clientes) * Quantidade_Clientes); 
 O(Quantidade_Clientes).

FILE *Arquivo_Clientes = fopen("Clientes.txt", "w+"); //Espaço constante - operação de abertura de arquivo
  for (contador = 0; contador < Quantidade_Clientes; contador++) { //O(Quantidade_Clientes)

Clientes_Var = insertionSort(Clientes_Var, Quantidade_Clientes); //oculpa um espaco constante
  fclose(Arquivo_Clientes); //Espaço constante - operação de fechamento de arquivo
  free(Clientes_Var); //Espaço constante - operação de liberação de memória.

void string_maiuscula_minuscula(char *str) { //Espaço constante - chamada de uma função
  int i; //4 bytes, espaco constante
//A complexidade de espaço dessa função é O(1), pois não depende do tamanho da entrada str

Clientes *insertionSort(Clientes *Clientes_Var, int Quantidade_Clientes) { //complexidade de espaço = O(1)
  int count1,count2; //duas variaveis inteiras, cada um oculpa 4 bytes, epaço constante
  // cria a variavel que vai servir de parametro na verificação abaixo
 
 Clientes cliente_atual; //A variável key é uma estrutura Clientes, que ocupa um espaço fixo
// a complexidade de espaço dessa função é O(1), pois não depende do tamanho da entrada Clientes_Var ou Quantidade_Clientes.

```
> O Insertion Sort é um algoritmo de ordenação que rearranja os elementos de uma lista, um por um, na ordem correta. Ele não precisa de espaço extra além da própria lista que está sendo ordenada. Isso significa que sua complexidade de espaço é constante, ou seja, O(1). 
>
> Portanto, a complexidade de espaço total do código é dominada pela alocação de memória na função Escrever_dados(), resultando em O(Quantidade_Clientes) em termos de quantidades significativas de memória alocada. As demais operações ocupam um espaço constante adicional.
***
## Referencias e ajuda
- https://gemini.google.com/
- https://youtu.be/ECdLOLaIVx8?si=93UIs5W46jr_NHSw
- https://chatgpt.com/
- https://youtu.be/RGD3iwqDdAE?si=0OLJh0bDdGLL81ZR
- https://youtu.be/v50wSxxlit0?si=G9I6JaPdy0M-4Ko8
