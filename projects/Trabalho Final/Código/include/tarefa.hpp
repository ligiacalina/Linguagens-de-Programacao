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
