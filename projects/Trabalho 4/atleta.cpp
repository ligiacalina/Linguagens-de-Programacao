/* Ling. Prog. 24.1 - Ligia Calina Bueno Bonifacio - Exercicio Avaliado 4
*  Arquivo de cpp da classe atleta
*  Aqui sao implementados os metodos definidos para a classe atleta.
*/

#include "atleta.hpp"

string Atleta::getNomeAtleta(){return nome;}

void Atleta::imprimeDetalhes(string nomeDoAtleta){
    cout << "Nome: " << nomeDoAtleta;
}

ostream& operator<<(ostream& os, Atleta& atleta) {
    atleta.imprimeDetalhes(atleta.getNomeAtleta());
    return os;
}

void AtletaFutebol::imprimeDetalhes(string nomeDoAtleta){
    cout << "Nome: " << nomeDoAtleta << ", Esporte: Futebol" << ", Posicao: " << posicao;
}

void AtletaKarate::imprimeDetalhes(string nomeDoAtleta){
    cout << "Nome: " << nomeDoAtleta << ", Esporte: Karate" << ", Cor da faixa: " << faixa;
}

void AtletaRobotica::imprimeDetalhes(string nomeDoAtleta){
    cout << "Nome: " << nomeDoAtleta << ", Esporte: Robotica" << ", Categoria: " << categoria << ", Nome do robo: " << nomeDoRobo;
}

void AtletaVolei::imprimeDetalhes(string nomeDoAtleta){
    cout << "Nome: " << nomeDoAtleta << ", Esporte: Volei" << ", Posicao: " << posicao;
}