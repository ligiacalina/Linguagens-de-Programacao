/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo de implementacao da classe Liga
*  Aqui sao programados os metodos da classe
*/
#include "liga.hpp"

using namespace std;

RetornosMultiplos retorno;

//Inicializando o vetor times com os objetos da classe Time
Liga::Liga(Time timeA, Time timeB, Time timeC){
            times.push_back(timeA);
            times.push_back(timeB);
            times.push_back(timeC);
        }

void Liga::setCampeonato(int indiceCampeonato){
            if (indiceCampeonato == 0){ campeonato = "Brasileirao";}
            else if (indiceCampeonato == 1){campeonato = "Cariocao";}
            else if (indiceCampeonato == 2){campeonato = "Copa do Brasil";}
            else {campeonato = "invalido";}
        }
string Liga::getCampeonato(){return campeonato;}
vector<Time> Liga::getTimes(){return times;}

void Liga::exibirMediaMovel(int anosConsiderados, int indiceCampeonato){
            for (Time& time : times) {
                cout << endl << "Time: " << time.getNomeDoTime() << endl;
                cout << "Media movel de gols feitos nos ultimos " << anosConsiderados << " anos: " << fixed << setprecision(2) << time.calcularMediaMovel(time.golsFeitos, anosConsiderados) << endl;
                cout << "Media movel de gols sofridos nos ultimos " << anosConsiderados << " anos: " << fixed << setprecision(2) << time.calcularMediaMovel(time.golsSofridos, anosConsiderados) << endl;
                cout << "Media movel de gols feitos nos ultimos " << anosConsiderados << " anos no campeonato " << getCampeonato() << ": " << fixed << setprecision(2) <<  time.calcularMediaMovelPorCampeonato(time.golsFeitos, anosConsiderados, indiceCampeonato) << endl;
                cout << "Media movel de gols sofridos nos ultimos " << anosConsiderados << " anos no campeonato " << getCampeonato() << ": " << fixed << setprecision(2) << time.calcularMediaMovelPorCampeonato(time.golsSofridos, anosConsiderados, indiceCampeonato) << endl;
                cout << "-------------------------------------" << endl;
            }

        }

RetornosMultiplos Liga::calcularDesempenhoCampeonato(Time& time, int indiceCampeonato){

            int ano = (time.golsFeitos.size()-1);
            double golsFeitosAtual = time.getGolsDeCampeonato(time.golsFeitos, ano, indiceCampeonato);
            double golsFeitosAnterior = time.getGolsDeCampeonato(time.golsFeitos, ano-1, indiceCampeonato);
            double golsSofridosAtual = time.getGolsDeCampeonato(time.golsSofridos, ano, indiceCampeonato);
            double golsSofridosAnterior = time.getGolsDeCampeonato(time.golsSofridos, ano-1, indiceCampeonato);

            double razaoFeitos = (golsFeitosAtual - golsFeitosAnterior) / golsFeitosAnterior;
            double razaoSofridos = (golsSofridosAtual - golsSofridosAnterior) / golsSofridosAnterior;

            //Atribuicao apenas para conseguir fazer retorno de strings e doubles
            retorno.numeroFeitos = razaoFeitos*100;
            retorno.numeroSofridos = razaoSofridos*100;

            if (razaoFeitos > limiarMelhoria || razaoSofridos < -limiarMelhoria) {
                retorno.texto = "Melhora";
            } else if (razaoFeitos < -limiarMelhoria || razaoSofridos > limiarMelhoria) {
                retorno.texto = "Piora";
            } else {
                retorno.texto = "Estavel";
            }
            return retorno;
        }

RetornosMultiplos Liga::calcularDesempenho(Time& time){

            int ano = (time.golsFeitos.size()-1);
            double mediaMovelFeitosAtual = time.calcularMediaMovelPorAno(time.golsFeitos, ano);
            double mediaMovelFeitosAnterior = time.calcularMediaMovelPorAno(time.golsFeitos, ano-1);
            double mediaMovelSofridosAtual = time.calcularMediaMovelPorAno(time.golsSofridos, ano);
            double mediaMovelSofridosAnterior = time.calcularMediaMovelPorAno(time.golsSofridos, ano-1);

            double razaoFeitos = (mediaMovelFeitosAtual - mediaMovelFeitosAnterior) / mediaMovelFeitosAnterior;
            double razaoSofridos = (mediaMovelSofridosAtual - mediaMovelSofridosAnterior) / mediaMovelSofridosAnterior;

            //Atribuicao apenas para conseguir fazer retorno de strings e doubles
            retorno.numeroFeitos = razaoFeitos*100;
            retorno.numeroSofridos = razaoSofridos*100;

            if (razaoFeitos > limiarMelhoria || razaoSofridos < -limiarMelhoria) {
                retorno.texto = "Melhora";
            } else if (razaoFeitos < -limiarMelhoria || razaoSofridos > limiarMelhoria) {
                retorno.texto = "Piora";
            } else {
                retorno.texto = "Estavel";
            }
            return retorno;
        }

