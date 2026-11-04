#include <iostream>                 
#include <vector>                   
using namespace std;                

long long comparacoes = 0;          // Contador global das comparações entre elementos.
long long movimentacoes = 0;        // Conta gravações de valores de volta no vetor.

void merge(vector<int>& v, int inicio, int meio, int fim) { // Intercala duas metades ordenadas.
    vector<int> esquerda(v.begin() + inicio, v.begin() + meio + 1); // Copia a metade esquerda.
    vector<int> direita(v.begin() + meio + 1, v.begin() + fim + 1); // Copia a metade direita.
    int i = 0;                      // Índice usado para percorrer a metade esquerda.
    int j = 0;                      // Índice usado para percorrer a metade direita.
    int k = inicio;                 // Posição atual de gravação no vetor original.

    while (i < (int)esquerda.size() && j < (int)direita.size()) { // Enquanto as duas metades tiverem elementos.
        comparacoes++;              // Conta a comparação entre os elementos das duas metades.
        if (esquerda[i] <= direita[j]) { // Escolhe o menor elemento disponível.
            v[k] = esquerda[i];     // Copia o elemento da esquerda para o vetor original.
            i++;                    // Avança na metade esquerda.
        } else {                    // Se o elemento da direita for menor.
            v[k] = direita[j];      // Copia o elemento da direita para o vetor original.
            j++;                    // Avança na metade direita.
        }                           // Fim da escolha do menor elemento.
        k++;                        // Avança a posição de gravação.
        movimentacoes++;            // Conta a gravação feita no vetor original.
    }                               // Fim da intercalação enquanto ambas têm elementos.

    while (i < (int)esquerda.size()) { // Copia os elementos restantes da esquerda.
        v[k] = esquerda[i];         // Grava o próximo elemento da esquerda.
        i++;                        // Avança na esquerda.
        k++;                        // Avança no vetor original.
        movimentacoes++;            // Conta a gravação.
    }                               // Fim da cópia da esquerda.

    while (j < (int)direita.size()) { // Copia os elementos restantes da direita.
        v[k] = direita[j];          // Grava o próximo elemento da direita.
        j++;                        // Avança na direita.
        k++;                        // Avança no vetor original.
        movimentacoes++;            // Conta a gravação.
    }                               // Fim da cópia da direita.
}                                   // Fim da função merge.

void mergeSort(vector<int>& v, int inicio, int fim) { // Divide e ordena o vetor recursivamente.
    if (inicio >= fim) return;      // Para quando o trecho tem zero ou um elemento.
    int meio = inicio + (fim - inicio) / 2; // Calcula o meio do trecho.
    mergeSort(v, inicio, meio);     // Ordena a metade esquerda.
    mergeSort(v, meio + 1, fim);    // Ordena a metade direita.
    merge(v, inicio, meio, fim);    // Intercala as duas metades ordenadas.
}                                   // Fim da função mergeSort.

int main() {                        // Início do programa.
    vector<int> v = {5, 3, 8, 4, 2}; // Cria o vetor de entrada.
    mergeSort(v, 0, (int)v.size() - 1); // Ordena todo o vetor.
    cout << "Vetor ordenado: ";     // Exibe uma identificação do resultado.
    for (int x : v) cout << x << " "; // Exibe cada elemento do vetor.
    cout << "\nComparacoes: " << comparacoes; // Exibe o total de comparações.
    cout << "\nTrocas diretas: 0";  // Merge Sort intercala por cópias, sem swap direto.
    cout << "\nMovimentacoes: " << movimentacoes << '\n'; // Exibe as gravações no vetor.
    return 0;                       // Encerra o programa com sucesso.
}                                   // Fim do programa.
