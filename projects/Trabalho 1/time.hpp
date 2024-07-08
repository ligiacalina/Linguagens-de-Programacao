/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 1
*  Arquivo de cabecalho da classe Time
*  Aqui sao definidos os atributos e metodos da classe.
*/
#include <vector>
#include <string>

using namespace std;

class Time{

    public:

        //Construtor que inicializa o objeto time com o seu nome
        Time (string nome);

        //Vetor que guarda vetores (anos diferentes) que guardam os gols feitos ou sofridos em cada campeonato
        vector <vector<int>> golsFeitos; // gols feitos em cada campeonato por ano
        vector <vector<int>> golsSofridos; // gols sofridos em cada campeonato por ano

        void setNomeDoTime(string nome);
        string getNomeDoTime() const;

        // Função para calcular a média móvel dos gols
        double calcularMediaMovel(vector<vector<int>>& dados, int anosConsiderados);

        //Função para calcular média móvel de gols em um campeonato específico
        double calcularMediaMovelPorCampeonato(vector<vector<int>>& dados, int anosConsiderados, int indiceCampeonato);

        //Função para calcular a média móvel em um determinado ano
        double calcularMediaMovelPorAno(vector<vector<int>>& dados, int i);

        //Função para calcular média móvel de gols em um campeonato específico em um determinado ano
        double getGolsDeCampeonato(vector<vector<int>>& dados, int i, int indiceCampeonato);

        int calcularSaldoDeGols(vector<vector<int>>& dados, int indiceCampeonato);

    private:
        string nomeDoTime;

};