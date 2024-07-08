/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 3
*  Arquivo principal do exercicio 
*  Este e um arquivo de header para a classe historico, o qual possui todas as assinaturas dos metodos da classe, 
*  assim como as variaveis principais.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "disciplina.hpp"

class Historico{
    public:

        vector<Disciplina> getListaDisciplinas();
        int getNumMaxDisciplinas();

        //Construtor para garantir que o numero maximo de disciplinas seja setado
        Historico(int max) : maxDisciplinas(max){carregarDisciplinas();};

        //Destrutor para salvar as disciplinas no arquivo
        ~Historico(){salvarDisciplinas();};

        //Adiciona uma disciplina ao vector de disciplinas
        int adicionarDisciplina(Disciplina disc);

        //Remove uma disciplina do vector de disciplinas
        int removerDisciplina(Disciplina& disc);

        //Busca todas as disciplinas que sao concluidas em um determinado periodo e retorna um vector com todas elas
        vector<Disciplina> buscarDisciplinasPeloPeriodo(string periodo);

        //Retorna a nota de uma determinada disciplina a partir do seu nome
        double getNotaPeloNome(string nome);

        //Sobrecarga do operador << para Historico
        friend ostream& operator<<(ostream& os, Historico hist);

        //Sobrecarga do operador += para adicionar uma unica disciplina
        int operator+=(Disciplina disc);

        //Sobrecarga do operador += para adicionar um vector de disciplinas
        int operator+=(vector<Disciplina> novasDisciplinas);

        //Sobrecarga do operador -= para Historico
        int operator-=(Disciplina disc);

        //Sobrecarga do operador () para Historico
        vector<Disciplina> operator()(string periodo);

        //Sobrecarga do operador [] para Historico
        double& operator[](string& nome);

        // Sobrecarga do operador >> para calculo do CRA do Historico
        double& operator>>(double& cra);
        
    private:

        void carregarDisciplinas();

        void salvarDisciplinas();

        vector<Disciplina> disciplinas;
        unsigned int maxDisciplinas;
};