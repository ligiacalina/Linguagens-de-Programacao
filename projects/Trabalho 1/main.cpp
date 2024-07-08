/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo principal do exercicio 
*  Este e o arquivo principal do programa, o qual possui toda logica principal, arquivos auxiliares,
*  alem do menu com interacao do usuario.
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <typeinfo>
#include "liga.hpp"

using namespace std;

int main(){

    // Criando objetos Time para armazenar os dados dos times
    Time timeA("Vasco");
    timeA.golsFeitos = {{20, 25, 28}, {30, 35, 32}, {40, 45, 42}, {35, 38, 40}, {8, 30, 28}, {6, 18, 16}, {10, 8, 6}};
    timeA.golsSofridos = {{4, 12, 10}, {11, 20, 18}, {8, 15, 12}, {9, 17, 20}, {15, 18, 22}, {18, 20, 25}, {22, 25, 28}};

    Time timeB("Botafogo");
    timeB.golsFeitos = {{0, 22, 24}, {26, 0, 28}, {34, 38, 36}, {0, 32, 35}, {28, 26, 24}, {22, 20, 18}, {22, 25, 20}};//3
    timeB.golsSofridos = {{20, 25, 28}, {30, 35, 32}, {40, 45, 42}, {35, 38, 40}, {32, 30, 28}, {20, 18, 16}, {20, 8, 6}};

    Time timeC("Fluminense");
    timeC.golsFeitos = {{25, 30, 32}, {35, 0, 38}, {45, 0, 48}, {40, 42, 45}, {0, 36, 34}, {30, 28, 26}, {12, 22, 20}};
    timeC.golsSofridos = {{15, 20, 22}, {25, 30, 28}, {35, 40, 38}, {40, 42, 45}, {38, 36, 34}, {30, 28, 26}, {21, 22, 10}};

    //Criando objeto da classe liga
    Liga liga(timeA, timeB, timeC);
    RetornosMultiplos retorno;
    int opcao;

    while(opcao != 6){

        cout << "---------------- MENU ----------------" << endl;
        cout << "1 - Exibir a media movel de 3 times nos ultimos anos em campeonatos nacionais/estaduais." << endl;
        cout << "2 - Exibir times que apresentaram melhoria de desempenho em um campeonato especifico no ultimo ano." << endl;
        cout << "3 - Exibir times que apresentaram melhoria de desempenho em geral no ultimo ano." << endl;
        cout << "4 - Exibir time com maior saldo de gols em determinado campeonato." << endl;
        cout << "5 - Exibir time com maior evolucao no ultimo ano." << endl;
        cout << "6 - Sair." << endl;
        cout << "Digite o numero referente a operacao desejada: ";
        cin >> opcao;
        cout << "-------------------------------------" << endl;

        switch(opcao){

            int anosConsiderados;
            int indiceCampeonato;

            case 1:

                cout << "Digite o numero de anos que deseja considerar: ";
                cin >> anosConsiderados;
                if (anosConsiderados > 7 || anosConsiderados < 1 || typeid(anosConsiderados) != typeid(int)){
                    cout << "Numero digitado invalido. Tente novamente." << endl;
                    break;
                }

                cout << "0 - Brasileirao" << endl << "1 - Cariocao" << endl << "2 - Copa do Brasil " << endl;
                cout << "Digite o indice correspondente a campeonato que deseja calcular a media de gols: "; 
                cin >> indiceCampeonato;
                if (indiceCampeonato > 2 || indiceCampeonato < 0 || typeid(indiceCampeonato) != typeid(int)){
                    cout << "Numero digitado invalido. Tente novamente." << endl;
                    break;
                }
                liga.setCampeonato(indiceCampeonato);

                liga.exibirMediaMovel(anosConsiderados, indiceCampeonato);
                break;

            case 2:

                cout << "0 - Brasileirao" << endl << "1 - Cariocao" << endl << "2 - Copa do Brasil " << endl;
                cout << "Digite o indice correspondente a campeonato que deseja calcular o desempenho: "; 
                cin >> indiceCampeonato;
                if (indiceCampeonato > 2 || indiceCampeonato < 0 || typeid(indiceCampeonato) != typeid(int)){
                    cout << "Numero digitado invalido. Tente novamente." << endl;
                    break;
                }
                liga.setCampeonato(indiceCampeonato);

                cout << "Desempenho de cada time:" << endl << endl;

                retorno = liga.calcularDesempenhoCampeonato(timeA, indiceCampeonato);
                cout << timeA.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;
                
                cout << " " << endl;

                retorno = liga.calcularDesempenhoCampeonato(timeB, indiceCampeonato);
                cout << timeB.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;
                
                cout << " " << endl;

                retorno = liga.calcularDesempenhoCampeonato(timeC, indiceCampeonato);
                cout << timeC.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;

                break;

            case 3:

                cout << "Desempenho de cada time:" << endl << endl;

                retorno = liga.calcularDesempenho(timeA);
                cout << timeA.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;
                
                cout << " " << endl;

                retorno = liga.calcularDesempenho(timeB);
                cout << timeB.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;
                
                cout << " " << endl;

                retorno = liga.calcularDesempenho(timeC);
                cout << timeC.getNomeDoTime() << ": " << retorno.texto << ". ";
                cout << "Porcentagem de gols feitos: " << fixed << setprecision(1) << retorno.numeroFeitos << "%. ";
                cout << "Porcentagem de gols sofridos: " << fixed << setprecision(1) << retorno.numeroSofridos << "%." << endl;

                break;

            case 4:

                cout << "0 - Brasileirao" << endl << "1 - Cariocao" << endl << "2 - Copa do Brasil " << endl;
                cout << "Digite o indice correspondente a campeonato que deseja saber o time de melhor desempenho: "; 
                cin >> indiceCampeonato;
                if (indiceCampeonato > 2 || indiceCampeonato < 0 || typeid(indiceCampeonato) != typeid(int)){
                    cout << "Numero digitado invalido. Tente novamente." << endl;
                    break;
                }
                liga.setCampeonato(indiceCampeonato);

                liga.calcularMaiorSaldoGols(timeA, timeB, timeC, indiceCampeonato);

                break;

            case 5:

                retorno = liga.calcularMaiorEvolucao(liga.getTimes());
                cout << "Time com maior evolucao nos gols feitos no ultimo ano: " << retorno.texto << " (" << fixed << setprecision(1) << retorno.numeroFeitos << "%)" << endl;
                cout << "Time com maior evolucao nos gols sofridos no ultimo ano: " << retorno.texto2 << " (" << fixed << setprecision(1) << retorno.numeroSofridos << "%)" << endl;
                break;

            default:
                cout << "Opcao invalida. Por favor, digite um valor valido" << endl;

        }
    }

        return 0;

};