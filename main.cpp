#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
#include <chrono>
#include "ler_arquivo.h"

void classificar_2_threads(std::vector<int>& vetor, int tamanho);
void classificar_10_threads(std::vector<int>& vetor, int tamanho);
void classificar_50_threads(std::vector<int>& vetor, int tamanho);

int main() {
    int tamanho = 0;
    std::string nome_arquivo;
    int escolha_arquivo = 0;
    int escolha_algoritmo = 0;

    while(true){

        // Menu de escolha de arquivo
        std::cout << "Escolha o arquivo a ser lido:\n";
        std::cout << "1. Pequeno (100 elementos)\n";
        std::cout << "2. Medio (1000 elementos)\n";
        std::cout << "3. Grande (10000 elementos)\n";
        std::cout << "Escolha (1/2/3): ";
        std::cin >> escolha_arquivo;

        switch (escolha_arquivo) {
            case 1:
                nome_arquivo = "arquivos/valores_pequeno.txt";  // Arquivo pequeno
                break;
            case 2:
                nome_arquivo = "arquivos/valores_medio.txt";  // Arquivo médio
                break;
            case 3:
                nome_arquivo = "arquivos/valores_grande.txt";  // Arquivo grande
                break;
            default:
                std::cout << "Escolha invalida. Usando arquivo médio por padrao.\n";
                nome_arquivo = "arquivos/valores_medio.txt";
                break;
        }

        std::vector<int> vetor = ler_arquivo(nome_arquivo, tamanho);

        std::cout << "Tamanho lido: " << tamanho << std::endl;


        std::vector<int> vetor1 = vetor;
        // Medir tempo de ordenação com 2 threads
        auto start_ordenacao_2_threads = std::chrono::high_resolution_clock::now();
        classificar_2_threads(vetor1, tamanho);
        auto end_ordenacao_2_threads = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_ordenacao_2_threads = end_ordenacao_2_threads - start_ordenacao_2_threads;
        std::cout << "Tempo de ordenacao com 2 threads classificadoras: " << duration_ordenacao_2_threads.count() << " segundos\n";

        /*std::cout << "Vetor final ordenado com 2 threads classificadoras:\n";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << vetor1[i] << " ";
        }*/
        std::cout << std::endl;


        std::vector<int> vetor2 = vetor;
        // Medir tempo de ordenação com 10 threads
        auto start_ordenacao_10_threads = std::chrono::high_resolution_clock::now();
        classificar_10_threads(vetor2, tamanho);
        auto end_ordenacao_10_threads = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_ordenacao_10_threads = end_ordenacao_10_threads - start_ordenacao_10_threads;
        std::cout << "Tempo de ordenacao com 10 threads classificadoras: " << duration_ordenacao_10_threads.count() << " segundos\n";

        /*std::cout << "Vetor final ordenado com 10 threads classificadoras:\n";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << vetor2[i] << " ";
        }*/
        std::cout << std::endl;

    
        std::vector<int> vetor3 = vetor;
        // Medir tempo de ordenação com 50 threads classificadoras
        auto start_ordenacao_50_threads = std::chrono::high_resolution_clock::now();
        classificar_50_threads(vetor3, tamanho);
        auto end_ordenacao_50_threads = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration_ordenacao_50_threads = end_ordenacao_50_threads - start_ordenacao_50_threads;
        std::cout << "Tempo de ordenacao com 50 threads classificadoras: " << duration_ordenacao_50_threads.count() << " segundos\n";

        /*std::cout << "Vetor final ordenado com 50 threads classificadoras:\n";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << vetor3[i] << " ";
        }*/
        std::cout << std::endl;

    }

    return 0;
}
