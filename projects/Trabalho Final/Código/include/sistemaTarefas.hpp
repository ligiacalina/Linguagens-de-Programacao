/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Final
*  Arquivo header contendo as assinaturas dos métodos e as variáveis da classe Sistema.
*/

#ifndef SISTEMATAREFAS_HPP
#define SISTEMATAREFAS_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm> 
#include <pybind11/embed.h> // Incluir suporte para embutir Python
#include "tarefa.hpp"

using namespace std;
namespace py = pybind11;

class SistemaTarefas{
    public:
        void carregarTarefas(string arquivo, string tipo);
        void listarTarefas();
        void adicionarTarefa();
        void removerTarefa(unsigned int indice);
        void concluirTarefa(unsigned int indice);
        void listarTarefasConcluidas();
        void analisarTarefa(unsigned int indice);
        void editarTarefa(unsigned int indice);
        void listarTarefasUrgentes();
        void exibirListaDeCompras();
        vector<string> chamarScriptPython(unsigned int indice);
        string juntarPalavrasChave(vector<string> vector, char delimitador);

    private:
        static bool compareTarefas(Tarefa tarefaA, Tarefa tarefaB);

        vector<Tarefa> tarefas;
        vector<Tarefa> tarefasConcluidas;

};

#endif // SISTEMATAREFAS_HPP