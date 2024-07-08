/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo auxiliar
*  Este e um arquivo auxiliar de cabecalho, onde somente defino, sem implementacoes, a classe grafo.
*/

//para evitar inclusoes multiplas
#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <queue>
#include <functional>
#include <algorithm>
#include <limits>
#include <cfloat>
#include "aresta.hpp"

const double INFINITO = 1000000000000.0;

// Definição da estrutura para poder retornar variveis de diferentes tipos dentro das funcoes
struct RetornosMultiplos{
    string cidade;
    double distancia;
};

class Grafo {
    public:
        Grafo(string arquivoTxt = "cidades.txt") : arquivoTxt(arquivoTxt) {
            lerArquivo();
            distancia.resize(cidades.size(), INFINITO);
            cidadesVisitadas.resize(cidades.size(), false);
            cidadesVizinhas.resize(cidades.size());
        }

        vector<string> getCidades();
        //Retorna o indice da cidade passada por argumento
        int getIndiceCidade(string cidade);

        void lerArquivo();

        void imprimirGrafo();

        int imprimirDensidade();

        void imprimirCidades();

        string existeCidade(string& cidade);

        RetornosMultiplos verticeMaiorCentralidade();

        vector<double> calcularDistanciaDestinoDijkstra(string origem, vector<double>& distancia, vector<string>& cidadesVizinhas, vector<bool>& cidadesVisitadas);

        void imprimeMenorPercursoDuasCidades(int indiceOrigem, int indiceDestino);

        vector<string> reconstruirCaminho(int indiceDestino, vector<string>& cidadesVizinhas);

        vector<double> dijkstraParaTodasCidades(int indiceOrigem);

        void imprimirMaiorCentralidadeProximidade();

    private:
        // Esta função remove espaços em branco, tabulações, quebras de linha e retornos de carro
        // do início e do final de uma string e retorna a string resultante.
        string trim(const string &str);

        Aresta criarAresta(const string& linha);

        vector<double> distancia;
        vector<bool> cidadesVisitadas;
        vector<string> cidades;
        vector<string> cidadesVizinhas;
        vector<Aresta> estradas;
        string arquivoTxt;
    };

    #endif // GRAFO_HPP