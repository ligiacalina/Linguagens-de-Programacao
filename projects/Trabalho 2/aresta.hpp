/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo auxiliar
*  Este e um arquivo auxiliar de cabecalho, onde somente defino, sem implementacoes, a classe aresta.
*/

//para evitar multiplas inclusoes
#ifndef ARESTA_HPP
#define ARESTA_HPP

#include "vertice.hpp"

using namespace std;

class Aresta {
public:

    void setOrigem(string nome);
    void setDestino(string nome);
    void setDistancia(double numero);

    Vertice getOrigem();
    Vertice getDestino();
    double getDistancia();

private:
    Vertice origem;
    Vertice destino;
    double distancia;
};

#endif // ARESTA_HPP