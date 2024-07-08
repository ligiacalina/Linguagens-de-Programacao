/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Final
*  Arquivo principal do exercicio 
*  Este e o arquivo principal do programa, o qual possui toda logica principal, arquivos auxiliares,
*  alem do menu com interacao do usuario.
*/

#include <iostream>
#include <vector>
#include "sistemaTarefas.hpp"

using namespace std;

int main(){
    SistemaTarefas sistema;
    sistema.carregarTarefas("tarefas.txt", "a fazer");
    sistema.carregarTarefas("tarefasConcluidas.txt", "concluidas");

    int opcao = 10;//Numero aleatorio para inicializacao da variavel;
    unsigned indice;
    vector<string> resultado;

    while(opcao!=0){

        cout << "--------------------------MENU--------------------------" << endl;
        cout << "1 - Adicionar tarefa" << endl
             << "2 - Listar tarefas por ordem de urgencia" << endl
             << "3 - Analisar tarefa" << endl
             << "4 - Remover tarefa" << endl
             << "5 - Concluir tarefa" << endl
             << "6 - Exibir tarefas concluidas" << endl
             << "7 - Editar tarefa" << endl
             << "8 - Exibir tarefas mais urgentes" << endl
             << "9 - Exibir Lista de compras" << endl
             << "0 - Sair" << endl;
        cout << "Escreva o indice referente a opcao desejada: ";
        cin >> opcao;
        cout << endl << "--------------------------------------------------------" << endl;

        switch(opcao){
            case 1:
                sistema.adicionarTarefa();
                break;

            case 2:
                sistema.listarTarefas();
                break;

            case 3:
                sistema.listarTarefas();
                cout << "Digite o indice referente a tarefa que deseja analisar: ";
                cin >> indice;
                sistema.analisarTarefa(indice);
                    break;

            case 4:
                sistema.listarTarefas();
                cout << "Digite o indice referente a tarefa que deseja remover: ";
                cin >> indice;
                sistema.removerTarefa(indice);
                break;

            case 5:
                sistema.listarTarefas();
                cout << "Digite o indice referente a tarefa que deseja concluir: ";
                cin >> indice;
                sistema.concluirTarefa(indice);
                break;

            case 6:
                sistema.listarTarefasConcluidas();
                break;

            case 7:
                sistema.listarTarefas();
                cout << "Digite o indice referente a tarefa que deseja editar: ";
                cin >> indice;
                sistema.editarTarefa(indice);
                break;

            case 8:
                sistema.listarTarefasUrgentes();
                break;

            case 9:
                sistema.exibirListaDeCompras();
                break;

            case 0:
                cout << "Saindo do programa..." << endl;
                return 0;

        }
    }
    return 0;
}