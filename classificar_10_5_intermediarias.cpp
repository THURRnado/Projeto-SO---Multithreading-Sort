// classificar_10_5_intermediarias.cpp
#include <thread>
#include <vector>
#include <algorithm>
#include "classificar.h"

void classificar_10_5_intermediarias(std::vector<int>& vetor, int tamanho) {
    int partes = 10;
    int tamanho_parte = tamanho / partes;

    std::vector<std::thread> threads_classificadoras;
    std::vector<std::thread> threads_intermediarias;

    // Threads classificadoras (10 threads)
    for (int i = 0; i < partes; ++i) {
        int inicio = i * tamanho_parte;
        int fim = (i + 1) * tamanho_parte;
        if (i == partes - 1) fim = tamanho;  // Garantir que a última parte cubra o restante

        threads_classificadoras.push_back(std::thread(classificar_parte, std::ref(vetor), inicio, fim));
    }

    // Espera as threads de classificação
    for (auto& t : threads_classificadoras) {
        t.join();
    }

    // Threads intermediárias para mesclar parcialmente (5 threads)
    for (int i = 0; i < 5; ++i) {
        int inicio1 = i * 2 * tamanho_parte;
        int fim1 = (i * 2 + 1) * tamanho_parte;
        int inicio2 = (i * 2 + 1) * tamanho_parte;
        int fim2 = (i * 2 + 2) * tamanho_parte;

        threads_intermediarias.push_back(std::thread(mesclar_partes, std::ref(vetor), inicio1, fim1, inicio2, fim2));
    }

    // Espera as threads intermediárias
    for (auto& t : threads_intermediarias) {
        t.join();
    }

    // Thread final de mesclagem
    std::thread t_final(mesclar_partes, std::ref(vetor), 0, tamanho / 2, tamanho / 2, tamanho);
    t_final.join();
}
