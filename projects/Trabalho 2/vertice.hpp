/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo auxiliar
*  Este e um arquivo auxiliar de cabecalho, onde somente defino, sem implementacoes, a classe vertice.
*/

//para evitar multiplas declaracoes
#ifndef VERTICE_HPP
#define VERTICE_HPP

#include <string>

using namespace std;

class Vertice {
public:
    void setNomeDaCidade(string nome);
    string getNomeDaCidade();

private:
    string nomeDaCidade;
};

#endif // VERTICE_HPP