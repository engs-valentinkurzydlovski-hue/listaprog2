#include <iostream>                 
#include <vector>                   
#include <utility>                  
using namespace std;                

int main() {                        // Início do programa.
    vector<int> v = {5, 3, 8, 4, 2}; // Cria o vetor de entrada.
    int comparacoes = 0;            // Inicializa o contador de comparações.
    int trocas = 0;                 // Inicializa o contador de trocas.

    for (int i = 0; i < (int)v.size() - 1; i++) { // Controla as passagens do Bubble Sort.
        for (int j = 0; j < (int)v.size() - 1 - i; j++) { // Percorre os pares ainda não ordenados.
            comparacoes++;          // Conta a comparação entre dois elementos vizinhos.
            if (v[j] > v[j + 1]) {  // Verifica se o elemento da esquerda é maior.
                swap(v[j], v[j + 1]); // Inverte a posição dos dois elementos.
                trocas++;           // Conta a troca realizada.
            }                       // Fim da condição de troca.
        }                           // Fim do laço interno.
    }                               // Fim do laço externo.

    cout << "Vetor ordenado: ";     // Exibe uma identificação do resultado.
    for (int x : v) cout << x << " "; // Exibe cada elemento do vetor.
    cout << "\nComparacoes: " << comparacoes; // Exibe o total de comparações.
    cout << "\nTrocas: " << trocas << '\n';   // Exibe o total de trocas.
    return 0;                       // Encerra o programa com sucesso.
}                                   // Fim do programa.
