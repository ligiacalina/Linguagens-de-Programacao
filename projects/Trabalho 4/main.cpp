/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo principal
*  Aqui sao esta a implementacao da interface com o usuario para utilizacao do programa
*/

#include "sistema.hpp"

using namespace std;

int main() {
    Sistema sistema;

    //Construindo uma árvore base
    sistema.adicionarAtleta(new AtletaRobotica("Marcelo", "Mini Sumo Radiocontrolado", "Bites The Dust"));
    sistema.adicionarAtleta(new AtletaKarate("Nayibe", "preta"));
    sistema.adicionarAtleta(new AtletaKarate("Isabel", "roxa"));
    sistema.adicionarAtleta(new AtletaVolei("Isadora", "Levantador"));
    sistema.adicionarAtleta(new AtletaRobotica("Anne", "Mini Sumo Autonomo", "Ze Pequeno"));
    sistema.adicionarAtleta(new AtletaFutebol("Felipe", "Goleiro"));

    int opcao;
    while (opcao != 5) {
        cout << "---------------------------Menu--------------------------" << endl;
        cout << "1. Adicionar Atleta" << endl;
        cout << "2. Remover Atleta" << endl;
        cout << "3. Buscar Atleta" << endl;
        cout << "4. Imprimir Arvore" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cout << "---------------------------------------------------------" << endl;

        switch (opcao) {
            case 1: {
                string nomeAtleta,atributo1, atributo2;
                int esporte;
                cout << "Digite o nome do novo atleta: ";
                cin >> ws; //tira os espaços em branco
                getline(cin, nomeAtleta);
                cout << "1 - Futebol " << endl
                     << "2 - Karate " << endl
                     << "3 - Robotica " << endl
                     << "4 - Volei " << endl
                     << "5 - Atleta generico " << endl;
                cout << "Digite o indice referente ao esporte do atleta: ";
                cin >> esporte;
                Atleta* novoAtleta = nullptr;

                if (esporte == 1) {
                    cout << "Digite a posicao: ";
                    cin >> ws;
                    getline(cin, atributo1);
                    novoAtleta = new AtletaFutebol(nomeAtleta, atributo1);

                } else if (esporte == 2) {
                    cout << "Digite a cor da faixa: ";
                    cin >> ws;
                    getline(cin, atributo1);
                    novoAtleta = new AtletaKarate(nomeAtleta, atributo1);

                } else if (esporte == 3) {
                    cout << "Digite a categoria: ";
                    cin >> ws;
                    getline(cin, atributo1); // Captura a linha inteira para permitir espaços
                    cout << "Digite o nome do robo: ";
                    cin >> ws;
                    getline(cin, atributo2); // Captura a linha inteira para permitir espaços
                    novoAtleta = new AtletaRobotica(nomeAtleta, atributo1, atributo2);

                } else if (esporte == 4) {
                    cout << "Digite a posicao: ";
                    cin >> ws;
                    getline(cin, atributo1);
                    novoAtleta = new AtletaVolei(nomeAtleta, atributo1);

                } else if (esporte == 5){
                    novoAtleta = new Atleta(nomeAtleta);

                } else {
                    cout << endl << "Esporte invalido." << endl;
                    break;
                }

                sistema.adicionarAtleta(novoAtleta);
                cout << endl;
                sistema.imprimirArvore();
                break;
            }
            
            case 2: {
                string nomeAtleta;
                cout << "Digite o nome do atleta a ser removido: ";
                cin >> ws;
                getline(cin, nomeAtleta);
                sistema.removerAtleta(new Atleta(nomeAtleta));
                cout << endl;
                sistema.imprimirArvore();
                break;
            }

            case 3: {
                string nomeAtleta;
                cout << "Digite o nome do atleta a ser buscado: ";
                cin >> ws;
                getline(cin, nomeAtleta);
                sistema.buscarAtleta(nomeAtleta);
                break;
            }

            case 4:{
                cout << endl;
                sistema.imprimirArvore();
                break;
            }

            case 5:{
                cout << "Saindo do programa." << endl;
                break;
            }
            
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
