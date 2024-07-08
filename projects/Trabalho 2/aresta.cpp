/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo auxiliar
*  Este e um arquivo auxiliar, no qual implemento as funcoes definidas no arquivo de cabecalho da classe aresta.
*/

#include "aresta.hpp"

void Aresta::setOrigem(string nome){ origem.setNomeDaCidade(nome);}
void Aresta::setDestino(string nome){destino.setNomeDaCidade(nome);}
void Aresta::setDistancia(double numero){ distancia = numero;}

Vertice Aresta::getOrigem() { return origem; }
Vertice Aresta::getDestino() { return destino; }
double Aresta::getDistancia() { return distancia; }
