/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo de implementacao da classe Time
*  Aqui sao programados os metodos da classe
*/
#include "time.hpp"

using namespace std;

Time::Time(string nome){
            setNomeDoTime(nome);
        }

void Time::setNomeDoTime(string nome){ nomeDoTime = nome; }
string Time::getNomeDoTime() const { return nomeDoTime; }

// Função para calcular a média móvel dos gols
double Time::calcularMediaMovel(vector<vector<int>>& dados, int anosConsiderados) {
            double soma = 0;
            int totalElementos = 0;

            for (vector<vector<int>>::size_type i = dados.size() - anosConsiderados; i < dados.size(); i++) {
                vector<int> ano = dados[i];
                
                for (vector<int>::size_type j = 0; j < ano.size(); j++) {
                    soma += ano[j];
                    ++totalElementos;
                }
            }

            return totalElementos > 0 ? soma / totalElementos : 0;
        }

//Função para calcular média móvel de gols em um campeonato específico
double Time::calcularMediaMovelPorCampeonato(vector<vector<int>>& dados, int anosConsiderados, int indiceCampeonato) {
            double soma = 0;
            int totalElementos = 0;

            // Loop externo para percorrer os anos
            for (vector<vector<int>>::size_type i = dados.size() - anosConsiderados; i < dados.size(); i++) {
                vector<int> ano = dados[i];

                // Loop interno para percorrer as competições dentro de um ano
                for (vector<int>::size_type j = 0; j < ano.size(); j++) {
                    if( static_cast<int>(j) == indiceCampeonato){
                    soma += ano[j];
                    ++totalElementos;
                    }
                }
            }

            return totalElementos > 0 ? soma / totalElementos : 0;
        }

//Função para calcular a média móvel em um determinado ano
double Time::calcularMediaMovelPorAno(vector<vector<int>>& dados, int i) {
            double soma = 0;
            int totalElementos = 0;
            vector<int> ano = dados[i];

            for (vector<int>::size_type j = 0; j < ano.size(); j++) {
                soma += ano[j];
                ++totalElementos;
            }

            return totalElementos > 0 ? soma / totalElementos : 0;

        }

//Função para calcular média móvel de gols em um campeonato específico em um determinado ano
double Time::getGolsDeCampeonato(vector<vector<int>>& dados, int i, int indiceCampeonato) {
            vector<int> ano = dados[i];
            return ano[indiceCampeonato];
        }

int Time::calcularSaldoDeGols(vector<vector<int>>& dados, int indiceCampeonato) {
            int soma = 0;

            // Loop externo para percorrer os anos
            for (vector<vector<int>>::size_type i = 0; i < dados.size(); i++) {
                vector<int> ano = dados[i];

                // Loop interno para percorrer as competições dentro de um ano
                for (vector<int>::size_type j = 0; j < ano.size(); j++) {
                    if( static_cast<int>(j) == indiceCampeonato){
                    soma += ano[j];
                    //std::cout << "soma: " << soma << endl;

                    }
                }
            }

            return soma;
        }
