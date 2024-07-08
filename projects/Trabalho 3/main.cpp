/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 3
*  Arquivo principal do exercicio 
*  Este e o arquivo principal do programa, o qual possui toda logica principal, arquivos auxiliares,
*  alem do menu com interacao do usuario.
*/
#include "historico.hpp"
#include <limits> 

using namespace std;

int main(){

    Historico historico(10);//limite de 5 disciplinas
    Disciplina discAdicionar; //criando uma disciplina generica
    Disciplina discRemover;

    string periodo;
    string nome;
    vector<Disciplina> resultado;
    vector<Disciplina> novasDisciplinas;
    int indice;
    unsigned int numDisciplinas;
    double novaNota;
    double cra = 0.0;

    int opcao = -1;//inicializando a variavel com um valor qualquer
    while(opcao!=0){

        cout << "------------------------------------MENU------------------------------------" << endl
             << "1 - Adicionar disciplina" << endl
             << "2 - Remover disciplina" << endl
             << "3 - Buscar disciplinas por periodo" << endl
             << "4 - Editar a nota de uma disciplina" << endl
             << "5 - Calcular o CRA" << endl
             << "6 - Listar todas as disciplinas" << endl
             << "0 - Sair" << endl
             << "Digite o indice: ";
             cin >> opcao;

        switch(opcao){

            case 1:
                cout << "Digite o numero de disciplinas a serem adicionadas: ";
                cin >> numDisciplinas;

                if(numDisciplinas > (historico.getNumMaxDisciplinas() - historico.getListaDisciplinas().size())){
                    cout << "Nao ha espaco para adicionar essa quantidade de disciplinas. " << endl;
                    break;
                }

                //cout << "conta: " << historico.getListaDisciplinas().size() << endl;

                for (unsigned int i = 0; i < numDisciplinas; ++i) {
                    cin >> discAdicionar;
                    novasDisciplinas.push_back(discAdicionar);
                }

                indice = historico += novasDisciplinas;
                if (indice != -1) {
                    cout << "Disciplinas adicionadas a partir do indice: " << indice << endl;
                }

                break;

            case 2:
                cout << "Digite o nome da disciplina para remover: ";
                cin >> ws; //Ignora espacos em branco
                getline(cin, nome);
                //nome = discRemover.trim(nome);
                discRemover.nome = nome; // Inicializa o objeto Disciplina com o nome fornecido
                indice = (historico -= discRemover);
                cout << "Disciplina removida do indice: " << indice << endl;
                break;

            case 3:
                cout << "Digite o periodo para buscar: ";;
                cin >> periodo;
                resultado = historico(periodo);

                if(resultado.empty()){
                    cout << "Nenhuma disciplina encontrada para o periodo " << periodo << endl;
                }else{
                    cout << "Disciplinas do periodo " << periodo << ": " << endl;
                    for(Disciplina disc : resultado){
                        cout << disc << endl;
                    }
                }
                break;

            case 4:
                cout << "Digite o nome da disciplina que deseja editar a nota: ";
                cin >> ws;
                getline(cin, nome);
                cout << "Digite a nova nota: ";
                cin >> novaNota;

                historico[nome] = novaNota;
                
                break;

            case 5:
                historico >> cra;
                break;

            case 6:
                cout << historico;
                break;

            case 0:
                break;

            default:
                cout << "Opcao invalida." << endl;
                break;
        }
        // Limpa o buffer de entrada para evitar comportamento inesperado
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;

}