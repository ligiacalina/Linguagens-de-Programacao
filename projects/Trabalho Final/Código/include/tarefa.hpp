/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Final
*  Arquivo header contendo as assinaturas dos métodos e as variáveis da classe Tarefa.
*/

#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <iostream>
#include <string>

using namespace std;

class Tarefa{
    public:
        Tarefa (string acao, int indiceUrgencia, int indiceRecorrencia){
            setAcaoTarefa(acao);
            setUrgencia(indiceUrgencia);
            setRecorrencia(indiceRecorrencia);
        }

        void setAcaoTarefa(string acaoTarefa);
        void setUrgencia(int indiceUrgencia );
        void setRecorrencia(int indiceRecorrencia);

        string getAcao();
        string getUrgencia();
        string getRecorrencia();
        int getIndiceUrgencia(string urgencia);
        int getIndiceRecorrencia(string recorrencia);

    private:
        string acao;
        string urgencia;
        string recorrencia;
};

#endif // TAREFA_HPP