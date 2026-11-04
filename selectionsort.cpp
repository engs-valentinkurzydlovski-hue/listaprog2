#include <iostream>                 
#include <vector>                   
#include <utility>                  
using namespace std;                

int main() {                        // Início do programa.
    vector<int> v = {5, 3, 8, 4, 2}; // Cria o vetor de entrada.
    int comparacoes = 0;            // Inicializa o contador de comparações.
    int trocas = 0;                 // Inicializa o contador de trocas.

    for (int i = 0; i < (int)v.size() - 1; i++) { // Define a posição que receberá o menor valor.
        int menor = i;              // Considera inicialmente que o menor está na posição i.
        for (int j = i + 1; j < (int)v.size(); j++) { // Procura o menor no restante do vetor.
            comparacoes++;          // Conta a comparação entre v[j] e v[menor].
            if (v[j] < v[menor]) {  // Verifica se encontrou um valor menor.
                menor = j;          // Atualiza a posição do menor elemento.
            }                       // Fim da condição.
        }                           // Fim da busca pelo menor elemento.
        if (menor != i) {           // Evita trocar um elemento com ele mesmo.
            swap(v[i], v[menor]);   // Coloca o menor elemento na posição correta.
            trocas++;               // Conta a troca realizada.
        }                           // Fim da troca.
    }                               // Fim do laço externo.

    cout << "Vetor ordenado: ";     // Exibe uma identificação do resultado.
    for (int x : v) cout << x << " "; // Exibe cada elemento do vetor.
    cout << "\nComparacoes: " << comparacoes; // Exibe o total de comparações.
    cout << "\nTrocas: " << trocas << '\n';   // Exibe o total de trocas.
    return 0;                       // Encerra o programa com sucesso.
}                                   // Fim do programa.