void Liga::calcularMaiorSaldoGols(Time& timeA, Time& timeB, Time& timeC, int indiceCampeonato){

            int somaGolsFeitosA = timeA.calcularSaldoDeGols(timeA.golsFeitos, indiceCampeonato);
            int somaGolsSofridosA = timeA.calcularSaldoDeGols(timeA.golsSofridos, indiceCampeonato);
            int somaGolsFeitosB = timeB.calcularSaldoDeGols(timeB.golsFeitos, indiceCampeonato);
            int somaGolsSofridosB = timeB.calcularSaldoDeGols(timeB.golsSofridos, indiceCampeonato);
            int somaGolsFeitosC = timeC.calcularSaldoDeGols(timeC.golsFeitos, indiceCampeonato);
            int somaGolsSofridosC = timeC.calcularSaldoDeGols(timeC.golsSofridos, indiceCampeonato);

            int saldoA = somaGolsFeitosA - somaGolsSofridosA;
            int saldoB = somaGolsFeitosB - somaGolsSofridosB;
            int saldoC = somaGolsFeitosC - somaGolsSofridosC;

            if (saldoA > saldoB && saldoA > saldoC){
                cout << "O time de maior saldo de gols e o " << timeA.getNomeDoTime() << " com " << somaGolsFeitosA << " gols e " << somaGolsSofridosA << " gols sofridos. ";
                cout << "Total = " << saldoA << endl;
            } else if(saldoB > saldoA && saldoB > saldoC){
                cout << "O time de maior saldo de gols e o" << timeB.getNomeDoTime() << " com " << somaGolsFeitosB << " gols e " << somaGolsSofridosB << " gols sofridos. ";
                cout << "Total = " << saldoB << endl;
            } else if(saldoC > saldoA && saldoC > saldoB){
                cout << "O time de maior saldo de gols e o" << timeC.getNomeDoTime() << " com " << somaGolsFeitosC << " gols e " << somaGolsSofridosC << " gols sofridos. ";
                cout << "Total = " << saldoC << endl;                    
            } else if(saldoA == saldoB && saldoA != saldoC){
                cout << "Empate entre os times " << timeA.getNomeDoTime() << " e " << timeB.getNomeDoTime() << ". ";
                cout << "Ambos possuem saldo de gols igual a " << saldoA << endl;
            } else if(saldoA == saldoC && saldoA != saldoB){
                cout << "Empate entre os times " << timeA.getNomeDoTime() << " e " << timeC.getNomeDoTime() << ". ";
                cout << "Ambos possuem saldo de gols igual a " << saldoA << endl;
            } else if(saldoB == saldoC && saldoB != saldoC){
                cout << "Empate entre os times " << timeB.getNomeDoTime() << " e " << timeC.getNomeDoTime() << ". ";
                cout << "Ambos possuem saldo de gols igual a " << saldoB << endl;
            } else{
                cout << "Empate entre os times " << timeA.getNomeDoTime() << ", " << timeB.getNomeDoTime() << " e " << timeC.getNomeDoTime() << ". ";
                cout << "Todos possuem saldo de gols igual a " << saldoB << endl;                   
            }

        }

RetornosMultiplos Liga::calcularMaiorEvolucao(vector<Time> times){
            double maiorEvolucaoFeitos = 0.0;
            double maiorEvolucaoSofridos = 0.0;
            string timeMaiorEvolucaoFeitos;
            string timeMaiorEvolucaoSofridos;
            
            for (auto& time : times) {
                retorno = calcularDesempenho(time);

                // Calculando a evolução dos gols feitos e gols sofridos
                double evolucaoFeitos = retorno.numeroFeitos;
                double evolucaoSofridos = retorno.numeroSofridos;

                // Se a evolução dos gols feitos for maior que a maior evolução atual
                if (evolucaoFeitos > maiorEvolucaoFeitos) {
                    maiorEvolucaoFeitos = evolucaoFeitos;
                    timeMaiorEvolucaoFeitos = time.getNomeDoTime();
                }

                // Se a evolução dos gols sofridos for maior que a maior evolução atual
                if (evolucaoSofridos > maiorEvolucaoSofridos) {
                    maiorEvolucaoSofridos = evolucaoSofridos;
                    timeMaiorEvolucaoSofridos = time.getNomeDoTime();
                }  
            }
            retorno.texto = timeMaiorEvolucaoFeitos;
            retorno.numeroFeitos = maiorEvolucaoFeitos;
            retorno.texto2 = timeMaiorEvolucaoSofridos;
            retorno.numeroSofridos = maiorEvolucaoSofridos;

            return retorno;
        }


