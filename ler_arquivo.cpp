#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "ler_arquivo.h"

std::vector<int> ler_arquivo(const std::string& nome_arquivo, int& tamanho) {
    std::ifstream arquivo(nome_arquivo);
    std::vector<int> numeros;
    int numero;

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nome_arquivo << std::endl;
        tamanho = 0;
        return numeros;
    }

    while (arquivo >> numero) {
        numeros.push_back(numero);
    }

    tamanho = numeros.size();
    return numeros;
}
