# Projeto de Ordenação com Threads em C++

Este projeto implementa um algoritmo de ordenação utilizando múltiplas threads em C++. O objetivo é demonstrar o uso de threads para realizar a classificação de um vetor de números, dividindo a carga de trabalho entre várias threads para melhorar a eficiência.


## Funções de Classificação

O código possui três implementações de funções que utilizam **multithreading** para ordenar um vetor de números. A diferença entre elas é a quantidade de threads usadas durante o processo de ordenação.

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

### 3. `classificar_10_5_intermediarias`

Esta função é mais avançada e utiliza **10 threads classificadoras**, **5 threads intermediárias** para combinar as partes ordenadas e **1 thread de mesclagem final** para juntar o vetor completo.

#### Passo a Passo:
- **10 Threads Classificadoras**: O vetor é dividido em 10 partes, e cada parte é classificada por uma thread.
- **5 Threads Intermediárias**: Essas threads pegam duas partes ordenadas e as combinam, criando subconjuntos ordenados.
- **1 Thread de Mesclagem Final**: Após as threads intermediárias, uma última thread de mesclagem junta as partes restantes para formar o vetor final ordenado.

**Objetivo**: Utilizar um número maior de threads intermediárias para combinar as partes ordenadas de forma mais eficiente.

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
g++ main.cpp ler_arquivo.cpp classificar_2_threads.cpp classificar_10_threads.cpp classificar_10_5_intermediarias.cpp -std=c++11 -pthread -o programa
```

E agora só rodar:

```bash
./programa
```