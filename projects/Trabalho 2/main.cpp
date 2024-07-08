/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 2
*  Arquivo principal do exercicio 
*  Este e o arquivo principal do programa, o qual possui toda logica principal, arquivos auxiliares,
*  alem do menu com interacao do usuario.
*/

#include "grafo.hpp"

int main() {
    Grafo grafo;

    RetornosMultiplos retorno = grafo.verticeMaiorCentralidade();
    vector<vector<string>> caminho;

    int opcao = 10; //inicializando com valor qualquer

    while(opcao != 0){

    cout << "------------------------------- Menu -------------------------------" << endl;
    cout << "1 - Grafo da rede de cidades." << endl;
    cout << "2 - Densidade do  grafo." << endl;
    cout << "3 - Imprimir a cidade com maior centralidade." << endl;
    cout << "4 - Imprimir menor caminho entre duas cidades." << endl;
    cout << "5 - Imprimir a cidade com maior centralidade de proximidade." << endl;
    cout << "0 - Sair." << endl;
    cout << "Selecione o indice correspondente a opcao que deseja visualizar: ";
    cin >> opcao;
    cout << endl << "--------------------------------------------------------------------" << endl;

        switch(opcao){

            case 0:
                break;

            case 1:
                grafo.imprimirGrafo();
                break;

            case 2:
                grafo.imprimirDensidade();
                break;

            case 3: 
                cout << "a cidade com maior centralidade e: " << retorno.cidade;
                cout << " e sua centralidade em km e: " << retorno.distancia <<"km." << endl;
                break;

            case 4:
                int indiceOrigem;
                int indiceDestino;
                grafo.imprimirCidades();
                cout << "Selecione o indice referente a origem: ";
                cin >> indiceOrigem;
                if(indiceOrigem<0 || indiceOrigem>7){
                    cout << "Opcao invalida. Por favor, digite um indice valido." << endl << endl;
                    break;
                }
                grafo.imprimirCidades();
                cout << "Selecione o indice referente ao destino: ";
                cin >> indiceDestino;
                if(indiceDestino<0 || indiceDestino>7){
                    cout << "Opcao invalida. Por favor, digite um indice valido." << endl << endl;
                    break;
                }

                grafo.imprimeMenorPercursoDuasCidades(indiceOrigem, indiceDestino);
                break;

            case 5:
                grafo.imprimirMaiorCentralidadeProximidade();
                break;

            default:
                cout << "Opcao invalida. Por favor, digite um indice valido." << endl << endl;

        }
    }

    return 0;
}
