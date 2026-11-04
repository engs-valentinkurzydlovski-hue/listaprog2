#include <iostream>                 
#include <vector>                   
using namespace std;                

int main() {                        // Início do programa.
    vector<int> v = {5, 3, 8, 4, 2}; // Cria o vetor de entrada.
    int comparacoes = 0;            // Conta comparações entre elementos.
    int deslocamentos = 0;          // Conta quantas vezes um elemento é deslocado à direita.

    for (int i = 1; i < (int)v.size(); i++) { // Começa no segundo elemento.
        int chave = v[i];           // Guarda o valor que será inserido na posição correta.
        int j = i - 1;              // Começa a comparar com o elemento imediatamente anterior.
        while (j >= 0) {            // Continua enquanto houver elementos à esquerda.
            comparacoes++;          // Conta a comparação entre v[j] e chave.
            if (v[j] > chave) {     // Verifica se o elemento deve avançar uma posição.
                v[j + 1] = v[j];    // Desloca o elemento maior para a direita.
                deslocamentos++;    // Conta o deslocamento realizado.
                j--;                // Continua a busca uma posição à esquerda.
            } else {                // Caso o elemento seja menor ou igual à chave.
                break;              // Interrompe a busca desta passagem.
            }                       // Fim da condição.
        }                           // Fim do while.
        v[j + 1] = chave;           // Insere a chave no espaço que ficou livre.
    }                               // Fim do laço externo.

    cout << "Vetor ordenado: ";     // Exibe uma identificação do resultado.
    for (int x : v) cout << x << " "; // Exibe cada elemento do vetor.
    cout << "\nComparacoes: " << comparacoes; // Exibe o total de comparações.
    cout << "\nTrocas diretas: 0";  // O algoritmo desloca elementos, não faz trocas diretas.
    cout << "\nDeslocamentos: " << deslocamentos << '\n'; // Exibe os deslocamentos.
    return 0;                       // Encerra o programa com sucesso.
}                                   // Fim do programa.
