#include <thread>
#include <vector>
#include <algorithm>
#include "classificar.h"

void classificar_10_threads(std::vector<int>& vetor, int tamanho) {
    int partes = 10;
    int tamanho_parte = tamanho / partes;

    std::vector<std::thread> threads;

    // Threads classificadoras
    for (int i = 0; i < partes; ++i) {
        int inicio = i * tamanho_parte;
        int fim = (i + 1) * tamanho_parte;
        if (i == partes - 1) fim = tamanho;  // Garantir que a última parte cubra o restante

        threads.emplace_back(std::thread(classificar_parte, std::ref(vetor), inicio, fim));
    }

    // Espera as threads de classificação
    for (auto& t : threads) {
        t.join();
    }

    // Thread de mesclagem
    std::thread t_final(mesclar_partes, std::ref(vetor), 0, tamanho / 2, tamanho / 2, tamanho);
    t_final.join();
}
