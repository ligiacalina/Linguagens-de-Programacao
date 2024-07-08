/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo de implementacao da classe arvore que servira como template de uma arvore binario
*  Aqui sao definidos e implementados os atributos e metodos deste template.
*/

#include "atleta.hpp"

struct No {
    No(Atleta* atleta) : atleta(atleta), esquerda(nullptr), direita(nullptr) {}
    ~No() { delete atleta; }

    Atleta* atleta;
    No* esquerda;
    No* direita;
};

template <class T>
class Arvore{
    public:
        Arvore() : raiz(nullptr){};

        // Busca um atleta pelo nome na árvore
        No* operator()(string nome) {
            return buscaRecursiva(raiz, nome);
        }

        // Remove um atleta da árvore
        Arvore<T> operator-(Atleta* atleta) {
            raiz = removeRecursivo(raiz, atleta);
            return *this; //retorna a propria arvore modificada sem o no 
        }

        // Adiciona um atleta a árvore
        Arvore<T> operator+(Atleta* atleta) {
            raiz = insereRecursivo(raiz, atleta);
            return *this; //Retorna a propria arvore com o no inserido
        }

        // Imprime todos os elementos da árvore
        void imprime(){
            imprimeRecursivo(raiz);
        }

        //Sobrecarga do operador << para impressao da arvore
        friend ostream& operator<<(ostream& os, Arvore& arvore) {
            arvore.imprimeRecursivo(arvore.raiz);
            return os;
        }

    private:
        No* insereRecursivo(No* noAtual, Atleta* atleta) {
            if (noAtual == nullptr) {
                return new No(atleta);
            }

            if (atleta->getNomeAtleta() < noAtual->atleta->getNomeAtleta()) {
                noAtual->esquerda = insereRecursivo(noAtual->esquerda, atleta);
            } else if (atleta->getNomeAtleta() > noAtual->atleta->getNomeAtleta()) {
                noAtual->direita = insereRecursivo(noAtual->direita, atleta);
            } else {
                // Caso um atleta com o mesmo nome já exista na árvore
                cout << endl << "Atleta com o mesmo nome (" << atleta->getNomeAtleta() << ") ja existe. Por este motivo, nao sera inserido na arvore." << endl;
            }
            return noAtual;
        }

        No* buscaRecursiva(No* noAtual, string nome) {
            if (noAtual == nullptr || noAtual->atleta->getNomeAtleta() == nome) {
                return noAtual;
            }

            if (nome < noAtual->atleta->getNomeAtleta()) {
                return buscaRecursiva(noAtual->esquerda, nome);
            } else {
                return buscaRecursiva(noAtual->direita, nome);
            }
        }

        No* removeRecursivo(No* noAtual, Atleta* atleta) {
            if (noAtual == nullptr) {
                // Caso um atleta nao exista na arvore
                cout << endl << "Nao existe atleta com este nome no sistema." << endl;
                return nullptr;
            }

            if (atleta->getNomeAtleta() < noAtual->atleta->getNomeAtleta()) {
                noAtual->esquerda = removeRecursivo(noAtual->esquerda, atleta);
            } else if (atleta->getNomeAtleta() > noAtual->atleta->getNomeAtleta()) {
                noAtual->direita = removeRecursivo(noAtual->direita, atleta);
            } else {
                if (noAtual->esquerda == nullptr) {
                    No* temp = noAtual->direita;
                    delete noAtual;
                    return temp;
                } else if (noAtual->direita == nullptr) {
                    No* temp = noAtual->esquerda;
                    delete noAtual;
                    return temp;
                }

                No* temp = menorNoSubarvoreDireita(noAtual->direita);
                noAtual->atleta = temp->atleta;
                noAtual->direita = removeRecursivo(noAtual->direita, temp->atleta);
            }

            return noAtual;
        }

        void imprimeRecursivo(No* noAtual) {
            if (noAtual != nullptr) {
                imprimeRecursivo(noAtual->esquerda);
                cout << *(noAtual->atleta) << endl;
                imprimeRecursivo(noAtual->direita);
            }
        }

        // Encontra o menor nó na subárvore direita
        No* menorNoSubarvoreDireita(No* noAtual) {
            No* atual = noAtual;
            while (atual && atual->esquerda != nullptr) {
                atual = atual->esquerda;
            }
            return atual;
        }

        No* raiz;

};