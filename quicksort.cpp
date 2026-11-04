#include <iostream>                 
#include <vector>                   
#include <utility>                  
using namespace std;                

long long comparacoes = 0;          // Contador das comparações com o pivô.
long long trocas = 0;               // Contador das trocas entre posições diferentes.

int particionar(vector<int>& v, int baixo, int alto) { // Separa menores/iguais e maiores que o pivô.
    int pivo = v[alto];             // Escolhe o último elemento como pivô.
    int i = baixo - 1;               // Marca o limite dos elementos menores ou iguais ao pivô.
    for (int j = baixo; j < alto; j++) { // Percorre os elementos antes do pivô.
        comparacoes++;              // Conta a comparação do elemento atual com o pivô.
        if (v[j] <= pivo) {         // Verifica se o elemento pertence ao lado esquerdo.
            i++;                    // Avança o limite da região dos menores ou iguais.
            if (i != j) {           // Evita contar troca de uma posição com ela mesma.
                swap(v[i], v[j]);   // Coloca o elemento na região dos menores ou iguais.
                trocas++;           // Conta a troca efetiva.
            }                       // Fim da condição de troca.
        }                           // Fim da condição de partição.
    }                               // Fim do laço de partição.
    if (i + 1 != alto) {            // Verifica se o pivô precisa mudar de posição.
        swap(v[i + 1], v[alto]);    // Coloca o pivô entre as duas regiões.
        trocas++;                   // Conta a troca efetiva do pivô.
    }                               // Fim da troca do pivô.
    return i + 1;                   // Retorna a posição definitiva do pivô.
}                                   // Fim da função particionar.

void quickSort(vector<int>& v, int baixo, int alto) { // Ordena recursivamente os dois lados do pivô.
    if (baixo < alto) {             // Continua se houver pelo menos dois elementos.
        int posicaoPivo = particionar(v, baixo, alto); // Particiona e obtém a posição do pivô.
        quickSort(v, baixo, posicaoPivo - 1); // Ordena a parte à esquerda do pivô.
        quickSort(v, posicaoPivo + 1, alto);  // Ordena a parte à direita do pivô.
    }                               // Fim da condição recursiva.
}                                   // Fim da função quickSort.

int main() {                        // Início do programa.
    vector<int> v = {5, 3, 8, 4, 2}; // Cria o vetor de entrada.
    quickSort(v, 0, (int)v.size() - 1); // Ordena todo o vetor.
    cout << "Vetor ordenado: ";     // Exibe uma identificação do resultado.
    for (int x : v) cout << x << " "; // Exibe cada elemento do vetor.
    cout << "\nComparacoes: " << comparacoes; // Exibe o total de comparações.
    cout << "\nTrocas: " << trocas << '\n';   // Exibe o total de trocas.
    return 0;                       // Encerra o programa com sucesso.
}                                   // Fim do programa.
