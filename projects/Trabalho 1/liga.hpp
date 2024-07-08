/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo de cabecalho da classe Liga
*  Aqui sao definidos os atributos e metodos da classe.
*/
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "time.hpp"

using namespace std;

// Definição da estrutura para poder retornar variveis de diferentes tipos dentro das funcoes
struct RetornosMultiplos{
    string texto;
    string texto2;
    double numeroFeitos;
    double numeroSofridos;
    double numeroTotal;
};

class Liga{

    public:

        //Inicializando o vetor times com os objetos da classe Time
        Liga(Time timeA, Time timeB, Time timeC);

        //Metodo para setar o campeonato
        void setCampeonato(int indiceCampeonato);
        //Metodo que retorna uma string com o nome do campeonato setado;
        string getCampeonato();
        //Metodo que retorna uma lista com todos os times da liga
        vector<Time> getTimes();

        //Metodo que exibe para o usuario a media movel de todos os times da liga
        void exibirMediaMovel(int anosConsiderados, int indiceCampeonato);

        /* 
        *  Metodo que calcula o desempenho de um unico time em um campeonato especifico
        *  Retorna uma variavel do tipo RetornosMultiplos onde:
        *  texto = nome do time; numeroFeitos = porcentagem de gols feitos; numeroSofridos = porcentagem de gols sofridos
        */
        RetornosMultiplos calcularDesempenhoCampeonato(Time& time, int indiceCampeonato);
       
        /* 
        *  Metodo que calcula o desempenho de um unico time em todos os campeonatos
        *  Retorna uma variavel do tipo RetornosMultiplos onde:
        *  texto = nome do time; numeroFeitos = porcentagem de gols feitos; numeroSofridos = porcentagem de gols sofridos
        */
        RetornosMultiplos calcularDesempenho(Time& time);
        
        //Metodo que exibe o time com o maior saldo de gols da liga
        void calcularMaiorSaldoGols(Time& timeA, Time& timeB, Time& timeC, int indiceCampeonato);

         /* 
        *  Metodo que calcula o time com maior evolucao da liga em relacao ao saldo de gols
        *  Retorna uma variavel do tipo RetornosMultiplos onde:
        *  texto = nome do time com maior porcentagem de crescimento de gols feitos; texto2 = nome do time com maior porcentagem de diminuicao de gols sofridos;
        *  numeroFeitos = porcentagem de crescimento dos gols feitos; numeroSofridos = porcentagem de crescimento dos gols sofridos;
        */
        RetornosMultiplos calcularMaiorEvolucao(vector<Time> times);
        
    private:
        vector<Time>times; //Vetor de objetos da classe Time
        string campeonato;
        double limiarMelhoria = 0.1;
};