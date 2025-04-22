# Projeto de Ordenação com Threads em C++

Este projeto implementa um algoritmo de ordenação utilizando múltiplas threads em C++. O objetivo é demonstrar o uso de threads para realizar a classificação de um vetor de números, dividindo a carga de trabalho entre várias threads para melhorar a eficiência.


## Funções de Classificação

O código possui três implementações de funções que utilizam **multithreading** para ordenar um vetor de números. A diferença entre elas é a quantidade de threads usadas durante o processo de ordenação. A ordenação é feita usando a função de sort padrão do C++.

### 1. `classificar_2_threads`

Esta função usa **2 threads classificadoras** para dividir o vetor em duas partes, ordenando cada parte individualmente. Após isso, uma **terceira thread de mesclagem** é responsável por combinar essas duas partes ordenadas em um único vetor ordenado.

#### Passo a Passo:
- **2 Threads Classificadoras**: Cada thread classifica uma metade do vetor.
- **1 Thread de Mesclagem**: Após a ordenação das duas partes, a thread de mesclagem junta essas partes ordenadas em um único vetor.

**Objetivo**: Demonstrar uma abordagem simples de multithreading para ordenação, com um nível básico de paralelismo.

### 2. `classificar_10_threads`

Nesta função, **10 threads classificadoras** são usadas para dividir o vetor em 10 partes iguais e ordenar cada parte simultaneamente. Depois disso, uma única thread de **mesclagem** é responsável por juntar todas as partes ordenadas em um vetor final.

#### Passo a Passo:
- **10 Threads Classificadoras**: O vetor é dividido em 10 partes, com cada thread classificando uma parte do vetor.
- **1 Thread de Mesclagem**: Após a classificação das 10 partes, a thread de mesclagem combina todas as partes ordenadas em um único vetor.

**Objetivo**: Aumentar a paralelização do processo de classificação utilizando 10 threads para ordenar diferentes partes do vetor.

### 3. `classificar_50_threads`

Esta função utiliza **50 threads classificadoras** para dividir o vetor em 50 partes iguais. Cada parte é ordenada por uma thread individual. Após a classificação, uma estratégia de mesclagem eficiente é aplicada para juntar todas as partes em um único vetor ordenado final.

#### Passo a Passo:
- **50 Threads Classificadoras**: O vetor é dividido em 50 partes. Cada thread ordena uma dessas partes.
- **Mesclagem em Etapas**: As partes ordenadas são combinadas progressivamente em etapas, utilizando uma abordagem semelhante à de uma árvore binária (merge sort paralelo), para evitar sobrecarga em uma única thread.

**Objetivo**: Aproveitar ao máximo o poder de paralelização do sistema em vetores grandes (ex: 100.000+ elementos), minimizando o tempo de ordenação mesmo em casos com muitos dados.

**Observação**: Essa abordagem é mais eficaz em sistemas com muitos núcleos de CPU e para vetores com muitos elementos. Em vetores pequenos, o uso de muitas threads pode causar sobrecarga (overhead) e reduzir o desempenho.

---

## Testes e conclusões

### Com o arquivo de 100 numeros desordenados

```bash
Escolha o arquivo a ser lido:
1. Pequeno (100 elementos)
2. Medio (1000 elementos)
3. Grande (10000 elementos)
Escolha (1/2/3): 1
Tamanho lido: 100
Tempo de ordenacao com 2 threads classificadoras: 0.0007148 segundos

Tempo de ordenacao com 10 threads classificadoras: 0.0014115 segundos

Tempo de ordenacao com 50 threads classificadoras: 0.0090408 segundos
```

É possível notar que o algorítmo com 2 threads classificadoras obteve um desempenho melhor por se tratar de uma quantidade pequena de dados a serem ordenados e o algorítmo de 50 threads obteve um péssimo desempenho em relação aos outros dois.

### Com o arquivo de 1000 numeros desordenados

```bash
Escolha o arquivo a ser lido:
1. Pequeno (100 elementos)
2. Medio (1000 elementos)
3. Grande (10000 elementos)
Escolha (1/2/3): 2
Tamanho lido: 1000
Tempo de ordenacao com 2 threads classificadoras: 0.0005631 segundos

Tempo de ordenacao com 10 threads classificadoras: 0.0011848 segundos

Tempo de ordenacao com 50 threads classificadoras: 0.0106029 segundos
```

É possível notar que o algorítmo com 2 threads classificadoras continuou obtendo um desempenho melhor e o algorítmo de 50 threads obteve um péssimo novamente desempenho em relação aos outros dois. Em contrapartida, o algorítmo de 10 threads melhorou um pouco seu desempenho por se tratar de mais dados.

### Com o arquivo de 10000 numeros desordenados

```bash
Escolha o arquivo a ser lido:
1. Pequeno (100 elementos)
2. Medio (1000 elementos)
3. Grande (10000 elementos)
Escolha (1/2/3): 3
Tamanho lido: 10000
Tempo de ordenacao com 2 threads classificadoras: 0.0019714 segundos

Tempo de ordenacao com 10 threads classificadoras: 0.0018469 segundos

Tempo de ordenacao com 50 threads classificadoras: 0.0123725 segundos
```

Nesse momento é possível notar uma melhora no algorítmo de 10 threads em relação ao de 2, justamente pelo aumento considerável de dados a serem ordenados. O algorítmo de 50 threads continua tendo um péssimo desempenho, pela mesma causa das anteriores, overhead. Talvez com uma quantidade de dados muitas vezes maior e um computador com um bom número de núcleos essa opção obtenha um desempenho consideravelmente melhor em relação aos outros dois.

---

## Como Rodar o Programa

### Pré-requisitos

Certifique-se de ter o **g++** instalado no seu sistema. Para verificar se o `g++` está instalado, digite o seguinte comando no terminal:

```bash
g++ --version
```

Se o g++ não estiver instalado, você pode instalá-lo da seguinte forma:

```bash
sudo apt-get update
sudo apt-get install g++
```

Depois de instalado, compile o código:

```bash
g++ main.cpp ler_arquivo.cpp classificar_2_threads.cpp classificar_10_threads.cpp classificar_50_threads.cpp -std=c++11 -pthread -o programa
```

E agora é só rodar:

```bash
./programa
```