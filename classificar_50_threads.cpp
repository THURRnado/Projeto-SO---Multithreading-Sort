#include <thread>
#include <vector>
#include <algorithm>
#include "classificar.h"

void classificar_50_threads(std::vector<int>& vetor, int tamanho) {
    int partes = 50;
    int tamanho_parte = tamanho / partes;

    std::vector<std::thread> threads;

    // Classificação paralela (50 threads)
    for (int i = 0; i < partes; ++i) {
        int inicio = i * tamanho_parte;
        int fim = (i + 1) * tamanho_parte;
        if (i == partes - 1) fim = tamanho;  // última parte pega o restante

        threads.emplace_back(classificar_parte, std::ref(vetor), inicio, fim);
    }

    for (auto& t : threads) {
        t.join();
    }

    // Mesclagens sucessivas em etapas
    int atual_partes = partes;
    int passo = tamanho_parte;

    while (atual_partes > 1) {
        std::vector<std::thread> threads_merge;
        for (int i = 0; i < atual_partes; i += 2) {
            int inicio1 = i * passo;
            int fim1 = std::min((i + 1) * passo, tamanho);
            int inicio2 = fim1;
            int fim2 = std::min((i + 2) * passo, tamanho);

            if (inicio2 >= tamanho) break;

            threads_merge.emplace_back(mesclar_partes, std::ref(vetor), inicio1, fim1, inicio2, fim2);
        }

        for (auto& t : threads_merge) {
            t.join();
        }

        passo *= 2;
        atual_partes = (atual_partes + 1) / 2;  // arredonda pra cima se for ímpar
    }
}
