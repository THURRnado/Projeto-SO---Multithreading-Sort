// classificar_2_threads.cpp
#include <thread>
#include <vector>
#include <algorithm>
#include "classificar.h"

void classificar_parte(std::vector<int>& vetor, int inicio, int fim) {
    std::sort(vetor.begin() + inicio, vetor.begin() + fim);
}

void mesclar_partes(std::vector<int>& vetor, int inicio1, int fim1, int inicio2, int fim2) {
    int i = inicio1, j = inicio2, k = 0;
    std::vector<int> resultado(vetor.size());

    while (i < fim1 && j < fim2) {
        if (vetor[i] < vetor[j]) {
            resultado[k++] = vetor[i++];
        } else {
            resultado[k++] = vetor[j++];
        }
    }

    while (i < fim1) {
        resultado[k++] = vetor[i++];
    }

    while (j < fim2) {
        resultado[k++] = vetor[j++];
    }

    // Copia o resultado final para o vetor original
    for (int m = 0; m < k; ++m) {
        vetor[m] = resultado[m];
    }
}

void classificar_2_threads(std::vector<int>& vetor, int tamanho) {
    int meio = tamanho / 2;

    // Threads classificadoras
    std::thread t1(classificar_parte, std::ref(vetor), 0, meio);
    std::thread t2(classificar_parte, std::ref(vetor), meio, tamanho);

    t1.join();
    t2.join();

    // Thread de mesclagem
    std::thread t3(mesclar_partes, std::ref(vetor), 0, meio, meio, tamanho);
    t3.join();
}
