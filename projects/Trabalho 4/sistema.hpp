/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo de cabecalho da classe sistema
*  Aqui sao definidos os atributos e metodos da classe.
*/

#include "arvore.hpp"

class Sistema {
public:
    void adicionarAtleta(Atleta* atleta);
    void removerAtleta(Atleta* atleta);
    void buscarAtleta(string nome);
    void imprimirArvore();

private:
    Arvore<Atleta> arvore;
};
