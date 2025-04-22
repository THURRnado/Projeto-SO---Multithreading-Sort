// classificar.h
#ifndef CLASSIFICAR_H
#define CLASSIFICAR_H

#include <vector>

// Funções para classificação com diferentes números de threads
void classificar_2_threads(std::vector<int>& vetor, int tamanho);
void classificar_10_threads(std::vector<int>& vetor, int tamanho);
void classificar_50_threads(std::vector<int>& vetor, int tamanho);

// Funções auxiliares
void classificar_parte(std::vector<int>& vetor, int inicio, int fim);
void mesclar_partes(std::vector<int>& vetor, int inicio1, int fim1, int inicio2, int fim2);

#endif 
