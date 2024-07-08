/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo de cpp da classe sistema
*  Aqui sao implementados os metodos definidos para a classe.
*/

#include "sistema.hpp"

void Sistema::adicionarAtleta(Atleta* atleta) {
    arvore = arvore + atleta;
}

void Sistema::removerAtleta(Atleta* atleta) {
    arvore = arvore - atleta;
}

void Sistema::buscarAtleta(string nome) {
    No* resultado = arvore(nome);
    if (resultado != nullptr) {
        cout << "Atleta encontrado: " << endl << *(resultado->atleta) << endl;
    } else {
        cout << "Atleta nao encontrado." << endl;
    }
}

void Sistema::imprimirArvore() {
    cout << "Arvore de Atletas:" << endl << endl;
    cout << arvore;
}
